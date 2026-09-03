#include <iostream>

void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Ejercicio 08 - Intercambio mediante Punteros" << std::endl;

    intercambiar(&x, &y);
    std::cout << "x = 10, y = 20 Resultado: x = " << x << ", y = " << y << std::endl;

    x = -5;
    y = 8;
    intercambiar(&x, &y);
    std::cout << "x = -5, y = 8  Resultado: x = " << x << ", y = " << y << std::endl;

    return 0;
}