#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include <string>
#include <vector>
#include "ItemCarrito.h"

/**
 * @class CarritoCompras
 * @brief Carrito de compras: agrega, elimina y calcula el total.
 */
class CarritoCompras {
private:
    std::vector<ItemCarrito> items;  ///< Productos en el carrito

public:
    /**
     * @brief Agrega un producto al carrito (si ya está, suma la cantidad).
     * @param producto Producto a agregar
     * @param cantidad Unidades a agregar
     * @return true si se agregó, false si no hay stock suficiente
     */
    bool agregarProducto(Producto* producto, int cantidad);

    /**
     * @brief Elimina un producto del carrito por nombre.
     * @param nombre Nombre del producto
     * @return true si se eliminó, false si no estaba en el carrito
     */
    bool eliminarProducto(const std::string& nombre);

    /** @brief Calcula el total de la compra. */
    double calcularTotal() const;

    /**
     * @brief Finaliza la compra: descuenta del stock cada producto del carrito.
     * @return true si todo se descontó, false si algún producto ya no tiene stock
     */
    bool finalizarCompra();

    /** @brief Vacía el carrito. */
    void vaciar();

    /** @brief Muestra el contenido del carrito y el total. */
    void mostrar() const;
};

#endif
