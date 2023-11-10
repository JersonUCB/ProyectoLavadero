#pragma once
#include <iostream>
#include <vector>
#include "Trabajador.h"

using namespace std;

class Lavado
{
private:
	string tipo;
	string descripcion;
	//vector<Vehiculo*> vehiculos;
	vector<Trabajador*> trabajadores;
	double costoTotal;

public:
	//Lavado(string tipo,string descripcion,vector<Vehiculo*> vehiculos,vector<Trabajador*> trabajadores,double costoTotal);
	~Lavado();

};



