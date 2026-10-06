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
    Libro(const std::string& titulo,
          const std::string& autor,
          const std::string& isbn);

    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getIsbn() const;
    bool estaDisponible() const;

    void setDisponible(bool valor);
    void mostrar() const;
};

#endif
