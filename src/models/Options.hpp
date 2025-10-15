#pragma once

namespace models{
    enum class OptionType {Call,Put};

    struct Options{
        OptionType type;
        double strike_price;
        double maturity;
    };
}