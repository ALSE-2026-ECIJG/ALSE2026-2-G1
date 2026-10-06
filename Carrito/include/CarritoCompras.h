#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include <string>
#include <vector>
#include "ItemCarrito.h"
#include "Usuario.h"

class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    bool agregarProducto(Producto& producto, int cantidad);
    bool eliminarProducto(const std::string& nombre);
    double calcularTotal() const;
    void mostrar() const;
    bool finalizarCompra(Usuario& usuario);
};

#endif
