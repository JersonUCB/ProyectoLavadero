#pragma once
#include <iostream>
#include <vector>
#include "Trabajador.h"
#include "Vehiculo.h"
#include "Cliente.h"

using namespace std;

class Lavado
{
private:
	string tipo;
	string descripcion;
	Vehiculo* vehiculo;
	Cliente* cliente;
	Trabajador* trabajador;

	
	double costoLavado;

public:
	Lavado(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, string tipo, double costoLavado);
	~Lavado();

	void mostrar();
	double getCostoLavado();
};



