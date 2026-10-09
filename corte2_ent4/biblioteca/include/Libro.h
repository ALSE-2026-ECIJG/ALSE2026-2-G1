#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

public:
    Libro();
    Libro(const std::string& titulo,
          const std::string& autor,
          const std::string& isbn,
          bool disponible = true);

    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getIsbn() const;
    bool isDisponible() const;

    void setDisponible(bool estado);

    void mostrarInfo() const;
};

#endif // LIBRO_H
