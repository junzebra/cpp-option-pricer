# 🧮 C++ Option Pricer — Black-Scholes Model

This project implements a **modular C++ option pricing library** based on the **Black-Scholes model** for European call and put options.  

---

## 📂 Project Structure

OptionPricer/
├── src/
│ ├── main.cpp # Test driver (runs the pricing engine)
│ ├── math/
│ │ ├── Normal.cpp # Normal distribution PDF and CDF
│ │ └── Normal.hpp
│ ├── models/
│ │ ├── Market.hpp # Market data structure (spot, rates, volatility)
│ │ └── Options.hpp # Option contract details (type, strike, maturity)
│ └── pricers/
│ ├── BlackScholes.cpp # Black-Scholes pricing implementation
│ └── BlackScholes.hpp
└── README.md


---


## 💻 Example Run

**Inputs**

| Variable | Symbol | Value |
|-----------|:------:|:------|
| Spot price | S | 100 |
| Strike price | K | 100 |
| Risk-free rate | r | 0.05 |
| Dividend yield | q | 0.02 |
| Volatility | σ | 0.20 |
| Time to maturity | T | 1 year |

**Output**

Call price : 9.2270
Put price : 6.3301


These values match the analytical Black-Scholes benchmark for European options.

---

## 🛠️ Build Instructions

From the project root:
```bash
g++ src/main.cpp src/math/Normal.cpp src/pricers/BlackScholes.cpp -o pricer -std=c++17
./pricer

If using VS Code, press Ctrl + Shift + B to build with the predefined task.
🚀 Future Improvements

    Compute Greeks (Δ Gamma Vega Theta Rho)

    Implement Monte Carlo and Binomial Tree pricing

    Add CLI or CSV input

    Unit-test each module
# cpp-option-pricer
