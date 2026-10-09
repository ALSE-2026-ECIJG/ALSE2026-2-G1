#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H

#include <vector>
#include "ItemCarrito.h"

class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    bool agregarProducto(const Producto& producto, int cantidad);
    bool eliminarProducto(const std::string& nombre);

    double calcularTotal() const;
    void vaciar();

    void mostrarContenido() const;
    std::size_t totalItems() const;
};

#endif // CARRITO_COMPRAS_H
