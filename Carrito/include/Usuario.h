#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Usuario {
private:
    std::string nombre;
    std::vector<double> historial;

public:
    explicit Usuario(const std::string& nombre);

    std::string getNombre() const;
    void agregarCompra(double total);
    void mostrarHistorial() const;
};

#endif
