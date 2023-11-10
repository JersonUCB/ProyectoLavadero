#include "Moto.h"

Moto::Moto(string placa, string marca, string modelo, int anio, string estado, bool electrica)
    : Vehiculo(placa, marca, modelo, anio, estado)
{
    this->esElectrica = esElectrica;
}

Moto::~Moto() {}

string Moto::getEstado() {
    return estado;
}
string Moto::getPlaca()
{
    return placa;
}

string Moto::getModelo()
{
    return modelo;
}

void Moto::setEstado(string newEstado)
{
    this->estado = newEstado;
}
double Moto::calcularCosto() {
    double costoBase;

    if (estado == "en espera") {
        costoBase = 20.0;
    }
    else {
        costoBase = 0.0;
    }

    if (esElectrica) {
        return costoBase * 1.1;
    }

    return costoBase;
}

void Moto::mostrar() {
    Vehiculo::mostrar();
    cout << "Es eléctrica: " << (esElectrica ? "Sí" : "No") << endl;
}