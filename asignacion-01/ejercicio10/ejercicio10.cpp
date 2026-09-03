#include <iostream>

double promedio_arreglo(const int arreglo[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; ++i) {
        suma += arreglo[i];
    }
    return static_cast<double>(suma) / tamano;
}

int contar_mayores_que(const int arreglo[], int tamano, double valor) {
    int contador = 0;
    for (int i = 0; i < tamano; ++i) {
        if (arreglo[i] > valor) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int datos[] = {2, 4, 6, 8, 10};
    int tamano = 5;

    std::cout << "Ejercicio 10 - Analisis de Datos Numericos" << std::endl;

    std::cout << "[2, 4, 6, 8, 10]   Resultado: " << promedio_arreglo(datos, tamano) << std::endl;
    std::cout << "[2, 4, 6, 8, 10]   Resultado: " << contar_mayores_que(datos, tamano, 6) << std::endl;

    return 0;
}