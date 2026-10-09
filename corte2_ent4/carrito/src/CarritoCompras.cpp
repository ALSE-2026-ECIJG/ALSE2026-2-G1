#include "CarritoCompras.h"
#include <iostream>
#include <algorithm>

bool CarritoCompras::agregarProducto(const Producto& producto, int cantidad) {
    if (!producto.hayStock(cantidad)) {
        std::cout << "Stock insuficiente de \"" << producto.getNombre()
                  << "\" (solicitado: " << cantidad
                  << ", disponible: " << producto.getStock() << ")\n";
        return false;
    }

    for (auto& item : items) {
        if (item.getProducto().getNombre() == producto.getNombre()) {
            int nuevaCantidad = item.getCantidad() + cantidad;
            if (!producto.hayStock(nuevaCantidad)) {
                std::cout << "No se puede agregar mas de \""
                          << producto.getNombre() << "\" (stock: "
                          << producto.getStock() << ")\n";
                return false;
            }
            item.setCantidad(nuevaCantidad);
            std::cout << "Actualizado en carrito: "
                      << producto.getNombre() << " x" << nuevaCantidad << "\n";
            return true;
        }
    }

    items.emplace_back(producto, cantidad);
    std::cout << "Agregado al carrito: "
              << producto.getNombre() << " x" << cantidad << "\n";
    return true;
}

bool CarritoCompras::eliminarProducto(const std::string& nombre) {
    auto it = std::remove_if(items.begin(), items.end(),
        [&nombre](const ItemCarrito& i){
            return i.getProducto().getNombre() == nombre;
        });
    if (it == items.end()) return false;
    items.erase(it, items.end());
    std::cout << "Eliminado del carrito: " << nombre << "\n";
    return true;
}

double CarritoCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : items) total += item.subtotal();
    return total;
}

void CarritoCompras::vaciar() { items.clear(); }

void CarritoCompras::mostrarContenido() const {
    if (items.empty()) {
        std::cout << "  (carrito vacio)\n";
        return;
    }
    std::cout << "--- Contenido del carrito (" << items.size()
              << " items) ---\n";
    for (const auto& item : items) item.mostrarInfo();
    std::cout << "  Total: $" << calcularTotal() << "\n";
}

std::size_t CarritoCompras::totalItems() const { return items.size(); }
