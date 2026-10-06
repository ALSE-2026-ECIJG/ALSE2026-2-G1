#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const std::string& marca,
                   const std::string& modelo,
                   const std::string& placa)
    : marca(marca), modelo(modelo), placa(placa), alquilado(false) {}

std::string Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::estaDisponible() const { return !alquilado; }
void Vehiculo::setAlquilado(bool valor) { alquilado = valor; }

void Vehiculo::mostrarInformacion() const {
    std::cout << marca << " " << modelo << " | Placa: " << placa
              << " | " << (alquilado ? "Alquilado" : "Disponible")
              << std::endl;
}
