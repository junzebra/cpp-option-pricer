#include "Normal.hpp"
#include <cmath>

// constant for normalization factor 1/sqrt(2π)
const double inv_sqrt_2pi = 1.0 / std::sqrt(2.0 * M_PI);

// Probability Density Function (PDF)
double normal::pdf(double x) {
    double pdf_val = inv_sqrt_2pi * std::exp(-0.5 * x * x);
    return pdf_val;
}

// Probability that variable is less than x (CDF)
double normal::cdf(double x) {
    double cdf_value = 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
    return cdf_value;
}
