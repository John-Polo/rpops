#include <Rcpp.h>
#include "simulation.hpp"
#include "raster.hpp"
#include "date.hpp"
#include "treatments.hpp"
#include "kernel.hpp"
#include "kernel_types.hpp"
#include "radial_kernel.hpp"
#include "short_long_kernel.hpp"
#include "spread_rate.hpp"
#include "statistics.hpp"
#include "switch_kernel.hpp"
#include "uniform_kernel.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

using namespace Rcpp;
using namespace pops;

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

bool all_infected(IntegerMatrix susceptible)
{
  bool allInfected = true;
  for (int j = 0; j < susceptible.rows(); j++) {
    for (int k = 0; k < susceptible.cols(); k++) {
      if (susceptible(j, k) > 0)
        allInfected = false;
    }
  }
  return allInfected;
}

TreatmentApplication treatment_application_enum_from_string(const std::string& text)
{
  if (text == "ratio")
    return TreatmentApplication::Ratio;
  else if (text == "all infected")
    return TreatmentApplication::AllInfectedInCell;
  else
    throw std::invalid_argument("treatment_application_enum_from_string: Invalid"
                                  " value '" + text +"' provided");
}


template<int... Indices>
struct indices {
  using next = indices<Indices..., sizeof...(Indices)>;
};

template<int Size>
struct build_indices {
  using type = typename build_indices<Size - 1>::type::next;
};

template<>
struct build_indices<0> {
  using type = indices<>;
};

template<typename T>
using Bare = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

template<typename Tuple>
constexpr
  typename build_indices<std::tuple_size<Bare<Tuple>>::value>::type
  make_indices()
  { return {}; }

template<typename Tuple, int... Indices>
std::array<
  typename std::tuple_element<0, Bare<Tuple>>::type,
  std::tuple_size<Bare<Tuple>>::value
>
to_array(Tuple&& tuple, indices<Indices...>)
{
  using std::get;
  return {{ get<Indices>(std::forward<Tuple>(tuple))... }};
}

template<typename Tuple>
auto to_array(Tuple&& tuple)
  -> decltype( to_array(std::declval<Tuple>(), make_indices<Tuple>()) )
  {
    return to_array(std::forward<Tuple>(tuple), make_indices<Tuple>());
  }

// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]
List pops_model(int random_seed, 
                bool use_lethal_temperature, double lethal_temperature, int lethal_temperature_month,
                IntegerMatrix infected,
                IntegerMatrix susceptible,
                IntegerMatrix total_plants,
                bool mortality_on,
                IntegerMatrix mortality_tracker,
                IntegerMatrix mortality,
                std::vector<NumericMatrix> treatment_maps,
                std::vector<std::string> treatment_dates,
                std::vector<int> pesticide_duration,
                IntegerMatrix resistant,
                bool weather,
                std::vector<NumericMatrix> temperature,
                std::vector<NumericMatrix> weather_coefficient,
                double ew_res, double ns_res, int num_rows, int num_cols,
                std::string time_step, double reproductive_rate,
                double mortality_rate = 0.0, int mortality_time_lag = 2,
                int season_month_start = 1, int season_month_end = 12,
                double start_time = 2018, double end_time = 2018,
                std::string treatment_method = "ratio",
                std::string natural_kernel_type = "cauchy", std::string anthropogenic_kernel_type = "cauchy", 
                bool use_anthropogenic_kernel = false, double percent_natural_dispersal = 0.0,
                double natural_distance_scale = 21, double anthropogenic_distance_scale = 0.0, 
                std::string natural_dir = "NONE", double natural_kappa = 0,
                std::string anthropogenic_dir = "NONE", double anthropogenic_kappa = 0
)
{
  
  std::vector<std::tuple<int, int>> outside_dispersers;
  DispersalKernelType natural_dispersal_kernel_type = kernel_type_from_string(natural_kernel_type);
  DispersalKernelType anthropogenic_dispersal_kernel_type = kernel_type_from_string(anthropogenic_kernel_type);
  TreatmentApplication treatment_application = treatment_application_enum_from_string(treatment_method);
  pops::Date dd_start(start_time, 01, 01);
  pops::Date dd_end(end_time, 12, 31);
  Direction natural_direction = direction_from_string(natural_dir);
  Direction anthropogenic_direction = direction_from_string(anthropogenic_dir);
  Season season(season_month_start,season_month_end);
  pops::Date dd_current(dd_start);
  Simulation<IntegerMatrix, NumericMatrix> simulation(random_seed, infected);
  RadialDispersalKernel natural_radial_dispersal_kernel(ew_res, ns_res, natural_dispersal_kernel_type, natural_distance_scale, natural_direction, natural_kappa);
  RadialDispersalKernel anthropogenic_radial_dispersal_kernel(ew_res, ns_res, anthropogenic_dispersal_kernel_type, anthropogenic_distance_scale, anthropogenic_direction, anthropogenic_kappa);
  UniformDispersalKernel uniform_kernel(num_rows, num_cols);
  SwitchDispersalKernel natural_dispersal_kernel(natural_dispersal_kernel_type, natural_radial_dispersal_kernel, uniform_kernel);
  SwitchDispersalKernel anthropogenic_dispersal_kernel(anthropogenic_dispersal_kernel_type, anthropogenic_radial_dispersal_kernel, uniform_kernel);
  DispersalKernel kernel(natural_dispersal_kernel, anthropogenic_dispersal_kernel, use_anthropogenic_kernel, percent_natural_dispersal);
  std::vector<std::array<double,4>> spread_rates_vector;
  std::tuple<double,double,double,double> spread_rates;
  std::function<void (pops::Date&)> increase_by_step = &pops::Date::increased_by_week;
  
  if (time_step == "month") {
    std::function<void (pops::Date&)> increase_by_step = &pops::Date::increased_by_month;
  } else if (time_step == "week") {
    std::function<void (pops::Date&)> increase_by_step = &pops::Date::increased_by_week;
  } 
    
  // if (time_step == "day") {
  //   std::function<void (pops::Date&)> increase_by_step = &pops::Date::increased_by_days;
  // }
  
  int num_infected;
  std::vector<int> number_infected;
  double area_infect;
  std::vector<double> area_infected;
  
  int counter = 0;
  int first_mortality_year = start_time + mortality_time_lag;
  
  std::vector<IntegerMatrix> infected_vector;
  std::vector<IntegerMatrix> susceptible_vector;
  std::vector<IntegerMatrix> mortality_tracker_vector;
  std::vector<IntegerMatrix> mortality_vector;
  std::vector<IntegerMatrix> resistant_vector;
  std::vector<int> simulated_weeks;
  int current_year;
  
  Treatments<IntegerMatrix, NumericMatrix> treatments;
  for (unsigned t = 0; t < treatment_maps.size(); t++) {
    treatments.add_treatment(treatment_maps[t], treatment_dates[t], pesticide_duration[t], treatment_application, increase_by_step);
  }
  
  unsigned num_years = dd_end.year() - dd_start.year() + 1;
  
  SpreadRate<IntegerMatrix> spreadrate(infected, ew_res, ns_res, num_years);
  
  for (unsigned current_time_step = 0; ; current_time_step++, time_step == "month" ? dd_current.increased_by_month() : dd_current.increased_by_week()) {
      
      if (dd_current.year() > dd_end.year()) {
        break;
      }
      
      if (all_infected(susceptible)) {
        Rcerr << "At timestep " << dd_current << " all suspectible hosts are infected!" << std::endl;
        infected_vector.push_back(Rcpp::clone(infected));
        susceptible_vector.push_back(Rcpp::clone(susceptible));
        resistant_vector.push_back(Rcpp::clone(resistant));
        break;
      }
    
      if (use_lethal_temperature && dd_current.month() == lethal_temperature_month && dd_current.year() <= dd_end.year()) {
        unsigned simulation_year = dd_current.year() - dd_start.year();
        if (simulation_year >= temperature.size()){
          Rcerr << "Not enough years of temperature data" << std::endl;
        }
        simulation.remove(infected, susceptible, temperature[simulation_year], lethal_temperature);
      }
      
      treatments.manage(dd_current, infected, susceptible, resistant);
      if (mortality_on) {
        for (unsigned l = 0; l < mortality_tracker_vector.size(); l++) {
          treatments.manage_mortality(dd_current, mortality_tracker_vector[l]);
        }
      }
      
      if (season.month_in_season(dd_current.month())) {
        counter += 1;
        simulated_weeks.push_back(current_time_step);
        
        if (current_time_step >= weather_coefficient.size()  && weather == TRUE) {
          Rcerr << "Not enough time steps of weather coefficient data" << std::endl;
        }

        simulation.generate(infected, weather, weather_coefficient[current_time_step], reproductive_rate);
        simulation.disperse(susceptible, infected,
                            mortality_tracker, total_plants,
                            outside_dispersers, 
                            weather, weather_coefficient[current_time_step], 
                            kernel);
      
      }
    
      if ((time_step == "month" ? dd_current.is_last_month_of_year() : dd_current.is_last_week_of_year())) {
        
        mortality_tracker_vector.push_back(Rcpp::clone(mortality_tracker));
        std::fill(mortality_tracker.begin(), mortality_tracker.end(), 0);
        if (mortality_on == TRUE) {
          int current_year = dd_current.year();
          simulation.mortality(infected, mortality_rate, current_year, first_mortality_year, mortality, mortality_tracker_vector);
          mortality_vector.push_back(Rcpp::clone(mortality));
        }
        
        infected_vector.push_back(Rcpp::clone(infected));
        susceptible_vector.push_back(Rcpp::clone(susceptible));
        resistant_vector.push_back(Rcpp::clone(resistant));
        
        num_infected = sum_of_infected(infected);
        number_infected.push_back(num_infected);
        area_infect = area_of_infected(infected, ew_res, ns_res);
        area_infected.push_back(area_infect);
        
        unsigned simulation_year = dd_current.year() - dd_start.year();
        spreadrate.compute_yearly_spread_rate(infected, simulation_year);
        spread_rates = spreadrate.yearly_rate(simulation_year);
        auto sr = to_array(spread_rates);
        spread_rates_vector.push_back(sr);
      }
    
      if (dd_current >= dd_end) {
        break;
      }
  
  }

  return List::create(
    _["infected"] = infected_vector,
    _["susceptible"] = susceptible_vector,
    _["resistant"] = resistant_vector,
    _["mortality"] = mortality_vector,
    _["rates"] = spread_rates_vector,
    _["number_infected"] = number_infected,
    _["area_infected"] = area_infected
  );
  
}
