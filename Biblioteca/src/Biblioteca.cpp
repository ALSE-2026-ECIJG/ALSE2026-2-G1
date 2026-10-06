#include "Biblioteca.h"
#include <iostream>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
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
    for (const Libro& libro : libros) {
        if (libro.getTitulo().find(titulo) != std::string::npos) {
            resultado.push_back(libro);
        }
    }
    return resultado;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultado;
    for (const Libro& libro : libros) {
        if (libro.getAutor().find(autor) != std::string::npos) {
            resultado.push_back(libro);
        }
    }
    return resultado;
}

bool Biblioteca::prestarLibro(const std::string& isbn) {
    for (size_t i = 0; i < libros.size(); i++) {
        if (libros[i].getIsbn() == isbn && libros[i].estaDisponible()) {
            libros[i].setDisponible(false);
            return true;
        }
    }
    return false;
}

void Biblioteca::mostrarDisponibles() const {
    std::cout << "--- Libros disponibles ---" << std::endl;
    bool hayAlguno = false;
    for (const Libro& libro : libros) {
        if (libro.estaDisponible()) {
            libro.mostrar();
            hayAlguno = true;
        }
    }
    if (!hayAlguno) {
        std::cout << "No hay libros disponibles." << std::endl;
    }
}
