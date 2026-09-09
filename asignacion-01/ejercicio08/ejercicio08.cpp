#include <iostream>

void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Antes del intercambio:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    intercambiar(&x, &y);

    std::cout << "Despues del intercambio:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}
