#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include <vector>
#include <memory>
#include <string>
#include "Vehiculo.h"

class SistemaAlquiler {
private:
    std::vector<std::shared_ptr<Vehiculo>> vehiculos;

public:
    // Registrar un vehiculo (toma propiedad via shared_ptr)
    void registrarVehiculo(std::shared_ptr<Vehiculo> v);

    // Alquilar / devolver por placa
    bool alquilarVehiculo(const std::string& placa);
    bool devolverVehiculo(const std::string& placa);

    // Listados
    void mostrarTodos() const;
    void mostrarDisponibles() const;

    std::size_t totalVehiculos() const;
};

#endif // SISTEMA_ALQUILER_H
