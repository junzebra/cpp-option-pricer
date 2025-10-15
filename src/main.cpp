#include<iostream>
#include "math/Normal.hpp"
#include "pricers/BlackScholes.hpp"

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
    

    double call_price = pricers::black_scholes_price(mkt, callOpt);
    double put_price = pricers::black_scholes_price(mkt, putOpt);

    std::cout << "Call price : " << call_price << "\nPut price : " << put_price << std::endl;

    


}

