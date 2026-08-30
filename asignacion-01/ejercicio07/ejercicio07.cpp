#include <iostream>

void dividir_entero(
    int dividendo,
    int divisor,
    int& cociente,
    int& residuo
) {
    cociente = dividendo / divisor;
    residuo = dividendo % divisor;
}

int main() {
    int cociente;
    int residuo;

    dividir_entero(17, 5, cociente, residuo);

    std::cout << "Cociente: " << cociente << std::endl;
    std::cout << "Residuo: " << residuo << std::endl;

    dividir_entero(20, 7, cociente, residuo);

    std::cout << "Cociente: " << cociente << std::endl;
    std::cout << "Residuo: " << residuo << std::endl;

    return 0;
}