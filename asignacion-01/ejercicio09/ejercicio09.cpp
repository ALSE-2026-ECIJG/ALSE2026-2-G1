#include <iostream>

int* crear_arreglo(int tamano) {
    return new int[tamano];
}

void inicializar_arreglo(
    int* arreglo,
    int tamano,
    int valor
) {
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = valor;
    }
}

void destruir_arreglo(int* arreglo) {
    delete[] arreglo;
}

int main() {
    int tamano = 5;

    int* arreglo = crear_arreglo(tamano);

    inicializar_arreglo(arreglo, tamano, 10);

    std::cout << "Arreglo: ";

    for (int i = 0; i < tamano; i++) {
        std::cout << arreglo[i] << " ";
    }

    std::cout << std::endl;

    destruir_arreglo(arreglo);

    return 0;
}
