#include <iostream>

int clasificar_numero(int numero) {
    if (numero > 0) {
        return 1;
    } else if (numero < 0) {
        return -1;
    }
    return 0;
}

bool es_positivo_par(int numero) {

    return (numero > 0) && (numero % 2 == 0);
}

int main() {
    std::cout << "Ejercicio 03 - Clasificacion de Numeros" << std::endl;

    std::cout << "clasificar_numero(15) Resultado: " << clasificar_numero(15) << std::endl;
    std::cout << "clasificar_numero(0)  Resultado: " << clasificar_numero(0) << std::endl;
    std::cout << "clasificar_numero(-7) Resultado: " << clasificar_numero(-7) << std::endl;

    std::cout << "es_positivo_par(2)    Resultado: " << es_positivo_par(2) << std::endl;
    std::cout << "es_positivo_par(10)   Resultado: " << es_positivo_par(10) << std::endl;
    std::cout << "es_positivo_par(3)    Resultado: " << es_positivo_par(3) << std::endl;
    std::cout << "es_positivo_par(-2)   Resultado: " << es_positivo_par(-2) << std::endl;
    std::cout << "es_positivo_par(0)    Resultado: " << es_positivo_par(0) << std::endl;

    return 0;
}