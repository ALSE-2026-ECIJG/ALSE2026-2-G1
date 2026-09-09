#include <iostream>
#include <string>

using namespace std;

int hammingDistance(string cadena1, string cadena2) {
    if (cadena1.length() != cadena2.length()) {
        return -1;
    }

    int distancia = 0;

    for (int i = 0; i < cadena1.length(); i++) {
        if (cadena1[i] != cadena2[i]) {
            distancia++;
        }
    }

    return distancia;
}

int main() {
    string cadena1 = "GAGCCTACTAACGGGAT";
    string cadena2 = "CATCGTAATGACGGCCT";

    int resultado = hammingDistance(cadena1, cadena2);

    if (resultado == -1) {
        cout << "Las cadenas deben tener la misma longitud" << endl;
    } else {
        cout << "Distancia de Hamming: " << resultado << endl;
    }

    return 0;
}
