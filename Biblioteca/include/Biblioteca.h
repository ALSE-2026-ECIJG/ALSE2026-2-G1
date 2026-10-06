#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>
#include "Libro.h"

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    bool eliminarLibro(const std::string& isbn);
    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;
    bool prestarLibro(const std::string& isbn);
    void mostrarDisponibles() const;
};

#endif
