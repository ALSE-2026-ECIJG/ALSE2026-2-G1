#ifndef ITEM_CARRITO_H
#define ITEM_CARRITO_H

#include "Producto.h"

class ItemCarrito {
private:
    Producto producto;
    int cantidad;

public:
    ItemCarrito(const Producto& producto, int cantidad);

    Producto getProducto() const;
    int getCantidad() const;

    void setCantidad(int cantidad);
    double subtotal() const;

    void mostrarInfo() const;
};

#endif // ITEM_CARRITO_H
