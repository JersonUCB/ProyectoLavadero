#include "Automovil.h"

Automovil::Automovil(string placa, string marca, string modelo, int anio, string estado, int numPuertas)
    : Vehiculo(placa, marca, modelo, anio, estado)
{
    this->numeroPuertas = numPuertas;
}

Automovil::~Automovil() {}

string Automovil::getEstado() {
    return estado;
}

string Automovil::getPlaca()
{
    return placa;
}

string Automovil::getModelo()
{
    return modelo;
}

void Automovil::setEstado(string newEstado)
{
    this->estado = newEstado;
}

double Automovil::calcularCosto() {
    double costoBase;

    // Determina el costo base según el tipo de lavado
    if (estado == "en espera") {
        costoBase = 20.0;
    }
    else {
        // El vehículo ya está lavado
        costoBase = 0.0;
    }

    // Aplica descuento del 10% si tiene 2 puertas
    if (numeroPuertas == 2) {
        return costoBase * 0.9;
    }

    return costoBase;
}

void Automovil::mostrar()
{
    Vehiculo::mostrar();
    cout << "Numero de puertas: " << numeroPuertas << endl;
}
