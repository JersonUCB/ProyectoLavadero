#pragma once
#include "Trabajador.h"
#include "Cliente.h"
#include <iostream>
using namespace std;

class Consola
{
public:
	int tipoVehiculo();
	int numeroPuertas();
	bool motoElectrica();
	bool cajaCubierta();
	void showMenu();
	Trabajador* showRegisterNewEmployee();
	Cliente* showRegisterNewClient();
};

