#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombreUsuario) : nombreUsuario(nombreUsuario) {}

std::string Usuario::getNombreUsuario() const { return nombreUsuario; }

void Usuario::agregarAlHistorial(const CarritoCompras& carrito) {
    if (!carrito.estaVacio()) {
        historialCompras.push_back(carrito);
        std::cout << "Compra registrada exitosamente en el historial del usuario: " << nombreUsuario << "\n";
    } else {
        std::cout << "No se puede registrar un carrito vacío en el historial.\n";
    }
}

void Usuario::mostrarHistorial() const {
    std::cout << "\n=== HISTORIAL DE COMPRAS DE " << nombreUsuario << " ===\n";
    if (historialCompras.empty()) {
        std::cout << "No hay compras registradas.\n";
        return;
    }
    int i = 1;
    for (const auto& carrito : historialCompras) {
        std::cout << "Compra #" << i++ << " (Total: $" << carrito.calcularTotal() << ")\n";
    }
}

