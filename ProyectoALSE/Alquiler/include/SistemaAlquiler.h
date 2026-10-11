#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include <string>
#include <vector>
#include "Vehiculo.h"

/**
 * @class SistemaAlquiler
 * @brief Gestiona el registro, alquiler y devolución de vehículos.
 *
 * Guarda autos y bicicletas como punteros a Vehiculo (polimorfismo).
 * El sistema es dueño de los vehículos y los libera en su destructor.
 */
class SistemaAlquiler {
private:
    std::vector<Vehiculo*> vehiculos;  ///< Vehículos registrados

    /**
     * @brief Busca un vehículo por placa.
     * @param placa Placa a buscar
     * @return Puntero al vehículo o nullptr si no existe
     */
    Vehiculo* buscar(const std::string& placa) const;

public:
    /** @brief Destructor: libera la memoria de todos los vehículos. */
    ~SistemaAlquiler();

    /**
     * @brief Registra un vehículo (el sistema se encarga de borrarlo).
     * @param vehiculo Vehículo creado con new
     * @return true si se registró, false si ya existía esa placa
     */
    bool registrarVehiculo(Vehiculo* vehiculo);

    /**
     * @brief Alquila un vehículo.
     * @param placa Placa del vehículo
     * @return true si se alquiló, false si no existe o ya estaba alquilado
     */
    bool alquilar(const std::string& placa);

    /**
     * @brief Devuelve un vehículo alquilado.
     * @param placa Placa del vehículo
     * @return true si se devolvió, false si no existe o no estaba alquilado
     */
    bool devolver(const std::string& placa);

    /** @brief Muestra los vehículos disponibles. */
    void mostrarDisponibles() const;
};

#endif
