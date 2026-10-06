#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include <string>
#include <vector>
#include "Vehiculo.h"

class SistemaAlquiler {
private:
    std::vector<Vehiculo*> vehiculos;

public:
    SistemaAlquiler() = default;
    ~SistemaAlquiler();
    SistemaAlquiler(const SistemaAlquiler&) = delete;
    SistemaAlquiler& operator=(const SistemaAlquiler&) = delete;

    void registrarVehiculo(Vehiculo* vehiculo);
    bool alquilarVehiculo(const std::string& placa);
    bool devolverVehiculo(const std::string& placa);
    void mostrarDisponibles() const;
};

#endif
