#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"

/**
 * @class ItemCarrito
 * @brief Un producto dentro del carrito junto con la cantidad elegida.
 */
class ItemCarrito {
private:
    Producto* producto;  ///< Producto (el carrito no es dueño del producto)
    int cantidad;        ///< Unidades en el carrito

public:
    /**
     * @brief Constructor.
     * @param producto Puntero al producto
     * @param cantidad Unidades
     */
    ItemCarrito(Producto* producto, int cantidad);

    /** @brief Devuelve el producto. */
    Producto* getProducto() const;
    /** @brief Devuelve la cantidad. */
    int getCantidad() const;
    /**
     * @brief Cambia la cantidad.
     * @param cantidad Nueva cantidad
     */
    void setCantidad(int cantidad);

    /** @brief Calcula precio * cantidad. */
    double subtotal() const;
};

#endif
