#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(std::string marca, std::string modelo, std::string placa, bool disponible)
    : marca(marca), modelo(modelo), placa(placa), disponible(disponible) {}

std::string Vehiculo::getMarca() const { return marca; }
std::string Vehiculo::getModelo() const { return modelo; }
std::string Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::isDisponible() const { return disponible; }
void Vehiculo::setDisponible(bool disp) { disponible = disp; }

// --- Implementación de Auto ---
Auto::Auto(std::string marca, std::string modelo, std::string placa, int pasajeros, bool disponible)
    : Vehiculo(marca, modelo, placa, disponible), capacidadPasajeros(pasajeros) {}

void Auto::mostrarInformacion() const {
    std::cout << "[Auto] Marca: " << marca 
              << " | Modelo: " << modelo 
              << " | Placa: " << placa 
              << " | Pasajeros: " << capacidadPasajeros 
              << " | Estado: " << (disponible ? "Disponible" : "Alquilado") << "\n";
}

// --- Implementación de Bicicleta ---
Bicicleta::Bicicleta(std::string marca, std::string modelo, std::string placa, std::string tipo, bool disponible)
    : Vehiculo(marca, modelo, placa, disponible), tipo(tipo) {}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[Bicicleta] Marca: " << marca 
              << " | Modelo: " << modelo 
              << " | Placa/ID: " << placa 
              << " | Tipo: " << tipo 
              << " | Estado: " << (disponible ? "Disponible" : "Alquilada") << "\n";
}

