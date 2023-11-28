
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

	void RegistrarVehiculo();
	void RegistrarEmpleado();
	void RegistrarNuevoCliente();
	void LavarVehiculo();
	void MostrarVehiculosLavados();
	void ObtenerBeneficioTotal();
	void MostrarVehiculosEnEspera();
	void BuscarTrabajadorPorNombre(string nombre);
	void MostrarLavadosInstaciados();
	void mostrarTrabajadoresPorSalarioAscendente();
	void MostrarClientesPremium();
	void buscarVehiculoPorPlaca(string placa);
	void buscarClientePorID(int id);
	void cambiarTipoLavadoAPremium();
	void MostrarCliente();
	void MostrarEmpleado();
	void MostrarVehiculo();

public:
	AdmiLavadero();
	AdmiLavadero(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, double costoLavado);
	~AdmiLavadero();

	void run();

};