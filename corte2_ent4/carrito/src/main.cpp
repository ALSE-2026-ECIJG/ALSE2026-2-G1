#include <iostream>
#include "Producto.h"
#include "ItemCarrito.h"
#include "CarritoCompras.h"
#include "Usuario.h"

int main() {
    Producto p1("Laptop",  1500.00, 5);
    Producto p2("Mouse",     25.50, 20);
    Producto p3("Teclado",   45.00, 10);
    Producto p4("Monitor",  320.00, 3);

    std::cout << "=== Catalogo ===\n";
    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();
    p4.mostrarInfo();

    Usuario user("Samuel", 2024001);

    std::cout << "\n=== Agregando productos al carrito ===\n";
    user.agregarAlCarrito(p1, 1);
    user.agregarAlCarrito(p2, 2);
    user.agregarAlCarrito(p3, 1);

    std::cout << "\n=== Contenido actual ===\n";
    user.getCarrito().mostrarContenido();

    std::cout << "\n=== Intentar agregar mas de lo que hay en stock ===\n";
    user.agregarAlCarrito(p4, 5);

    std::cout << "\n=== Agregar mismo producto (suma cantidad) ===\n";
    user.agregarAlCarrito(p2, 1);

    std::cout << "\n=== Contenido actualizado ===\n";
    user.getCarrito().mostrarContenido();

    std::cout << "\n=== Eliminar un producto ===\n";
    user.eliminarDelCarrito("Teclado");

    std::cout << "\n=== Contenido final del carrito ===\n";
    user.getCarrito().mostrarContenido();

    std::cout << "\n=== Finalizar compra #1 ===\n";
    user.finalizarCompra();

    std::cout << "\n=== Segunda compra: solo un monitor ===\n";
    user.agregarAlCarrito(p4, 1);
    user.getCarrito().mostrarContenido();
    user.finalizarCompra();

    std::cout << "\n=== Historial ===\n";
    user.mostrarHistorial();

    return 0;
}
