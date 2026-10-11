#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

/**
 * @class Bicicleta
 * @brief Vehículo de dos ruedas con un tipo (montaña, ruta, urbana).
 */
class Bicicleta : public Vehiculo {
private:
    std::string tipo;  ///< Tipo de bicicleta: montaña, ruta o urbana

public:
    /**
     * @brief Constructor.
     * @param marca Marca
     * @param modelo Modelo
     * @param placa Placa
     * @param tipo Tipo de bicicleta
     */
    Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa,
              const std::string& tipo);

    /** @brief Devuelve el tipo de bicicleta. */
    const std::string& getTipo() const;

    /** @brief Muestra la información de la bicicleta (incluye tipo). */
    void mostrarInformacion() const;
};

#endif
