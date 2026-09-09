#include <string>

using namespace std;

int hamming_distance(const string& cadena1, const string& cadena2) {
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
