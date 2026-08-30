#include <iostream>

double promedio_arreglo(const int arreglo[], int tamano) {
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += arreglo[i];
    }

    return static_cast<double>(suma) / tamano;
}

int contar_mayores_que(
    const int arreglo[],
    int tamano,
    double valor
) {
    int cantidad = 0;

    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] > valor) {
            cantidad++;
        }
    }

    return cantidad;
}

int main() {
    int arreglo[] = {2, 4, 6, 8, 10};
    int tamano = 5;

    std::cout << "Promedio: "
              << promedio_arreglo(arreglo, tamano)
              << std::endl;

    std::cout << "Mayores que 6: "
              << contar_mayores_que(arreglo, tamano, 6)
              << std::endl;

    return 0;
}
