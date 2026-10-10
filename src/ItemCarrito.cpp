#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(Producto producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

Producto ItemCarrito::getProducto() const { return producto; }
int ItemCarrito::getCantidad() const { return cantidad; }
void ItemCarrito::setCantidad(int c) { cantidad = c; }

double ItemCarrito::calcularSubtotal() const {
    return producto.getPrecio() * cantidad;
}

