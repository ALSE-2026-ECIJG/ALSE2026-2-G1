#include "Vehiculo.h"

Vehiculo::Vehiculo(const std::string& marca,
                   const std::string& modelo,
                   const std::string& placa)
    : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

std::string Vehiculo::getMarca() const { return marca; }
std::string Vehiculo::getModelo() const { return modelo; }
std::string Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::isDisponible() const { return disponible; }

void Vehiculo::setDisponible(bool estado) { disponible = estado; }
