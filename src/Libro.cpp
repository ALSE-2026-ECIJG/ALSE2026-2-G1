#include "Libro.h"
#include <iostream>

Libro::Libro(std::string t, std::string a, std::string i, bool disp)
    : titulo(t), autor(a), isbn(i), disponible(disp) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getIsbn() const { return isbn; }
bool Libro::isDisponible() const { return disponible; }

void Libro::setDisponible(bool disp) { disponible = disp; }

void Libro::mostrarInfo() const {
    std::cout << "Título: " << titulo 
              << " | Autor: " << autor 
              << " | ISBN: " << isbn 
              << " | Estado: " << (disponible ? "Disponible" : "Prestado") << "\n";
}
