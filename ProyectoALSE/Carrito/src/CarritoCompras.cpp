#include "CarritoCompras.h"
#include <iostream>

bool CarritoCompras::agregarProducto(Producto* producto, int cantidad) {
    if (cantidad <= 0) return false;
    for (auto& item : items) {
        if (item.getProducto() == producto) {
            int nueva = item.getCantidad() + cantidad;
            if (nueva > producto->getStock()) return false;
            item.setCantidad(nueva);
            return true;
        }
    }
    if (cantidad > producto->getStock()) return false;
    items.emplace_back(producto, cantidad);
    return true;
}

bool CarritoCompras::eliminarProducto(const std::string& nombre) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProducto()->getNombre() == nombre) {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

double CarritoCompras::calcularTotal() const {
    double total = 0;
    for (const auto& item : items) total += item.subtotal();
    return total;
}

bool CarritoCompras::finalizarCompra() {
    for (const auto& item : items) {
        if (item.getCantidad() > item.getProducto()->getStock()) return false;
    }
    for (const auto& item : items) {
        item.getProducto()->reducirStock(item.getCantidad());
    }
    return true;
}

void CarritoCompras::vaciar() { items.clear(); }

void CarritoCompras::mostrar() const {
    for (const auto& item : items) {
        std::cout << item.getProducto()->getNombre() << " x" << item.getCantidad()
                  << " = $" << item.subtotal() << "\n";
    }
    std::cout << "TOTAL: $" << calcularTotal() << "\n";
}
