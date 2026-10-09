#include "Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(const std::string& marca,
                     const std::string& modelo,
                     const std::string& placa,
                     const std::string& tipo)
    : Vehiculo(marca, modelo, placa),
      tipo(tipo) {}

std::string Bicicleta::getTipoBicicleta() const { return tipo; }

void Bicicleta::mostrarInformacion() const {
    std::cout << "  [Bicicleta] " << marca << " " << modelo
              << " | Placa: " << placa
              << " | Tipo: " << tipo
              << " | Estado: " << (disponible ? "Disponible" : "Alquilada")
              << "\n";
}

std::string Bicicleta::getTipo() const { return "Bicicleta"; }
