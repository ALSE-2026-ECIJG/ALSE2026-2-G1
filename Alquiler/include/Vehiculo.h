#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool alquilado;

public:
    Vehiculo(const std::string& marca,
             const std::string& modelo,
             const std::string& placa);
    virtual ~Vehiculo() = default;

    std::string getPlaca() const;
    bool estaDisponible() const;
    void setAlquilado(bool valor);

    virtual void mostrarInformacion() const;
};

#endif
