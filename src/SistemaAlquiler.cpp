#include "SistemaAlquiler.h"
#include <iostream>

void SistemaAlquiler::registrarVehiculo(std::shared_ptr<Vehiculo> vehiculo) {
    vehiculos.push_back(vehiculo);
    std::cout << "Vehículo registrado correctamente.\n";
}

void SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            if (v->isDisponible()) {
                v->setDisponible(false);
                std::cout << "¡Vehículo alquilado con éxito!\n";
            } else {
                std::cout << "El vehículo ya se encuentra alquilado.\n";
            }
            return;
        }
    }
    std::cout << "No se encontró ningún vehículo con la placa: " << placa << "\n";
}

void SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            if (!v->isDisponible()) {
                v->setDisponible(true);
                std::cout << "¡Vehículo devuelto con éxito!\n";
            } else {
                std::cout << "Este vehículo ya estaba disponible en el sistema.\n";
            }
            return;
        }
    }
    std::cout << "No se encontró ningún vehículo con la placa: " << placa << "\n";
}

void SistemaAlquiler::mostrarVehiculosDisponibles() const {
    std::cout << "\n--- Vehículos Disponibles ---\n";
    bool hay = false;
    for (const auto& v : vehiculos) {
        if (v->isDisponible()) {
            v->mostrarInformacion();
            hay = true;
        }
    }
    if (!hay) {
        std::cout << "No hay vehículos disponibles en este momento.\n";
    }
}
