#include "Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado exitosamente.\n";
}

void Biblioteca::eliminarLibro(const std::string& isbn) {
    auto it = std::remove_if(libros.begin(), libros.end(), [&isbn](const Libro& l) {
        return l.getIsbn() == isbn;
    });

    if (it != libros.end()) {
        libros.erase(it, libros.end());
        std::cout << "Libro eliminado con éxito.\n";
    } else {
        std::cout << "No se encontró ningún libro con ese ISBN.\n";
    }
}

void Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro.getTitulo() == titulo) {
            libro.mostrarInfo();
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron libros con el título: " << titulo << "\n";
    }
}

void Biblioteca::buscarPorAutor(const std::string& autor) const {
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro.getAutor() == autor) {
            libro.mostrarInfo();
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron libros del autor: " << autor << "\n";
    }
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "\n--- Libros Disponibles ---\n";
    bool hayDisponibles = false;
    for (const auto& libro : libros) {
        if (libro.isDisponible()) {
            libro.mostrarInfo();
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles) {
        std::cout << "No hay libros disponibles en este momento.\n";
    }
}
