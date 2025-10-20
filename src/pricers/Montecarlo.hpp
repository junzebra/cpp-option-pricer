#pragma once

#include "../models/Market.hpp"
#include "../models/Options.hpp"

namespace pricers{
    double montecarlo_price(const models::Market& mkt, const models::Options& opt);
}