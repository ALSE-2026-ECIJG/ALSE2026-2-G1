#include "Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(const std::string& marca,
                     const std::string& modelo,
                     const std::string& placa,
                     const std::string& tipo)
    : Vehiculo(marca, modelo, placa), tipo(tipo) {}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[Bicicleta] ";
    Vehiculo::mostrarInformacion();
    std::cout << "            Tipo: " << tipo << std::endl;
}
