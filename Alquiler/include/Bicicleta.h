#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    std::string tipo;

public:
    Bicicleta(const std::string& marca,
              const std::string& modelo,
              const std::string& placa,
              const std::string& tipo);

    void mostrarInformacion() const override;
};

#endif
