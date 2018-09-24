#include <Rcpp.h>
using namespace Rcpp;
#include "pops/simulation.hpp"
#include "pops/raster.hpp"
#include <iostream>
#include <vector>
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


using namespace pops;

//Raster<int> total_plants;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]
List pops_model(int random_seed, double lethal_temperature,
                double reproductive_rate,
                bool weather,
                double short_distance_scale,
                double start_time, double end_time,
                double percent_short_distance_dispersal = 0.0,
                double long_distance_scale = 0.0
                )
  {
  Raster<int> infected = {{5, 0}, {0, 0}};
  Raster<int> mortality_tracker = {{0, 0}, {0, 0}};
  Raster<int> susceptible = {{10, 6}, {14, 15}};
  Raster<int> total_plants = {{15, 6}, {14, 15}};
  Raster<double> temperature = {{5, 0}, {0, 0}};
  Raster<double> weather_coefficient = {{0.8, 0.8}, {0.2, 0.8}};
  std::vector<std::tuple<int, int>> outside_dispersers;
  DispersalKernel dispersal_kernel = CAUCHY;
  
  Date dd_start(start_time, 01, 01);
  Date dd_end(end_time, 12, 31);
  string step = "month";
  Date dd_current(dd_start);

for (int current_week = 0; ; current_week++, step == "month" ? dd_current.increased_by_month() : dd_current.increased_by_week()) {
        if (dd_current < dd_end)
            if (season.month_in_season(dd_current.getMonth()))
}
  
  Simulation<Raster<int>, Raster<double>> simulation(random_seed, infected);
  simulation.remove(infected, susceptible,
                    temperature, lethal_temperature);
  simulation.generate(infected, weather, weather_coefficient, reproductive_rate);
  simulation.disperse(susceptible, infected,
                      mortality_tracker, total_plants,
                      outside_dispersers, weather, weather_coefficient, 
                      dispersal_kernel, short_distance_scale);
  // this is a test of vector of rasters
  std::vector<Raster<int>> v;
  v = {infected,susceptible};
   // this is a test of vector of rasters
   
  cout << infected;
  cout << outside_dispersers.size() << endl;
  for(Raster<int> n : v) {
    cout << n;  // this is a test of vector of rasters
  }
  
  return 0;
}


