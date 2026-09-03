#include <iostream>

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

double dividir(int a, int b) {

    return (double)a / b;
}

int main() {
    std::cout << "Ejercicio 01 - Calculadora Básica" << std::endl;
    
    std::cout << "sumar(10, 5)         Resultado: " << sumar(10, 5) << std::endl;
    std::cout << "restar(10, 5)        Resultado: " << restar(10, 5) << std::endl;
    std::cout << "multiplicar(10, 5)   Resultado: " << multiplicar(10, 5) << std::endl;
    std::cout << "dividir(10, 5)       Resultado: " << dividir(10, 5) << std::endl;
    std::cout << "dividir(5, 2)        Resultado: " << dividir(5, 2) << std::endl;

    return 0;
}