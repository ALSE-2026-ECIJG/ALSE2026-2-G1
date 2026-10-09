#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, int id)
    : nombre(nombre), id(id) {}

std::string Usuario::getNombre() const { return nombre; }
int Usuario::getId() const { return id; }

CarritoCompras& Usuario::getCarrito() { return carrito; }
const CarritoCompras& Usuario::getCarrito() const { return carrito; }

void Usuario::agregarAlCarrito(const Producto& producto, int cantidad) {
    carrito.agregarProducto(producto, cantidad);
}

void Usuario::eliminarDelCarrito(const std::string& nombre) {
    carrito.eliminarProducto(nombre);
}

double Usuario::finalizarCompra() {
    double total = carrito.calcularTotal();
    if (total <= 0.0) {
        std::cout << "El carrito esta vacio. Nada que finalizar.\n";
        return 0.0;
    }
    historialCompras.push_back(total);
    carrito.vaciar();
    std::cout << "Compra finalizada por $" << total
              << ". Carrito vaciado.\n";
    return total;
}

const std::vector<double>& Usuario::getHistorial() const {
    return historialCompras;
}

double Usuario::totalGastado() const {
    double suma = 0.0;
    for (double t : historialCompras) suma += t;
    return suma;
}

void Usuario::mostrarHistorial() const {
    std::cout << "--- Historial de " << nombre << " ("
              << historialCompras.size() << " compras) ---\n";
    for (std::size_t i = 0; i < historialCompras.size(); ++i) {
        std::cout << "  Compra #" << (i + 1)
                  << ": $" << historialCompras[i] << "\n";
    }
    std::cout << "  Total gastado: $" << totalGastado() << "\n";
}
