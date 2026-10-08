#include "Usuario.h"
#include <iostream>
#include <algorithm>

Usuario::Usuario(const std::string& nombre, int id, int limitePrestamos)
    : nombre(nombre), id(id), limitePrestamos(limitePrestamos) {}

std::string Usuario::getNombre() const { return nombre; }
int Usuario::getId() const             { return id; }
int Usuario::getLimitePrestamos() const { return limitePrestamos; }
int Usuario::getPrestamosActivos() const {
    return static_cast<int>(prestamosActivos.size());
}

bool Usuario::puedePrestar() const {
    return static_cast<int>(prestamosActivos.size()) < limitePrestamos;
}

void Usuario::agregarPrestamo(const std::string& isbn) {
    prestamosActivos.push_back(isbn);
}

void Usuario::devolverPrestamo(const std::string& isbn) {
    prestamosActivos.erase(
        std::remove(prestamosActivos.begin(), prestamosActivos.end(), isbn),
        prestamosActivos.end());
}

void Usuario::mostrarInfo() const {
    std::cout << "Usuario [" << getRol() << "] "
              << nombre << " (ID: " << id << ")"
              << " - Prestamos: " << prestamosActivos.size()
              << "/" << limitePrestamos << "\n";
}

Estudiante::Estudiante(const std::string& nombre, int id)
    : Usuario(nombre, id, 3) {}

std::string Estudiante::getRol() const { return "Estudiante"; }

Profesor::Profesor(const std::string& nombre, int id)
    : Usuario(nombre, id, 10) {}

std::string Profesor::getRol() const { return "Profesor"; }
