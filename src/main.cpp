#include<iostream>
#include "math/Normal.hpp"
#include "pricers/BlackScholes.hpp"
#include "pricers/Montecarlo.hpp"

int main() {
    models::Market mkt;
        mkt.spot_price = 100;
        mkt.risk_free_rate = 0.05;
        mkt.dividend_yield = 0.02;
        mkt.volatility = 0.2;

    models::Options callOpt;
        callOpt.maturity = 1;
        callOpt.strike_price = 100;
        callOpt.type = models::OptionType::Call;

    models::Options putOpt;
        putOpt.maturity = 1;
        putOpt.strike_price = 100;
        putOpt.type = models::OptionType::Put;
    

    double bs_call_price = pricers::black_scholes_price(mkt, callOpt);
    double bs_put_price = pricers::black_scholes_price(mkt, putOpt);
    double mc_call_price = pricers::montecarlo_price(mkt, callOpt);
    double mc_put_price = pricers::montecarlo_price(mkt,putOpt);

    std::cout <<"Black Scholes :\n" << "Call price : " << bs_call_price << "\nPut price : " << bs_put_price << std::endl;
    std::cout <<"Montecarlo :\n" << "Call price : " << mc_call_price << "\nPut price : " << mc_put_price << std::endl;
    
    


}

