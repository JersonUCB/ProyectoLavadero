
#pragma once
#include "Cliente.h"
#include "Trabajador.h"
#include "Lavado.h"
#include <vector>
#include "Vehiculo.h"
#include "Automovil.h"
#include "Moto.h"
#include "Camioneta.h"
#include "StaticLocalLoader.h"
#include "Consola.h"

class AdmiLavadero
{
private:
	vector<Vehiculo*> vehiculos;
	vector<Automovil*> automoviles;
	vector<Moto*> motos;
	vector<Camioneta*> camionetas;

	vector<Cliente*> clientes;
	vector<Trabajador*> trabajadores;
	vector<Lavado*> lavados;
	Consola consola;

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
	void showVehiclesInQueue();
	void searchWorkersByName(string nombre);
	void showCliente();
	void showEmployee();
	void showVehicle();
	void showClientePremium();
	void showLavadosInstanciados();
	void mostrarTrabajadoresPorSalarioAscendente();
	void buscarVehiculoPorPlaca(string placa);
	void buscarClientePorID(int id);
	void cambiarTipoLavadoAPremium();

public:
	AdmiLavadero();
	AdmiLavadero(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, double costoLavado);
	~AdmiLavadero();

	void run();

};