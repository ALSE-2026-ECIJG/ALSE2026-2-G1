#include <iostream>

void multiplicar_arreglo(int arreglo[], int tamano, int factor) {
    for (int i = 0; i < tamano; ++i) {
        arreglo[i] *= factor;
    }
}

int main() {
    int datos[] = {1, 2, 3, 4};
    int tamano = 4;

    std::cout << "Ejercicio 06 - Transformacion de un Arreglo" << std::endl;

    multiplicar_arreglo(datos, tamano, 3);

    std::cout << "multiplicar_arreglo Resultado: ";
    for (int i = 0; i < tamano; ++i) {
        std::cout << datos[i] << (i < tamano - 1 ? " " : "");
    }
    std::cout << std::endl;

    return 0;
}