#include "Biblioteca.h"
#include <iostream>
#include <algorithm>

bool Biblioteca::agregarLibro(const Libro& libro) {
    for (const auto& l : libros) {
        if (l.getIsbn() == libro.getIsbn()) {
            std::cout << "Ya existe un libro con ISBN " << libro.getIsbn() << "\n";
            return false;
        }
    }
    libros.push_back(libro);
    return true;
}

bool Biblioteca::eliminarLibro(const std::string& isbn) {
    auto it = std::remove_if(libros.begin(), libros.end(),
        [&isbn](const Libro& l){ return l.getIsbn() == isbn; });

    if (it == libros.end()) return false;
    libros.erase(it, libros.end());
    return true;
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::vector<Libro> resultado;
    for (const auto& l : libros) {
        if (l.getTitulo().find(titulo) != std::string::npos) {
            resultado.push_back(l);
        }
    }
    return resultado;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultado;
    for (const auto& l : libros) {
        if (l.getAutor().find(autor) != std::string::npos) {
            resultado.push_back(l);
        }
    }
    return resultado;
}

std::vector<Libro> Biblioteca::librosDisponibles() const {
    std::vector<Libro> resultado;
    for (const auto& l : libros) {
        if (l.isDisponible()) resultado.push_back(l);
    }
    return resultado;
}

bool Biblioteca::prestarLibro(const std::string& isbn, Usuario& usuario) {
    if (!usuario.puedePrestar()) {
        std::cout << usuario.getNombre()
                  << " alcanzo su limite de prestamos.\n";
        return false;
    }
    for (auto& l : libros) {
        if (l.getIsbn() == isbn) {
            if (!l.isDisponible()) {
                std::cout << "El libro ya esta prestado.\n";
                return false;
            }
            l.setDisponible(false);
            usuario.agregarPrestamo(isbn);
            std::cout << "Prestado \"" << l.getTitulo()
                      << "\" a " << usuario.getNombre() << "\n";
            return true;
        }
    }
    std::cout << "ISBN no encontrado.\n";
    return false;
}

bool Biblioteca::devolverLibro(const std::string& isbn, Usuario& usuario) {
    for (auto& l : libros) {
        if (l.getIsbn() == isbn) {
            l.setDisponible(true);
            usuario.devolverPrestamo(isbn);
            std::cout << "Devuelto \"" << l.getTitulo()
                      << "\" por " << usuario.getNombre() << "\n";
            return true;
        }
    }
    return false;
}

void Biblioteca::mostrarCatalogo() const {
    std::cout << "--- Catalogo (" << libros.size() << " libros) ---\n";
    for (const auto& l : libros) l.mostrarInfo();
}

std::size_t Biblioteca::totalLibros() const { return libros.size(); }
