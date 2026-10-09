#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    std::string tipo; // montaña, ruta, urbana

public:
    Bicicleta(const std::string& marca,
              const std::string& modelo,
              const std::string& placa,
              const std::string& tipo);

    std::string getTipoBicicleta() const;

    void mostrarInformacion() const override;
    std::string getTipo() const override; // devuelve "Bicicleta"
};

#endif // BICICLETA_H
