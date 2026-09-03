#include <iostream>

double celsius_a_fahrenheit(double celsius) {
    return celsius * (9.0 / 5.0) + 32.0;
}

double fahrenheit_a_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}

int main() {
    std::cout << "Ejercicio 02 - Conversión de Temperatura" << std::endl;

    std::cout << "celsius a fahrenheit: 0  Resultado: " 
              << celsius_a_fahrenheit(0) << std::endl;
    std::cout << "celsius a fahrenheit: 100  Resultado: " 
              << celsius_a_fahrenheit(100) << std::endl;
              
    std::cout << "fahrenheit a celsius: 32  Resultado: " 
              << fahrenheit_a_celsius(32) << std::endl;
    std::cout << "fahrenheit a celsius: 212  Resultado: " 
              << fahrenheit_a_celsius(212) << std::endl;

    return 0;
}