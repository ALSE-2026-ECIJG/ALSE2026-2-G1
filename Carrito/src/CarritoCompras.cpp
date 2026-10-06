#include "CarritoCompras.h"
#include <iostream>
#include <iomanip>

bool CarritoCompras::agregarProducto(Producto& producto, int cantidad) {
    if (cantidad <= 0) {
        return false;
    }
    for (ItemCarrito& item : items) {
        if (item.getProducto()->getNombre() == producto.getNombre()) {
            if (item.getCantidad() + cantidad > producto.getStock()) {
                return false;
            }
            item.aumentar(cantidad);
            return true;
        }
    }
    if (cantidad > producto.getStock()) {
        return false;
    }
    items.push_back(ItemCarrito(&producto, cantidad));
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
    for (const ItemCarrito& item : items) {
        total += item.subtotal();
    }
    return total;
}

void CarritoCompras::mostrar() const {
    std::cout << "--- Carrito ---" << std::endl;
    if (items.empty()) {
        std::cout << "El carrito esta vacio." << std::endl;
        return;
    }
    for (const ItemCarrito& item : items) {
        std::cout << item.getProducto()->getNombre()
                  << " x" << item.getCantidad()
                  << " = $" << std::fixed << std::setprecision(2)
                  << item.subtotal() << std::endl;
    }
    std::cout << "TOTAL: $" << std::fixed << std::setprecision(2)
              << calcularTotal() << std::endl;
}

bool CarritoCompras::finalizarCompra(Usuario& usuario) {
    if (items.empty()) {
        return false;
    }
    double total = calcularTotal();
    for (ItemCarrito& item : items) {
        item.getProducto()->reducirStock(item.getCantidad());
    }
    usuario.agregarCompra(total);
    items.clear();
    return true;
}
