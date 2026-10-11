#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

/**
 * @class Vehiculo
 * @brief Clase base para los vehículos que se pueden alquilar.
 */
class Vehiculo {
private:
    std::string marca;   ///< Marca del vehículo
    std::string modelo;  ///< Modelo del vehículo
    std::string placa;   ///< Placa (identificador único)
    bool alquilado;      ///< true si está alquilado actualmente

public:
    /**
     * @brief Constructor. El vehículo se crea como no alquilado.
     * @param marca Marca
     * @param modelo Modelo
     * @param placa Placa
     */
    Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa);

    /** @brief Destructor virtual (necesario para el polimorfismo). */
    virtual ~Vehiculo() {}

    /** @brief Devuelve la marca. */
    const std::string& getMarca() const;
    /** @brief Devuelve el modelo. */
    const std::string& getModelo() const;
    /** @brief Devuelve la placa. */
    const std::string& getPlaca() const;
    /** @brief Indica si el vehículo está alquilado. */
    bool estaAlquilado() const;
    /**
     * @brief Cambia el estado de alquiler.
     * @param alquilado Nuevo estado
     */
    void setAlquilado(bool alquilado);

    /**
     * @brief Muestra la información del vehículo.
     * Las clases derivadas la pueden sobrescribir para agregar sus datos.
     */
    virtual void mostrarInformacion() const;
};

#endif
