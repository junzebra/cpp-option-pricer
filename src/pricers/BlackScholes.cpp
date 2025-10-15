#include "BlackScholes.hpp"
#include <cmath>

double pricers::black_scholes_price(const models::Market& mkt, const models::Options& opt) {
    double S = mkt.spot_price;
    double r = mkt.risk_free_rate;
    double q = mkt.dividend_yield;
    double sigma = mkt.volatility;
    double K = opt.strike_price;
    double T = opt.maturity;

    // Calculations
    double d1 = (std::log(S / K) + (r - q + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (opt.type == models::OptionType::Call) {
        // Call option
        double call_sigma_d1 = normal::cdf(d1);
        double call_sigma_d2 = normal::cdf(d2);

        double call_price = (S * std::exp(-q * T) * call_sigma_d1)
                          - (K * std::exp(-r * T) * call_sigma_d2);
        return call_price;
    }
    else if (opt.type == models::OptionType::Put) {
        // Put option
        double put_sigma_d1 = normal::cdf(-d1);
        double put_sigma_d2 = normal::cdf(-d2);

        double put_price = (K * std::exp(-r * T) * put_sigma_d2)
                         - (S * std::exp(-q * T) * put_sigma_d1);
        return put_price;
    }
    else {
        return 0.0;
    }
}
