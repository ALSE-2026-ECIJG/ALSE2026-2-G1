#include <iostream>
#include "CarritoCompras.h"
#include "Usuario.h"

int main() {
    Producto camiseta("Camiseta", 25000, 10);
    Producto zapatos("Zapatos", 120000, 3);
    Producto gorra("Gorra", 18000, 5);

    Usuario usuario("Santiago");
    CarritoCompras carrito;

    carrito.agregarProducto(camiseta, 2);
    carrito.agregarProducto(zapatos, 1);
    carrito.agregarProducto(gorra, 1);
    carrito.mostrar();

    std::cout << "\nIntentando agregar 5 zapatos (solo hay 3)..." << std::endl;
    if (!carrito.agregarProducto(zapatos, 5)) {
        std::cout << "No se pudo: stock insuficiente." << std::endl;
    }

    std::cout << "\nEliminando la gorra..." << std::endl;
    carrito.eliminarProducto("Gorra");
    carrito.mostrar();

    std::cout << "\nFinalizando compra..." << std::endl;
    carrito.finalizarCompra(usuario);
    carrito.mostrar();
    std::cout << "Stock de camisetas ahora: " << camiseta.getStock() << std::endl;

    std::cout << std::endl;
    usuario.mostrarHistorial();

    return 0;
}
