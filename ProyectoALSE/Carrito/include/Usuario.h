#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "CarritoCompras.h"

/**
 * @class Usuario
 * @brief Cliente de la tienda con su historial de compras.
 */
class Usuario {
private:
    std::string nombre;                     ///< Nombre del usuario
    std::vector<CarritoCompras> historial;  ///< Compras realizadas

public:
    /**
     * @brief Constructor.
     * @param nombre Nombre del usuario
     */
    explicit Usuario(const std::string& nombre);

    /** @brief Devuelve el nombre. */
    const std::string& getNombre() const;

    /**
     * @brief Agrega una compra al historial.
     * @param compra Carrito ya finalizado
     */
    void agregarCompra(const CarritoCompras& compra);

    /** @brief Muestra todas las compras del historial. */
    void mostrarHistorial() const;
};

#endif
