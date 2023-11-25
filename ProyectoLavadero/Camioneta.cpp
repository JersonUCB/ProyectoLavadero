#include "Camioneta.h"


Camioneta::Camioneta(string placa, string marca, string modelo, int anio, string estado, bool cargaAbierta)
    : Vehiculo(placa, marca, modelo, anio, estado)
{
    this->cargaAbierta = cargaAbierta;
}

Camioneta::~Camioneta() {}

string Camioneta::getPlaca()
{
    return placa;
}
string Camioneta::getEstado() {
    return estado;
}

string Camioneta::getModelo()
{
    return modelo;
}

void Camioneta::setEstado(string newEstado)
{
    this->estado = newEstado;
}
double Camioneta::calcularCosto() {
    double costoBase;

    if (estado == "en espera") {
        costoBase = 20.0;
    }
    else {
        costoBase = 0.0;
    }

    if (cargaAbierta) {
        return costoBase * 1.08;
    }

    return costoBase;
}

void Camioneta::mostrar() {
    Vehiculo::mostrar();
    cout << "Carga abierta: " << (cargaAbierta ? "Si" : "No") << endl;
}