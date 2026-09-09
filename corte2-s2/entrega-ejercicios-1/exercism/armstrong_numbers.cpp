#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrongNumber(int numero) {
    int original = numero;
    int digitos = 0;
    int suma = 0;

    int temporal = numero;

    while (temporal > 0) {
        digitos++;
        temporal /= 10;
    }

    temporal = numero;

    while (temporal > 0) {
        int digito = temporal % 10;
        suma += pow(digito, digitos);
        temporal /= 10;
    }

    return suma == original;
}

int main() {
    int numero = 153;

    if (isArmstrongNumber(numero)) {
        cout << "Es un numero de Armstrong" << endl;
    } else {
        cout << "No es un numero de Armstrong" << endl;
    }

    return 0;
}
