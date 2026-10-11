#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Producto de la tienda con nombre, precio y stock.
 */
class Producto {
private:
    std::string nombre;  ///< Nombre del producto
    double precio;       ///< Precio unitario
    int stock;           ///< Unidades disponibles

public:
    /**
     * @brief Constructor.
     * @param nombre Nombre del producto
     * @param precio Precio unitario
     * @param stock Unidades disponibles
     */
    Producto(const std::string& nombre, double precio, int stock);

    /** @brief Devuelve el nombre. */
    const std::string& getNombre() const;
    /** @brief Devuelve el precio unitario. */
    double getPrecio() const;
    /** @brief Devuelve el stock actual. */
    int getStock() const;

    /**
     * @brief Descuenta unidades del stock.
     * @param cantidad Unidades a descontar
     * @return true si había suficiente stock, false en caso contrario
     */
    bool reducirStock(int cantidad);
};

#endif
