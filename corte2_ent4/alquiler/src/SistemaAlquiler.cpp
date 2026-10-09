#include "SistemaAlquiler.h"
#include <iostream>

void SistemaAlquiler::registrarVehiculo(std::shared_ptr<Vehiculo> v) {
    // Evitar placas duplicadas
    for (const auto& existente : vehiculos) {
        if (existente->getPlaca() == v->getPlaca()) {
            std::cout << "Ya existe un vehiculo con placa "
                      << v->getPlaca() << "\n";
            return;
        }
    }
    vehiculos.push_back(v);
    std::cout << "Registrado: " << v->getTipo()
              << " " << v->getMarca() << " " << v->getModelo()
              << " (placa " << v->getPlaca() << ")\n";
}

bool SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            if (!v->isDisponible()) {
                std::cout << "El vehiculo con placa " << placa
                          << " ya esta alquilado.\n";
                return false;
            }
            v->setDisponible(false);
            std::cout << "Alquilado: " << v->getTipo()
                      << " " << v->getMarca() << " " << v->getModelo()
                      << " (placa " << placa << ")\n";
            return true;
        }
    }
    std::cout << "No se encontro vehiculo con placa " << placa << "\n";
    return false;
}

bool SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            if (v->isDisponible()) {
                std::cout << "El vehiculo con placa " << placa
                          << " no estaba alquilado.\n";
                return false;
            }
            v->setDisponible(true);
            std::cout << "Devuelto: " << v->getTipo()
                      << " " << v->getMarca() << " " << v->getModelo()
                      << " (placa " << placa << ")\n";
            return true;
        }
    }
    std::cout << "No se encontro vehiculo con placa " << placa << "\n";
    return false;
}

void SistemaAlquiler::mostrarTodos() const {
    std::cout << "--- Todos los vehiculos (" << vehiculos.size() << ") ---\n";
    for (const auto& v : vehiculos) v->mostrarInformacion();
}

void SistemaAlquiler::mostrarDisponibles() const {
    std::cout << "--- Vehiculos disponibles ---\n";
    for (const auto& v : vehiculos) {
        if (v->isDisponible()) v->mostrarInformacion();
    }
}

std::size_t SistemaAlquiler::totalVehiculos() const {
    return vehiculos.size();
}
