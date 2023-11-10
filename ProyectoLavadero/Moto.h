#pragma once
#include "Vehiculo.h"

class Moto : public Vehiculo
{
private:
    bool esElectrica;

public:
    Moto(string placa, string marca, string modelo, int anio, string estado, bool electrica);
    ~Moto();

    string getEstado() override;
    string getPlaca() override;
    string  getModelo() override;
    void setEstado(string newEstado) override;
    double calcularCosto() override;
    void mostrar() override;
};