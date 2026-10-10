#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include <vector>
#include <memory>
#include "Vehiculo.h"

class SistemaAlquiler {
private:
    std::vector<std::shared_ptr<Vehiculo>> vehiculos;

public:
    void registrarVehiculo(std::shared_ptr<Vehiculo> vehiculo);
    void alquilarVehiculo(const std::string& placa);
    void devolverVehiculo(const std::string& placa);
    void mostrarVehiculosDisponibles() const;
};

#endif // SISTEMA_ALQUILER_H

