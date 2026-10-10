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
    Libro(std::string t, std::string a, std::string i, bool disp = true);

    // Métodos Getters y Setters
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getIsbn() const;
    bool isDisponible() const;

    void setDisponible(bool disp);

    void mostrarInfo() const;
};

#endif // LIBRO_H
