
#pragma once
#include "Cliente.h"
#include "Trabajador.h"
#include "Lavado.h"
#include <vector>
#include "Vehiculo.h"
#include "Automovil.h"
#include "Moto.h"
#include "Camioneta.h"

class AdmiLavadero
{
private:
	vector<Vehiculo*> vehiculos;
	vector<Cliente*> clientes;
	vector<Trabajador*> trabajadores;
	vector<Lavado*> lavados;

	Vehiculo* vehiculo;
	Cliente* cliente;
	Trabajador* trabajador;
	double costoLavado;

	void showMenu();
	void registerNewVehicle();
	void registerNewEmployee();
	void registerNewClient();
	void washVehicle();
	void showWashedVehicles();
	void getTotalProfit();


public:
	AdmiLavadero();
	AdmiLavadero(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, double costoLavado);
	~AdmiLavadero();

	void run();

};