#include "Libro.h"
#include <iostream>

Libro::Libro()
    : titulo(""), autor(""), isbn(""), disponible(true) {}

Libro::Libro(const std::string& titulo,
             const std::string& autor,
             const std::string& isbn,
             bool disponible)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(disponible) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const  { return autor; }
std::string Libro::getIsbn() const   { return isbn; }
bool        Libro::isDisponible() const { return disponible; }

void Libro::setDisponible(bool estado) { disponible = estado; }

void Libro::mostrarInfo() const {
    std::cout << "  ISBN: " << isbn
              << " | Titulo: " << titulo
              << " | Autor: " << autor
              << " | Estado: " << (disponible ? "Disponible" : "Prestado")
              << "\n";
}
