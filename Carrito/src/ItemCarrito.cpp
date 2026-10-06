#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(Producto* producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

Producto* ItemCarrito::getProducto() const { return producto; }
int ItemCarrito::getCantidad() const { return cantidad; }

void ItemCarrito::aumentar(int cantidad) { this->cantidad += cantidad; }

double ItemCarrito::subtotal() const {
    return producto->getPrecio() * cantidad;
}
