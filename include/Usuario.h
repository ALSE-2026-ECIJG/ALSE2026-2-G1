#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include "CarritoCompras.h"

class Usuario {
private:
    std::string nombreUsuario;
    std::vector<CarritoCompras> historialCompras;

public:
    Usuario(std::string nombreUsuario);

    std::string getNombreUsuario() const;
    void agregarAlHistorial(const CarritoCompras& carrito);
    void mostrarHistorial() const;
};

#endif // USUARIO_H

