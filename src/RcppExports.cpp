// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/PoPS.h"
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// pops_model_cpp
List pops_model_cpp(int random_seed, bool use_lethal_temperature, double lethal_temperature, int lethal_temperature_month, IntegerMatrix infected, IntegerMatrix total_exposed, std::vector<IntegerMatrix> exposed, IntegerMatrix susceptible, IntegerMatrix total_populations, IntegerMatrix total_hosts, bool mortality_on, std::vector<IntegerMatrix> mortality_tracker, IntegerMatrix mortality, IntegerMatrix quarantine_areas, std::vector<NumericMatrix> treatment_maps, std::vector<std::string> treatment_dates, std::vector<int> pesticide_duration, IntegerMatrix resistant, bool use_movements, std::vector<std::vector<int>> movements, std::vector<std::string> movements_dates, bool weather, std::vector<NumericMatrix> temperature, std::vector<NumericMatrix> weather_coefficient, List res, List rows_cols, std::string time_step, double reproductive_rate, std::vector<std::vector<int>> spatial_indices, List season_month_start_end, double mortality_rate, int mortality_time_lag, std::string start_date, std::string end_date, std::string treatment_method, std::string natural_kernel_type, std::string anthropogenic_kernel_type, bool use_anthropogenic_kernel, double percent_natural_dispersal, double natural_distance_scale, double anthropogenic_distance_scale, std::string natural_dir, double natural_kappa, std::string anthropogenic_dir, double anthropogenic_kappa, std::string output_frequency, int output_frequency_n, std::string quarantine_frequency, int quarantine_frequency_n, bool use_quarantine, std::string spreadrate_frequency, int spreadrate_frequency_n, std::string mortality_frequency, int mortality_frequency_n, bool use_spreadrates, std::string model_type_, int latency_period, bool generate_stochasticity, bool establishment_stochasticity, bool movement_stochasticity, bool deterministic, double establishment_probability, double dispersal_percentage, bool use_overpopulation_movements, Nullable<List> overpopulation_config);
static SEXP _PoPS_pops_model_cpp_try(SEXP random_seedSEXP, SEXP use_lethal_temperatureSEXP, SEXP lethal_temperatureSEXP, SEXP lethal_temperature_monthSEXP, SEXP infectedSEXP, SEXP total_exposedSEXP, SEXP exposedSEXP, SEXP susceptibleSEXP, SEXP total_populationsSEXP, SEXP total_hostsSEXP, SEXP mortality_onSEXP, SEXP mortality_trackerSEXP, SEXP mortalitySEXP, SEXP quarantine_areasSEXP, SEXP treatment_mapsSEXP, SEXP treatment_datesSEXP, SEXP pesticide_durationSEXP, SEXP resistantSEXP, SEXP use_movementsSEXP, SEXP movementsSEXP, SEXP movements_datesSEXP, SEXP weatherSEXP, SEXP temperatureSEXP, SEXP weather_coefficientSEXP, SEXP resSEXP, SEXP rows_colsSEXP, SEXP time_stepSEXP, SEXP reproductive_rateSEXP, SEXP spatial_indicesSEXP, SEXP season_month_start_endSEXP, SEXP mortality_rateSEXP, SEXP mortality_time_lagSEXP, SEXP start_dateSEXP, SEXP end_dateSEXP, SEXP treatment_methodSEXP, SEXP natural_kernel_typeSEXP, SEXP anthropogenic_kernel_typeSEXP, SEXP use_anthropogenic_kernelSEXP, SEXP percent_natural_dispersalSEXP, SEXP natural_distance_scaleSEXP, SEXP anthropogenic_distance_scaleSEXP, SEXP natural_dirSEXP, SEXP natural_kappaSEXP, SEXP anthropogenic_dirSEXP, SEXP anthropogenic_kappaSEXP, SEXP output_frequencySEXP, SEXP output_frequency_nSEXP, SEXP quarantine_frequencySEXP, SEXP quarantine_frequency_nSEXP, SEXP use_quarantineSEXP, SEXP spreadrate_frequencySEXP, SEXP spreadrate_frequency_nSEXP, SEXP mortality_frequencySEXP, SEXP mortality_frequency_nSEXP, SEXP use_spreadratesSEXP, SEXP model_type_SEXP, SEXP latency_periodSEXP, SEXP generate_stochasticitySEXP, SEXP establishment_stochasticitySEXP, SEXP movement_stochasticitySEXP, SEXP deterministicSEXP, SEXP establishment_probabilitySEXP, SEXP dispersal_percentageSEXP, SEXP use_overpopulation_movementsSEXP, SEXP overpopulation_configSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< int >::type random_seed(random_seedSEXP);
    Rcpp::traits::input_parameter< bool >::type use_lethal_temperature(use_lethal_temperatureSEXP);
    Rcpp::traits::input_parameter< double >::type lethal_temperature(lethal_temperatureSEXP);
    Rcpp::traits::input_parameter< int >::type lethal_temperature_month(lethal_temperature_monthSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type infected(infectedSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type total_exposed(total_exposedSEXP);
    Rcpp::traits::input_parameter< std::vector<IntegerMatrix> >::type exposed(exposedSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type susceptible(susceptibleSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type total_populations(total_populationsSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type total_hosts(total_hostsSEXP);
    Rcpp::traits::input_parameter< bool >::type mortality_on(mortality_onSEXP);
    Rcpp::traits::input_parameter< std::vector<IntegerMatrix> >::type mortality_tracker(mortality_trackerSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type mortality(mortalitySEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type quarantine_areas(quarantine_areasSEXP);
    Rcpp::traits::input_parameter< std::vector<NumericMatrix> >::type treatment_maps(treatment_mapsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type treatment_dates(treatment_datesSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type pesticide_duration(pesticide_durationSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type resistant(resistantSEXP);
    Rcpp::traits::input_parameter< bool >::type use_movements(use_movementsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::vector<int>> >::type movements(movementsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type movements_dates(movements_datesSEXP);
    Rcpp::traits::input_parameter< bool >::type weather(weatherSEXP);
    Rcpp::traits::input_parameter< std::vector<NumericMatrix> >::type temperature(temperatureSEXP);
    Rcpp::traits::input_parameter< std::vector<NumericMatrix> >::type weather_coefficient(weather_coefficientSEXP);
    Rcpp::traits::input_parameter< List >::type res(resSEXP);
    Rcpp::traits::input_parameter< List >::type rows_cols(rows_colsSEXP);
    Rcpp::traits::input_parameter< std::string >::type time_step(time_stepSEXP);
    Rcpp::traits::input_parameter< double >::type reproductive_rate(reproductive_rateSEXP);
    Rcpp::traits::input_parameter< std::vector<std::vector<int>> >::type spatial_indices(spatial_indicesSEXP);
    Rcpp::traits::input_parameter< List >::type season_month_start_end(season_month_start_endSEXP);
    Rcpp::traits::input_parameter< double >::type mortality_rate(mortality_rateSEXP);
    Rcpp::traits::input_parameter< int >::type mortality_time_lag(mortality_time_lagSEXP);
    Rcpp::traits::input_parameter< std::string >::type start_date(start_dateSEXP);
    Rcpp::traits::input_parameter< std::string >::type end_date(end_dateSEXP);
    Rcpp::traits::input_parameter< std::string >::type treatment_method(treatment_methodSEXP);
    Rcpp::traits::input_parameter< std::string >::type natural_kernel_type(natural_kernel_typeSEXP);
    Rcpp::traits::input_parameter< std::string >::type anthropogenic_kernel_type(anthropogenic_kernel_typeSEXP);
    Rcpp::traits::input_parameter< bool >::type use_anthropogenic_kernel(use_anthropogenic_kernelSEXP);
    Rcpp::traits::input_parameter< double >::type percent_natural_dispersal(percent_natural_dispersalSEXP);
    Rcpp::traits::input_parameter< double >::type natural_distance_scale(natural_distance_scaleSEXP);
    Rcpp::traits::input_parameter< double >::type anthropogenic_distance_scale(anthropogenic_distance_scaleSEXP);
    Rcpp::traits::input_parameter< std::string >::type natural_dir(natural_dirSEXP);
    Rcpp::traits::input_parameter< double >::type natural_kappa(natural_kappaSEXP);
    Rcpp::traits::input_parameter< std::string >::type anthropogenic_dir(anthropogenic_dirSEXP);
    Rcpp::traits::input_parameter< double >::type anthropogenic_kappa(anthropogenic_kappaSEXP);
    Rcpp::traits::input_parameter< std::string >::type output_frequency(output_frequencySEXP);
    Rcpp::traits::input_parameter< int >::type output_frequency_n(output_frequency_nSEXP);
    Rcpp::traits::input_parameter< std::string >::type quarantine_frequency(quarantine_frequencySEXP);
    Rcpp::traits::input_parameter< int >::type quarantine_frequency_n(quarantine_frequency_nSEXP);
    Rcpp::traits::input_parameter< bool >::type use_quarantine(use_quarantineSEXP);
    Rcpp::traits::input_parameter< std::string >::type spreadrate_frequency(spreadrate_frequencySEXP);
    Rcpp::traits::input_parameter< int >::type spreadrate_frequency_n(spreadrate_frequency_nSEXP);
    Rcpp::traits::input_parameter< std::string >::type mortality_frequency(mortality_frequencySEXP);
    Rcpp::traits::input_parameter< int >::type mortality_frequency_n(mortality_frequency_nSEXP);
    Rcpp::traits::input_parameter< bool >::type use_spreadrates(use_spreadratesSEXP);
    Rcpp::traits::input_parameter< std::string >::type model_type_(model_type_SEXP);
    Rcpp::traits::input_parameter< int >::type latency_period(latency_periodSEXP);
    Rcpp::traits::input_parameter< bool >::type generate_stochasticity(generate_stochasticitySEXP);
    Rcpp::traits::input_parameter< bool >::type establishment_stochasticity(establishment_stochasticitySEXP);
    Rcpp::traits::input_parameter< bool >::type movement_stochasticity(movement_stochasticitySEXP);
    Rcpp::traits::input_parameter< bool >::type deterministic(deterministicSEXP);
    Rcpp::traits::input_parameter< double >::type establishment_probability(establishment_probabilitySEXP);
    Rcpp::traits::input_parameter< double >::type dispersal_percentage(dispersal_percentageSEXP);
    Rcpp::traits::input_parameter< bool >::type use_overpopulation_movements(use_overpopulation_movementsSEXP);
    Rcpp::traits::input_parameter< Nullable<List> >::type overpopulation_config(overpopulation_configSEXP);
    rcpp_result_gen = Rcpp::wrap(pops_model_cpp(random_seed, use_lethal_temperature, lethal_temperature, lethal_temperature_month, infected, total_exposed, exposed, susceptible, total_populations, total_hosts, mortality_on, mortality_tracker, mortality, quarantine_areas, treatment_maps, treatment_dates, pesticide_duration, resistant, use_movements, movements, movements_dates, weather, temperature, weather_coefficient, res, rows_cols, time_step, reproductive_rate, spatial_indices, season_month_start_end, mortality_rate, mortality_time_lag, start_date, end_date, treatment_method, natural_kernel_type, anthropogenic_kernel_type, use_anthropogenic_kernel, percent_natural_dispersal, natural_distance_scale, anthropogenic_distance_scale, natural_dir, natural_kappa, anthropogenic_dir, anthropogenic_kappa, output_frequency, output_frequency_n, quarantine_frequency, quarantine_frequency_n, use_quarantine, spreadrate_frequency, spreadrate_frequency_n, mortality_frequency, mortality_frequency_n, use_spreadrates, model_type_, latency_period, generate_stochasticity, establishment_stochasticity, movement_stochasticity, deterministic, establishment_probability, dispersal_percentage, use_overpopulation_movements, overpopulation_config));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _PoPS_pops_model_cpp(SEXP random_seedSEXP, SEXP use_lethal_temperatureSEXP, SEXP lethal_temperatureSEXP, SEXP lethal_temperature_monthSEXP, SEXP infectedSEXP, SEXP total_exposedSEXP, SEXP exposedSEXP, SEXP susceptibleSEXP, SEXP total_populationsSEXP, SEXP total_hostsSEXP, SEXP mortality_onSEXP, SEXP mortality_trackerSEXP, SEXP mortalitySEXP, SEXP quarantine_areasSEXP, SEXP treatment_mapsSEXP, SEXP treatment_datesSEXP, SEXP pesticide_durationSEXP, SEXP resistantSEXP, SEXP use_movementsSEXP, SEXP movementsSEXP, SEXP movements_datesSEXP, SEXP weatherSEXP, SEXP temperatureSEXP, SEXP weather_coefficientSEXP, SEXP resSEXP, SEXP rows_colsSEXP, SEXP time_stepSEXP, SEXP reproductive_rateSEXP, SEXP spatial_indicesSEXP, SEXP season_month_start_endSEXP, SEXP mortality_rateSEXP, SEXP mortality_time_lagSEXP, SEXP start_dateSEXP, SEXP end_dateSEXP, SEXP treatment_methodSEXP, SEXP natural_kernel_typeSEXP, SEXP anthropogenic_kernel_typeSEXP, SEXP use_anthropogenic_kernelSEXP, SEXP percent_natural_dispersalSEXP, SEXP natural_distance_scaleSEXP, SEXP anthropogenic_distance_scaleSEXP, SEXP natural_dirSEXP, SEXP natural_kappaSEXP, SEXP anthropogenic_dirSEXP, SEXP anthropogenic_kappaSEXP, SEXP output_frequencySEXP, SEXP output_frequency_nSEXP, SEXP quarantine_frequencySEXP, SEXP quarantine_frequency_nSEXP, SEXP use_quarantineSEXP, SEXP spreadrate_frequencySEXP, SEXP spreadrate_frequency_nSEXP, SEXP mortality_frequencySEXP, SEXP mortality_frequency_nSEXP, SEXP use_spreadratesSEXP, SEXP model_type_SEXP, SEXP latency_periodSEXP, SEXP generate_stochasticitySEXP, SEXP establishment_stochasticitySEXP, SEXP movement_stochasticitySEXP, SEXP deterministicSEXP, SEXP establishment_probabilitySEXP, SEXP dispersal_percentageSEXP, SEXP use_overpopulation_movementsSEXP, SEXP overpopulation_configSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_PoPS_pops_model_cpp_try(random_seedSEXP, use_lethal_temperatureSEXP, lethal_temperatureSEXP, lethal_temperature_monthSEXP, infectedSEXP, total_exposedSEXP, exposedSEXP, susceptibleSEXP, total_populationsSEXP, total_hostsSEXP, mortality_onSEXP, mortality_trackerSEXP, mortalitySEXP, quarantine_areasSEXP, treatment_mapsSEXP, treatment_datesSEXP, pesticide_durationSEXP, resistantSEXP, use_movementsSEXP, movementsSEXP, movements_datesSEXP, weatherSEXP, temperatureSEXP, weather_coefficientSEXP, resSEXP, rows_colsSEXP, time_stepSEXP, reproductive_rateSEXP, spatial_indicesSEXP, season_month_start_endSEXP, mortality_rateSEXP, mortality_time_lagSEXP, start_dateSEXP, end_dateSEXP, treatment_methodSEXP, natural_kernel_typeSEXP, anthropogenic_kernel_typeSEXP, use_anthropogenic_kernelSEXP, percent_natural_dispersalSEXP, natural_distance_scaleSEXP, anthropogenic_distance_scaleSEXP, natural_dirSEXP, natural_kappaSEXP, anthropogenic_dirSEXP, anthropogenic_kappaSEXP, output_frequencySEXP, output_frequency_nSEXP, quarantine_frequencySEXP, quarantine_frequency_nSEXP, use_quarantineSEXP, spreadrate_frequencySEXP, spreadrate_frequency_nSEXP, mortality_frequencySEXP, mortality_frequency_nSEXP, use_spreadratesSEXP, model_type_SEXP, latency_periodSEXP, generate_stochasticitySEXP, establishment_stochasticitySEXP, movement_stochasticitySEXP, deterministicSEXP, establishment_probabilitySEXP, dispersal_percentageSEXP, use_overpopulation_movementsSEXP, overpopulation_configSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}

// validate (ensure exported C++ functions exist before calling them)
static int _PoPS_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("List(*pops_model_cpp)(int,bool,double,int,IntegerMatrix,IntegerMatrix,std::vector<IntegerMatrix>,IntegerMatrix,IntegerMatrix,IntegerMatrix,bool,std::vector<IntegerMatrix>,IntegerMatrix,IntegerMatrix,std::vector<NumericMatrix>,std::vector<std::string>,std::vector<int>,IntegerMatrix,bool,std::vector<std::vector<int>>,std::vector<std::string>,bool,std::vector<NumericMatrix>,std::vector<NumericMatrix>,List,List,std::string,double,std::vector<std::vector<int>>,List,double,int,std::string,std::string,std::string,std::string,std::string,bool,double,double,double,std::string,double,std::string,double,std::string,int,std::string,int,bool,std::string,int,std::string,int,bool,std::string,int,bool,bool,bool,bool,double,double,bool,Nullable<List>)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _PoPS_RcppExport_registerCCallable() { 
    R_RegisterCCallable("PoPS", "_PoPS_pops_model_cpp", (DL_FUNC)_PoPS_pops_model_cpp_try);
    R_RegisterCCallable("PoPS", "_PoPS_RcppExport_validate", (DL_FUNC)_PoPS_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_PoPS_pops_model_cpp", (DL_FUNC) &_PoPS_pops_model_cpp, 65},
    {"_PoPS_RcppExport_registerCCallable", (DL_FUNC) &_PoPS_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_PoPS(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
