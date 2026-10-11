#include "SistemaAlquiler.h"
#include <iostream>

SistemaAlquiler::~SistemaAlquiler() {
    for (size_t i = 0; i < vehiculos.size(); i++) {
        delete vehiculos[i];
    }
}

Vehiculo* SistemaAlquiler::buscar(const std::string& placa) const {
    for (size_t i = 0; i < vehiculos.size(); i++) {
        if (vehiculos[i]->getPlaca() == placa) return vehiculos[i];
    }
    return nullptr;
}

bool SistemaAlquiler::registrarVehiculo(Vehiculo* vehiculo) {
    if (buscar(vehiculo->getPlaca()) != nullptr) {
        delete vehiculo;  // ya existía esa placa, se descarta
        return false;
    }
    vehiculos.push_back(vehiculo);
    return true;
}

bool SistemaAlquiler::alquilar(const std::string& placa) {
    Vehiculo* v = buscar(placa);
    if (v == nullptr || v->estaAlquilado()) return false;
    v->setAlquilado(true);
    return true;
}

bool SistemaAlquiler::devolver(const std::string& placa) {
    Vehiculo* v = buscar(placa);
    if (v == nullptr || !v->estaAlquilado()) return false;
    v->setAlquilado(false);
    return true;
}

void SistemaAlquiler::mostrarDisponibles() const {
    for (size_t i = 0; i < vehiculos.size(); i++) {
        if (!vehiculos[i]->estaAlquilado()) vehiculos[i]->mostrarInformacion();
    }
}
