#include <iostream>

// ---------------------------------------------------------
// Ejemplo alternativo: operaciones básicas con cadenas estilo C
// Este ejemplo NO es parte de la asignación.
// Su propósito es mostrar estructura, funciones puras y pruebas.
// ---------------------------------------------------------

// Función que calcula la longitud de una cadena estilo C
int longitud(const char texto[]) {
    int contador = 0;
    while (texto[contador] != '\0') {
        contador++;
    }
    return contador;
}

// Función que cuenta cuántas veces aparece un carácter en la cadena
int contar_caracter(const char texto[], char c) {
    int contador = 0;
    int i = 0;

    while (texto[i] != '\0') {
        if (texto[i] == c) {
            contador++;
        }
        i++;
    }

    return contador;
}

// Función que convierte todas las letras minúsculas a mayúsculas
// (solo para caracteres ASCII entre 'a' y 'z')
void convertir_mayusculas(char texto[]) {
    int i = 0;

    while (texto[i] != '\0') {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = texto[i] - ('a' - 'A');
        }
        i++;
    }
}

// ---------------------------------------------------------
// main() solo para pruebas manuales.
// ---------------------------------------------------------
int main() {
    char saludo[] = "Hola Mundo";

    std::cout << "Texto: " << saludo << "\n";
    std::cout << "Longitud: " << longitud(saludo) << "\n";
    std::cout << "Cantidad de 'o': " << contar_caracter(saludo, 'o') << "\n";

    convertir_mayusculas(saludo);
    std::cout << "En mayúsculas: " << saludo << "\n";

    return 0;
}
