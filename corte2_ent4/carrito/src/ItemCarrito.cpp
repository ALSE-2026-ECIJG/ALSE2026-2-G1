#include "ItemCarrito.h"
#include <iostream>

ItemCarrito::ItemCarrito(const Producto& producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

Producto ItemCarrito::getProducto() const { return producto; }
int ItemCarrito::getCantidad() const { return cantidad; }

void ItemCarrito::setCantidad(int cantidad) { this->cantidad = cantidad; }

double ItemCarrito::subtotal() const {
    return producto.getPrecio() * cantidad;
}

void ItemCarrito::mostrarInfo() const {
    std::cout << "  " << producto.getNombre()
              << " x" << cantidad
              << " @ $" << producto.getPrecio()
              << " = $" << subtotal() << "\n";
}
