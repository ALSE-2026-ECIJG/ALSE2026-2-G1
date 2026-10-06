#include "SistemaAlquiler.h"
#include <iostream>

SistemaAlquiler::~SistemaAlquiler() {
    for (Vehiculo* v : vehiculos) {
        delete v;
    }
}

void SistemaAlquiler::registrarVehiculo(Vehiculo* vehiculo) {
    vehiculos.push_back(vehiculo);
}

bool SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    for (Vehiculo* v : vehiculos) {
        if (v->getPlaca() == placa && v->estaDisponible()) {
            v->setAlquilado(true);
            return true;
        }
    }
    return false;
}

bool SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    for (Vehiculo* v : vehiculos) {
        if (v->getPlaca() == placa && !v->estaDisponible()) {
            v->setAlquilado(false);
            return true;
        }
    }
    return false;
}

void SistemaAlquiler::mostrarDisponibles() const {
    std::cout << "--- Vehiculos disponibles ---" << std::endl;
    bool hayAlguno = false;
    for (const Vehiculo* v : vehiculos) {
        if (v->estaDisponible()) {
            v->mostrarInformacion();
            hayAlguno = true;
        }
    }
    if (!hayAlguno) {
        std::cout << "No hay vehiculos disponibles." << std::endl;
    }
}
