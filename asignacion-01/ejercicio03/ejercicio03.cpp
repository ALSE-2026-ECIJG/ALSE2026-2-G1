#include <iostream>

int clasificar_numero(int numero) {
    if (numero > 0) {
        return 1;
    } else if (numero < 0) {
        return -1;
    } else {
        return 0;
    }
}

bool es_positivo_par(int numero) {
    return numero > 0 && numero % 2 == 0;
}

int main() {
    std::cout << "Clasificacion de 15: " << clasificar_numero(15) << std::endl;
    std::cout << "Clasificacion de 0: " << clasificar_numero(0) << std::endl;
    std::cout << "Clasificacion de -7: " << clasificar_numero(-7) << std::endl;

    std::cout << "2 es positivo y par: " << es_positivo_par(2) << std::endl;
    std::cout << "3 es positivo y par: " << es_positivo_par(3) << std::endl;
    std::cout << "-2 es positivo y par: " << es_positivo_par(-2) << std::endl;
    std::cout << "0 es positivo y par: " << es_positivo_par(0) << std::endl;

    return 0;
}