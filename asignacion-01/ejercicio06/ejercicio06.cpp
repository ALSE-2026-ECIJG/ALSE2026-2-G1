#include <iostream>

void multiplicar_arreglo(int arreglo[], int tamano, int factor) {
    for (int i = 0; i < tamano; i++) {
        arreglo[i] *= factor;
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4};
    int tamano = 4;
    int factor = 3;

    multiplicar_arreglo(arreglo, tamano, factor);

    std::cout << "Arreglo despues de multiplicar: ";

    for (int i = 0; i < tamano; i++) {
        std::cout << arreglo[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}