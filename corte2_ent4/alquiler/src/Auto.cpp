#include "Auto.h"
#include <iostream>

Auto::Auto(const std::string& marca,
           const std::string& modelo,
           const std::string& placa,
           int capacidadPasajeros)
    : Vehiculo(marca, modelo, placa),
      capacidadPasajeros(capacidadPasajeros) {}

int Auto::getCapacidadPasajeros() const { return capacidadPasajeros; }

void Auto::mostrarInformacion() const {
    std::cout << "  [Auto] " << marca << " " << modelo
              << " | Placa: " << placa
              << " | Pasajeros: " << capacidadPasajeros
              << " | Estado: " << (disponible ? "Disponible" : "Alquilado")
              << "\n";
}

std::string Auto::getTipo() const { return "Auto"; }
