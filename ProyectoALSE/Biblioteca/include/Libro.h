#ifndef LIBRO_H
#define LIBRO_H

#include <string>

/**
 * @class Libro
 * @brief Representa un libro de la biblioteca.
 */
class Libro {
private:
    std::string titulo;  ///< Título del libro
    std::string autor;   ///< Autor del libro
    std::string isbn;    ///< Código ISBN (identificador único)
    bool disponible;     ///< true si el libro no está prestado

public:
    /**
     * @brief Constructor. El libro se crea como disponible.
     * @param titulo Título del libro
     * @param autor Autor del libro
     * @param isbn Código ISBN
     */
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn);

    /** @brief Devuelve el título. */
    const std::string& getTitulo() const;
    /** @brief Devuelve el autor. */
    const std::string& getAutor() const;
    /** @brief Devuelve el ISBN. */
    const std::string& getIsbn() const;
    /** @brief Indica si el libro está disponible. */
    bool estaDisponible() const;
    /**
     * @brief Cambia el estado de disponibilidad.
     * @param disponible Nuevo estado
     */
    void setDisponible(bool disponible);

    /** @brief Imprime la información del libro en pantalla. */
    void mostrar() const;
};

#endif
