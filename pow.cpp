#include <iostream>
#include <cmath>

// Function to calculate power of a number
double custom_power(double base, double exponent) {
    if (exponent == 0)
        return 1;
    else if (exponent > 0)
        return exp(exponent * log(base));
    else
        return 1 / exp(-exponent * log(base));
}

int main() {
    double base, exponent, result;

    // Taking base and exponent as input
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    // Calculating power
    result = custom_power(base, exponent);

    // Displaying the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
