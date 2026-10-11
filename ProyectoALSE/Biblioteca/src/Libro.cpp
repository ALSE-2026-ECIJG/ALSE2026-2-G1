#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(true) {}

const std::string& Libro::getTitulo() const { return titulo; }
const std::string& Libro::getAutor() const { return autor; }
const std::string& Libro::getIsbn() const { return isbn; }
bool Libro::estaDisponible() const { return disponible; }
void Libro::setDisponible(bool disponible) { this->disponible = disponible; }

void Libro::mostrar() const {
    std::cout << titulo << " - " << autor << " (ISBN: " << isbn << ") "
              << (disponible ? "[Disponible]" : "[Prestado]") << "\n";
}
