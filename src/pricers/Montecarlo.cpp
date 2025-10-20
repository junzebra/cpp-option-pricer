#include "Montecarlo.hpp"
#include "BlackScholes.hpp"
#include <cmath>
#include <random>

//random z from normal distribution
double random_z(){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> distribution(0.0,1.0);
    return distribution(generator);
}



double pricers::montecarlo_price(const models::Market& mkt, const models::Options& opt){
    double S = mkt.spot_price;
    double r = mkt.risk_free_rate;
    double q = mkt.dividend_yield;
    double sigma = mkt.volatility;
    double K = opt.strike_price;
    double T = opt.maturity;
    int sim_count = 100000;

    double total_call_price = 0;
    double total_put_price = 0;
    double avg_price = 0;
    for (int i=0; i<sim_count; i++){
        double future_price = S * std::exp((r-q-((sigma*sigma)/2)*T)+(sigma*(sqrt(T))*random_z()));



        if(opt.type == models::OptionType::Call){
            double call_price = std::fmax(0,future_price - K);
            total_call_price += call_price;
        }

        else if (opt.type == models::OptionType::Put){
            double put_price = std::fmax(0, K - future_price);
            total_put_price += put_price; 
        }
    }
    
    if(total_call_price != 0){
        avg_price = total_call_price/sim_count* std::exp(-T*(r));
        return avg_price;
    }
    else{
        avg_price = total_put_price/sim_count* std::exp(-T*(r));
        return avg_price;
    }
}
    