#include <iostream>

double celsius_a_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double fahrenheit_a_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    std::cout << "0 C = " << celsius_a_fahrenheit(0) << " F" << std::endl;
    std::cout << "100 C = " << celsius_a_fahrenheit(100) << " F" << std::endl;
    std::cout << "32 F = " << fahrenheit_a_celsius(32) << " C" << std::endl;
    std::cout << "212 F = " << fahrenheit_a_celsius(212) << " C" << std::endl;

    return 0;
}