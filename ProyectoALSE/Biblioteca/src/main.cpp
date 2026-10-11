#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Biblioteca.h"

/** @brief Muestra un texto y lee una línea completa (permite espacios). */
std::string leerTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

/** @brief Lee un número entero desde el teclado (repite si escriben otra cosa). */
int leerEntero() {
    int valor;
    while (!(std::cin >> valor)) {
        if (std::cin.eof()) return 0;  // se acabó la entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Escribe un numero valido: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

/** @brief Muestra los resultados de una búsqueda. */
void mostrarResultados(const std::vector<Libro>& resultados) {
    if (resultados.empty()) {
        std::cout << "No se encontraron libros.\n";
        return;
    }
    for (size_t i = 0; i < resultados.size(); i++) {
        resultados[i].mostrar();
    }
}

int main() {
    Biblioteca biblioteca;

    // Libros iniciales (el usuario puede agregar o eliminar los que quiera)
    biblioteca.agregarLibro(Libro("Cien anos de soledad", "Gabriel Garcia Marquez", "111"));
    biblioteca.agregarLibro(Libro("El principito", "Antoine de Saint-Exupery", "222"));
    biblioteca.agregarLibro(Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "333"));

    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n===== BIBLIOTECA =====\n"
                  << "1. Agregar libro\n"
                  << "2. Eliminar libro\n"
                  << "3. Buscar por titulo\n"
                  << "4. Buscar por autor\n"
                  << "5. Mostrar libros disponibles\n"
                  << "0. Salir\n"
                  << "Opcion: ";
        opcion = leerEntero();

        if (opcion == 1) {
            std::string titulo = leerTexto("Titulo: ");
            std::string autor = leerTexto("Autor: ");
            std::string isbn = leerTexto("ISBN: ");
            if (titulo.empty() || autor.empty() || isbn.empty()) {
                std::cout << "Todos los campos son obligatorios.\n";
            } else if (biblioteca.agregarLibro(Libro(titulo, autor, isbn))) {
                std::cout << "Libro agregado.\n";
            } else {
                std::cout << "Ya existe un libro con ese ISBN.\n";
            }

        } else if (opcion == 2) {
            std::string isbn = leerTexto("ISBN del libro a eliminar: ");
            if (biblioteca.eliminarLibro(isbn)) {
                std::cout << "Libro eliminado.\n";
            } else {
                std::cout << "No existe un libro con ese ISBN.\n";
            }

        } else if (opcion == 3) {
            mostrarResultados(biblioteca.buscarPorTitulo(leerTexto("Titulo a buscar: ")));

        } else if (opcion == 4) {
            mostrarResultados(biblioteca.buscarPorAutor(leerTexto("Autor a buscar: ")));

        } else if (opcion == 5) {
            std::cout << "\n--- Libros disponibles ---\n";
            biblioteca.mostrarDisponibles();

        } else if (opcion != 0) {
            std::cout << "Opcion no valida.\n";
        }
    }

    std::cout << "Hasta luego!\n";
    return 0;
}
