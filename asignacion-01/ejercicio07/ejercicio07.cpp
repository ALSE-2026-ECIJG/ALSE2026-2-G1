#include <iostream>

void dividir_entero(int dividendo, int divisor, int& cociente, int& residuo) {
    cociente = dividendo / divisor;
    residuo = dividendo % divisor;
}

int main() {
    int cociente = 0;
    int residuo = 0;

    std::cout << "Ejercicio 07 - Division Entera" << std::endl;

    dividir_entero(17, 5, cociente, residuo);
    std::cout << "17 / 5 Resultado: Cociente: " << cociente << ", Residuo: " << residuo << std::endl;

    dividir_entero(10, 2, cociente, residuo);
    std::cout << "10 / 2 Resultado: Cociente: " << cociente << ", Residuo: " << residuo << std::endl;

    dividir_entero(20, 7, cociente, residuo);
    std::cout << "20 / 7 Resultado: Cociente: " << cociente << ", Residuo: " << residuo << std::endl;

    return 0;
}