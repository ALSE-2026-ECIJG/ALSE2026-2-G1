#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa)
    : marca(marca), modelo(modelo), placa(placa), alquilado(false) {}

const std::string& Vehiculo::getMarca() const { return marca; }
const std::string& Vehiculo::getModelo() const { return modelo; }
const std::string& Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::estaAlquilado() const { return alquilado; }
void Vehiculo::setAlquilado(bool alquilado) { this->alquilado = alquilado; }

void Vehiculo::mostrarInformacion() const {
    std::cout << "Marca: " << marca << " | Modelo: " << modelo
              << " | Placa: " << placa
              << " | Estado: " << (alquilado ? "Alquilado" : "Disponible");
}
