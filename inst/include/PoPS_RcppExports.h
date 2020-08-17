// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_PoPS_RCPPEXPORTS_H_GEN_
#define RCPP_PoPS_RCPPEXPORTS_H_GEN_

#include <Rcpp.h>

namespace PoPS {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("PoPS", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("PoPS", "_PoPS_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in PoPS");
            }
        }
    }

    inline List pops_model(int random_seed, bool use_lethal_temperature, double lethal_temperature, int lethal_temperature_month, IntegerMatrix infected, std::vector<IntegerMatrix> exposed, IntegerMatrix susceptible, IntegerMatrix total_plants, bool mortality_on, IntegerMatrix mortality_tracker, IntegerMatrix mortality, std::vector<NumericMatrix> treatment_maps, std::vector<std::string> treatment_dates, std::vector<int> pesticide_duration, IntegerMatrix resistant, bool use_movements, std::vector<std::vector<int>> movements, std::vector<std::string> movements_dates, bool weather, std::vector<NumericMatrix> temperature, std::vector<NumericMatrix> weather_coefficient, double ew_res, double ns_res, int num_rows, int num_cols, std::string time_step, double reproductive_rate, double mortality_rate = 0.0, int mortality_time_lag = 2, int season_month_start = 1, int season_month_end = 12, std::string start_date = "2018-01-01", std::string end_date = "2018-12-31", std::string treatment_method = "ratio", std::string natural_kernel_type = "cauchy", std::string anthropogenic_kernel_type = "cauchy", bool use_anthropogenic_kernel = false, double percent_natural_dispersal = 0.0, double natural_distance_scale = 21, double anthropogenic_distance_scale = 0.0, std::string natural_dir = "NONE", double natural_kappa = 0, std::string anthropogenic_dir = "NONE", double anthropogenic_kappa = 0, std::string output_frequency = "year", std::string model_type_ = "SI", int latency_period = 0, bool generate_stochasticity = true, bool establishment_stochasticity = true, bool movement_stochasticity = true, bool deterministic = false, double establishment_probability = 0, double dispersal_percentage = 0.99) {
        typedef SEXP(*Ptr_pops_model)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_pops_model p_pops_model = NULL;
        if (p_pops_model == NULL) {
            validateSignature("List(*pops_model)(int,bool,double,int,IntegerMatrix,std::vector<IntegerMatrix>,IntegerMatrix,IntegerMatrix,bool,IntegerMatrix,IntegerMatrix,std::vector<NumericMatrix>,std::vector<std::string>,std::vector<int>,IntegerMatrix,bool,std::vector<std::vector<int>>,std::vector<std::string>,bool,std::vector<NumericMatrix>,std::vector<NumericMatrix>,double,double,int,int,std::string,double,double,int,int,int,std::string,std::string,std::string,std::string,std::string,bool,double,double,double,std::string,double,std::string,double,std::string,std::string,int,bool,bool,bool,bool,double,double)");
            p_pops_model = (Ptr_pops_model)R_GetCCallable("PoPS", "_PoPS_pops_model");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_pops_model(Shield<SEXP>(Rcpp::wrap(random_seed)), Shield<SEXP>(Rcpp::wrap(use_lethal_temperature)), Shield<SEXP>(Rcpp::wrap(lethal_temperature)), Shield<SEXP>(Rcpp::wrap(lethal_temperature_month)), Shield<SEXP>(Rcpp::wrap(infected)), Shield<SEXP>(Rcpp::wrap(exposed)), Shield<SEXP>(Rcpp::wrap(susceptible)), Shield<SEXP>(Rcpp::wrap(total_plants)), Shield<SEXP>(Rcpp::wrap(mortality_on)), Shield<SEXP>(Rcpp::wrap(mortality_tracker)), Shield<SEXP>(Rcpp::wrap(mortality)), Shield<SEXP>(Rcpp::wrap(treatment_maps)), Shield<SEXP>(Rcpp::wrap(treatment_dates)), Shield<SEXP>(Rcpp::wrap(pesticide_duration)), Shield<SEXP>(Rcpp::wrap(resistant)), Shield<SEXP>(Rcpp::wrap(use_movements)), Shield<SEXP>(Rcpp::wrap(movements)), Shield<SEXP>(Rcpp::wrap(movements_dates)), Shield<SEXP>(Rcpp::wrap(weather)), Shield<SEXP>(Rcpp::wrap(temperature)), Shield<SEXP>(Rcpp::wrap(weather_coefficient)), Shield<SEXP>(Rcpp::wrap(ew_res)), Shield<SEXP>(Rcpp::wrap(ns_res)), Shield<SEXP>(Rcpp::wrap(num_rows)), Shield<SEXP>(Rcpp::wrap(num_cols)), Shield<SEXP>(Rcpp::wrap(time_step)), Shield<SEXP>(Rcpp::wrap(reproductive_rate)), Shield<SEXP>(Rcpp::wrap(mortality_rate)), Shield<SEXP>(Rcpp::wrap(mortality_time_lag)), Shield<SEXP>(Rcpp::wrap(season_month_start)), Shield<SEXP>(Rcpp::wrap(season_month_end)), Shield<SEXP>(Rcpp::wrap(start_date)), Shield<SEXP>(Rcpp::wrap(end_date)), Shield<SEXP>(Rcpp::wrap(treatment_method)), Shield<SEXP>(Rcpp::wrap(natural_kernel_type)), Shield<SEXP>(Rcpp::wrap(anthropogenic_kernel_type)), Shield<SEXP>(Rcpp::wrap(use_anthropogenic_kernel)), Shield<SEXP>(Rcpp::wrap(percent_natural_dispersal)), Shield<SEXP>(Rcpp::wrap(natural_distance_scale)), Shield<SEXP>(Rcpp::wrap(anthropogenic_distance_scale)), Shield<SEXP>(Rcpp::wrap(natural_dir)), Shield<SEXP>(Rcpp::wrap(natural_kappa)), Shield<SEXP>(Rcpp::wrap(anthropogenic_dir)), Shield<SEXP>(Rcpp::wrap(anthropogenic_kappa)), Shield<SEXP>(Rcpp::wrap(output_frequency)), Shield<SEXP>(Rcpp::wrap(model_type_)), Shield<SEXP>(Rcpp::wrap(latency_period)), Shield<SEXP>(Rcpp::wrap(generate_stochasticity)), Shield<SEXP>(Rcpp::wrap(establishment_stochasticity)), Shield<SEXP>(Rcpp::wrap(movement_stochasticity)), Shield<SEXP>(Rcpp::wrap(deterministic)), Shield<SEXP>(Rcpp::wrap(establishment_probability)), Shield<SEXP>(Rcpp::wrap(dispersal_percentage)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

}

#endif // RCPP_PoPS_RCPPEXPORTS_H_GEN_
