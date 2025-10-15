#pragma once

#include "../math/Normal.hpp"
#include "../models/Market.hpp"
#include "../models/Options.hpp"

namespace pricers{
    double black_scholes_price(const models::Market& mkt, const models::Options& opt);
}