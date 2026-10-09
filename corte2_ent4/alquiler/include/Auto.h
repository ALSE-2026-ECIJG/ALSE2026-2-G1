#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(const std::string& marca,
         const std::string& modelo,
         const std::string& placa,
         int capacidadPasajeros);

    int getCapacidadPasajeros() const;

    void mostrarInformacion() const override;
    std::string getTipo() const override;
};

#endif // AUTO_H
