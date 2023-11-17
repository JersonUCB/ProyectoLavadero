#pragma once

#include "Vehiculo.h"

class Camioneta : public Vehiculo {
private:
    bool cargaAbierta;

public:
    Camioneta(string placa, string marca, string modelo, int anio, string estado, bool cargaAbierta);
    ~Camioneta();

    string getEstado() override;
    string getPlaca() override;
    string  getModelo() override;
    void setEstado(string newEstado) override;
    double calcularCosto() override;
    void mostrar() override;
};

