#include "CarritoCompras.h"
#include <iostream>
#include <algorithm>

void CarritoCompras::agregarProducto(Producto producto, int cantidad) {
    for (auto& item : items) {
        if (item.getProducto().getNombre() == producto.getNombre()) {
            item.setCantidad(item.getCantidad() + cantidad);
            std::cout << "Cantidad actualizada en el carrito.\n";
            return;
        }
    }
    items.push_back(ItemCarrito(producto, cantidad));
    std::cout << "Producto agregado al carrito de compras.\n";
}

void CarritoCompras::eliminarProducto(const std::string& nombreProducto) {
    auto it = std::remove_if(items.begin(), items.end(), [&nombreProducto](const ItemCarrito& item) {
        return item.getProducto().getNombre() == nombreProducto;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "Producto eliminado del carrito.\n";
    } else {
        std::cout << "El producto no se encontraba en el carrito.\n";
    }
}

double CarritoCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.calcularSubtotal();
    }
    return total;
}

void CarritoCompras::mostrarCarrito() const {
    std::cout << "\n--- CARRITO DE COMPRAS ---\n";
    if (items.empty()) {
        std::cout << "El carrito está vacío.\n";
        return;
    }
    for (const auto& item : items) {
        std::cout << "- " << item.getProducto().getNombre() 
                  << " | Cantidad: " << item.getCantidad() 
                  << " | Subtotal: $" << item.calcularSubtotal() << "\n";
    }
    std::cout << "TOTAL A PAGAR: $" << calcularTotal() << "\n";
}

void CarritoCompras::vaciarCarrito() {
    items.clear();
}

bool CarritoCompras::estaVacio() const {
    return items.empty();
}

std::vector<ItemCarrito> CarritoCompras::getItems() const {
    return items;
}

