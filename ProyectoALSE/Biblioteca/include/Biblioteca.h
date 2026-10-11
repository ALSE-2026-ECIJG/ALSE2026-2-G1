#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "Libro.h"

/**
 * @class Biblioteca
 * @brief Gestiona una colección de libros: agregar, eliminar, buscar y listar.
 */
class Biblioteca {
private:
    std::vector<Libro> libros;  ///< Colección de libros

public:
    /**
     * @brief Agrega un libro a la biblioteca.
     * @param libro Libro a agregar
     * @return true si se agregó, false si ya existía un libro con ese ISBN
     */
    bool agregarLibro(const Libro& libro);

    /**
     * @brief Elimina un libro según su ISBN.
     * @param isbn ISBN del libro a eliminar
     * @return true si se eliminó, false si no se encontró
     */
    bool eliminarLibro(const std::string& isbn);

    /**
     * @brief Busca libros cuyo título contenga el texto dado.
     * @param titulo Texto a buscar en el título
     * @return Vector con los libros encontrados
     */
    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;

    /**
     * @brief Busca libros cuyo autor contenga el texto dado.
     * @param autor Texto a buscar en el autor
     * @return Vector con los libros encontrados
     */
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;

    /** @brief Muestra en pantalla solo los libros disponibles. */
    void mostrarDisponibles() const;
};

#endif
