#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "Libro.h"
#include "Usuario.h"

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    bool agregarLibro(const Libro& libro);
    bool eliminarLibro(const std::string& isbn);

    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;

    std::vector<Libro> librosDisponibles() const;

    bool prestarLibro(const std::string& isbn, Usuario& usuario);
    bool devolverLibro(const std::string& isbn, Usuario& usuario);

    void mostrarCatalogo() const;
    std::size_t totalLibros() const;
};

#endif // BIBLIOTECA_H
