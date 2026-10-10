#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    void eliminarLibro(const std::string& isbn);
    void buscarPorTitulo(const std::string& titulo) const;
    void buscarPorAutor(const std::string& autor) const;
    void mostrarLibrosDisponibles() const;
};

#endif // BIBLIOTECA_H
