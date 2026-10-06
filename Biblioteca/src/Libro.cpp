#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string& titulo,
             const std::string& autor,
             const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(true) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getIsbn() const { return isbn; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::setDisponible(bool valor) { disponible = valor; }

void Libro::mostrar() const {
    std::cout << titulo << " | " << autor << " | ISBN: " << isbn
              << " | " << (disponible ? "Disponible" : "Prestado")
              << std::endl;
}
