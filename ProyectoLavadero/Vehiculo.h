#pragma once
#include <string>
#include <iostream>
using namespace std;
class Vehiculo
{
protected:
    string placa;
    string marca;
    string modelo;
    int anio;
    string estado; //en espera o lavado

public:

    Vehiculo(string placa, string marca, string modelo, int anio, string estado);
    ~Vehiculo();

    virtual string getEstado() = 0;
    virtual string getPlaca() = 0;
    virtual string getModelo() = 0;
    virtual void setEstado(string newEstado) = 0;
    virtual void mostrar();   //El virtual llama a las clases hija cuando desde alquiler llamemos a vehiculo


    virtual double calcularCosto() = 0; // M�todo virtual puro
};

