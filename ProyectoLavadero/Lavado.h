#pragma once
#include <iostream>
#include <vector>
#include "Trabajador.h"
#include "Vehiculo.h"
#include "Cliente.h"

using namespace std;
enum TipoLavado
{
	estandar,
	medio,
	premium
};
class Lavado
{
private:

	Vehiculo* vehiculo;
	Cliente* cliente;
	Trabajador* trabajador;
	TipoLavado tipo;

	double costoLavado;

	static int cantidadInstancias;

public:
	Lavado(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, double costoLavado);
	~Lavado();

	string encode();
	void mostrar();
	double getCostoLavado();

	void setcostoLavado(int costo);
	void setTipoLavadoEstandar();
	void setTipoLavadoMedio();
	void setTipoLavadoPremium();
	
	static int getCantidadInstancias();
};

string tipoLavadoToString(TipoLavado tipo);