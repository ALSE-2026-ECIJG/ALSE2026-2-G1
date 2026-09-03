#include <iostream>

int suma_arreglo(const int arreglo[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; ++i) {
        suma += arreglo[i];
    }
    return suma;
}

int maximo_arreglo(const int arreglo[], int tamano) {
    int maximo = arreglo[0];
    for (int i = 1; i < tamano; ++i) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}

bool contiene(const int arreglo[], int tamano, int valor) {
    for (int i = 0; i < tamano; ++i) {
        if (arreglo[i] == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    int datos[] = {4, 8, 2, 10, 3};
    int tamano = 5;

    std::cout << "Ejercicio 05 - Operaciones con Arreglos" << std::endl;

    std::cout << "suma_arreglo   [4, 8, 2, 10, 3]  Resultado: " << suma_arreglo(datos, tamano) << std::endl;
    std::cout << "maximo_arreglo [4, 8, 2, 10, 3]  Resultado: " << maximo_arreglo(datos, tamano) << std::endl;

    std::cout << "contiene(8)   [4, 8, 2, 10, 3], 8  Resultado: " << contiene(datos, tamano, 8) << std::endl;
    std::cout << "contiene(20)  [4, 8, 2, 10, 3], 20  Resultado: " << contiene(datos, tamano, 20) << std::endl;

    return 0;
}