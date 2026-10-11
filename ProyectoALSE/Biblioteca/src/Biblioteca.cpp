#include "Biblioteca.h"
#include <iostream>

bool Biblioteca::agregarLibro(const Libro& libro) {
    for (const auto& l : libros) {
        if (l.getIsbn() == libro.getIsbn()) return false;
    }
    libros.push_back(libro);
    return true;
}

bool Biblioteca::eliminarLibro(const std::string& isbn) {
    for (size_t i = 0; i < libros.size(); i++) {
        if (libros[i].getIsbn() == isbn) {
            libros.erase(libros.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::vector<Libro> resultado;
    for (const auto& l : libros) {
        if (l.getTitulo().find(titulo) != std::string::npos) resultado.push_back(l);
    }
    return resultado;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultado;
    for (const auto& l : libros) {
        if (l.getAutor().find(autor) != std::string::npos) resultado.push_back(l);
    }
    return resultado;
}

void Biblioteca::mostrarDisponibles() const {
    for (const auto& l : libros) {
        if (l.estaDisponible()) l.mostrar();
    }
}
