#include <iostream>

int suma_hasta(int n) {
    int suma = 0;

    for (int i = 1; i <= n; i++) {
        suma += i;
    }

    return suma;
}

int contar_pares(int n) {
    int cantidad = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cantidad++;
        }
    }

    return cantidad;
}

int main() {
    std::cout << "Suma hasta 5: " << suma_hasta(5) << std::endl;
    std::cout << "Suma hasta 10: " << suma_hasta(10) << std::endl;

    std::cout << "Pares hasta 5: " << contar_pares(5) << std::endl;
    std::cout << "Pares hasta 10: " << contar_pares(10) << std::endl;

    return 0;
}