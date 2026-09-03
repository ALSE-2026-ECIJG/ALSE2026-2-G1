#include <iostream>

int* crear_arreglo(int tamano) {
    return new int[tamano];
}

void inicializar_arreglo(int* arreglo, int tamano, int valor) {
    for (int i = 0; i < tamano; ++i) {
        arreglo[i] = valor;
    }
}

void destruir_arreglo(int* arreglo) {
    delete[] arreglo;
}

int main() {
    int tamano = 5;

    std::cout << "Ejercicio 09 - Arreglo Dinamico de Enteros" << std::endl;

    int* mi_arreglo = crear_arreglo(tamano);
    inicializar_arreglo(mi_arreglo, tamano, 10);

    std::cout << "inicializar_arreglo Resultado: ";
    for (int i = 0; i < tamano; ++i) {
        std::cout << mi_arreglo[i] << (i < tamano - 1 ? " " : "");
    }
    std::cout << std::endl;

    destruir_arreglo(mi_arreglo);

    return 0;
}