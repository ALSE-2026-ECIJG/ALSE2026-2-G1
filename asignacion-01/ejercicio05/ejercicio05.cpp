#include <iostream>

int suma_arreglo(const int arreglo[], int tamano) {
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += arreglo[i];
    }

    return suma;
}

int maximo_arreglo(const int arreglo[], int tamano) {
    int maximo = arreglo[0];

    for (int i = 1; i < tamano; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }

    return maximo;
}

bool contiene(const int arreglo[], int tamano, int valor) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == valor) {
            return true;
        }
    }

    return false;
}

int main() {
    int arreglo[] = {4, 8, 2, 10, 3};
    int tamano = 5;

    std::cout << "Suma: " << suma_arreglo(arreglo, tamano) << std::endl;
    std::cout << "Maximo: " << maximo_arreglo(arreglo, tamano) << std::endl;
    std::cout << "Contiene 8: " << contiene(arreglo, tamano, 8) << std::endl;
    std::cout << "Contiene 20: " << contiene(arreglo, tamano, 20) << std::endl;

    return 0;
}