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
    return static_cast<double>(a) / b;
}

int main() {
    std::cout << "Suma: " << sumar(10, 5) << std::endl;
    std::cout << "Resta: " << restar(10, 5) << std::endl;
    std::cout << "Multiplicacion: " << multiplicar(10, 5) << std::endl;
    std::cout << "Division: " << dividir(5, 2) << std::endl;

    return 0;
}