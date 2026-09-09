#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string columnTitle) {
    int resultado = 0;

    for (char letra : columnTitle) {
        int valor = letra - 'A' + 1;
        resultado = resultado * 26 + valor;
    }

    return resultado;
}

int main() {
    string columnTitle = "AB";

    int resultado = titleToNumber(columnTitle);

    cout << resultado << endl;

    return 0;
}