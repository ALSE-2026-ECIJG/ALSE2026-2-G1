#ifndef CARRITO_COMPRAS_H
#define CARRITO_COMPRAS_H

#include <vector>
#include "ItemCarrito.h"

class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    void agregarProducto(Producto producto, int cantidad);
    void eliminarProducto(const std::string& nombreProducto);
    double calcularTotal() const;
    void mostrarCarrito() const;
    void vaciarCarrito();
    bool estaVacio() const;
    std::vector<ItemCarrito> getItems() const;
};

#endif // CARRITO_COMPRAS_H

