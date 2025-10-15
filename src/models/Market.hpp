#pragma once

namespace models{

    struct Market{
        double spot_price;
        double risk_free_rate;
        double dividend_yield;
        double volatility;
    };
}