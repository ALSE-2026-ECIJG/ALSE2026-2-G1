#include "Producto.h"
#include <iostream>

Producto::Producto(const std::string& nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock) {}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

void Producto::setStock(int nuevoStock) { stock = nuevoStock; }

bool Producto::hayStock(int cantidad) const {
    return cantidad > 0 && cantidad <= stock;
}

void Producto::mostrarInfo() const {
    std::cout << "  " << nombre
              << " | Precio: $" << precio
              << " | Stock: " << stock << "\n";
}
