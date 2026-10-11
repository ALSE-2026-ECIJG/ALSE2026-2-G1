#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

/**
 * @class Auto
 * @brief Vehículo de cuatro ruedas con capacidad de pasajeros.
 */
class Auto : public Vehiculo {
private:
    int capacidadPasajeros;  ///< Número máximo de pasajeros

public:
    /**
     * @brief Constructor.
     * @param marca Marca
     * @param modelo Modelo
     * @param placa Placa
     * @param capacidadPasajeros Número de pasajeros
     */
    Auto(const std::string& marca, const std::string& modelo, const std::string& placa,
         int capacidadPasajeros);

    /** @brief Devuelve la capacidad de pasajeros. */
    int getCapacidadPasajeros() const;

    /** @brief Muestra la información del auto (incluye pasajeros). */
    void mostrarInformacion() const;
};

#endif
