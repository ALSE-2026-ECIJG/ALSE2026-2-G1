#include <iostream>

// Declaración e implementación de funciones
int suma_hasta(int n) {
    int suma = 0;
    for (int i = 1; i <= n; ++i) {
        suma += i;
    }
    return suma;
}

int contar_pares(int n) {
    int contador = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

int main() {

    std::cout << "Ejercicio 04 - Estadísticas de Enteros" << std::endl;

    std::cout << "suma_hasta(1)  Resultado: " << suma_hasta(1) << std::endl;
    std::cout << "suma_hasta(5)  Resultado: " << suma_hasta(5) << std::endl;
    std::cout << "suma_hasta(10) Resultado: " << suma_hasta(10) << std::endl;

    std::cout << "contar_pares(1)  Resultado: " << contar_pares(1) << std::endl;
    std::cout << "contar_pares(5)  Resultado: " << contar_pares(5) << std::endl;
    std::cout << "contar_pares(10) Resultado: " << contar_pares(10) << std::endl;

    return 0;
}