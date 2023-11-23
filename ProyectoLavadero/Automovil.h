#pragma once
#include "Vehiculo.h"

class Automovil : public Vehiculo 
{
private:
    int numeroPuertas;

public:
    Automovil(string placa, string marca, string modelo, int anio, string estado, int numPuertas);
    ~Automovil();

    string getEstado() override;
    string getPlaca() override;
    string  getModelo() override;
    void setEstado(string newEstado) override;
    double calcularCosto() override;
    void mostrar() override;
};

