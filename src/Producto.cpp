#include "Producto.h"
#include <iostream>

Producto::Producto(std::string nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock) {}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
void Producto::setStock(int nuevoStock) { stock = nuevoStock; }

void Producto::mostrarInfo() const {
    std::cout << "Producto: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << "\n";
}

