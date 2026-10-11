#include "Auto.h"
#include <iostream>

Auto::Auto(const std::string& marca, const std::string& modelo, const std::string& placa,
           int capacidadPasajeros)
    : Vehiculo(marca, modelo, placa), capacidadPasajeros(capacidadPasajeros) {}

int Auto::getCapacidadPasajeros() const { return capacidadPasajeros; }

void Auto::mostrarInformacion() const {
    std::cout << "[Auto] ";
    Vehiculo::mostrarInformacion();
    std::cout << " | Pasajeros: " << capacidadPasajeros << "\n";
}
