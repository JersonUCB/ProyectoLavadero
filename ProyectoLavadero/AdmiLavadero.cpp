#include "AdmiLavadero.h"
#include <algorithm>  // Para incluir la función sort

void AdmiLavadero::showMenu()
{
	int option;
	do {
		cout << "1. Registrar nuevo vehiculo" << endl;
		cout << "2. Lavar un vehiculo " << endl;
		cout << "3. Mostrar todos los datos de los vehiculos que se han lavado" << endl;
		cout << "4. Obtener el beneficio total" << endl;


		cout << "Digite una opcion: " << endl;
		cout << "0. Salir" << endl;
		cin >> option;

		switch (option)
		{
		case 1:
		{
			registerNewVehicle();
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			washVehicle();
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			showWashedVehicles();
			system("pause");
			system("cls");
			break;
		}


		case 4:
		{
			getTotalProfit();
			system("pause");
			system("cls");
			break;
		}

		default:
			break;
		}
	} while (option != 0);
}

AdmiLavadero::AdmiLavadero()
{
	this->vehiculo = nullptr;
	this->cliente = nullptr;
	this->trabajador = nullptr;
	this->costoLavado = 0.01;
}

AdmiLavadero::AdmiLavadero(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, double costoLavado)
{
	this->vehiculo = vehiculo;
	this->cliente = cliente;
	this->trabajador = trabajador;
	this->costoLavado = costoLavado;
}

AdmiLavadero::~AdmiLavadero()
{
	// Liberar la memoria de los vehículos
	for (auto* vehiculo : vehiculos)
	{
		delete vehiculo;
	}

	// Liberar la memoria de los trabajadores
	for (auto* trabajador : trabajadores)
	{
		delete trabajador;
	}

	// Liberar la memoria de los clientes
	for (auto* cliente : clientes)
	{
		delete cliente;
	}

	// Liberar la memoria de los alquileres
	for (auto* lavado : lavados)
	{
		delete lavado;
	}
}

void AdmiLavadero::run()
{
	showMenu();
}

void AdmiLavadero::registerNewVehicle() {
	string placa, marca, modelo, estado;
	int anio;

	cout << "Ingrese la placa del vehiculo: ";
	cin >> placa;
	cout << "Ingrese la marca del vehiculo: ";
	cin >> marca;
	cout << "Ingrese el modelo del vehiculo: ";
	cin >> modelo;
	cout << "Ingrese el anio del vehiculo: ";
	cin >> anio;

	int tipoVehiculo;
	cout << "Seleccione el tipo de vehiculo:" << endl;
	cout << "1. Automovil" << endl;
	cout << "2. Moto" << endl;
	cout << "3. Camioneta" << endl;
	cout << "Ingrese la opción: ";
	cin >> tipoVehiculo;

	Vehiculo* nuevoVehiculo = nullptr;

	switch (tipoVehiculo) {
	case 1:
	{
		int numPuertas;
		cout << "Ingrese el numero de puertas del automovil: ";
		cin >> numPuertas;
		nuevoVehiculo = new Automovil(placa, marca, modelo, anio, "en espera", numPuertas);
		break;
	}
		
	case 2:
		bool esElectrica;
		cout << "¿Es la moto electrica? (1 para Si / 0 para No): ";
		cin >> esElectrica;
		nuevoVehiculo = new Moto(placa, marca, modelo, anio, "en espera", esElectrica);
		break;
	case 3:
		bool cargaAbierta;
		cout << "¿Es la camioneta de carga abierta? (1 para Si / 0 para No): ";
		cin >> cargaAbierta;
		nuevoVehiculo = new Camioneta(placa, marca, modelo, anio, "en espera", cargaAbierta);
		break;
	default:
		cout << "Opcion no valida." << endl;
		return;
	}

	vehiculos.push_back(nuevoVehiculo);
	cout << "Vehiculo registrado con exito." << endl;
}

void AdmiLavadero::washVehicle() {
	string placa;
	cout << "Ingrese la placa del vehiculo a lavar: ";
	cin >> placa;

	auto it = find_if(vehiculos.begin(), vehiculos.end(),
		[placa](Vehiculo* v) { return v->getPlaca() == placa; });

	if (it != vehiculos.end()) {
		(*it)->setEstado("lavado");

		// Aquí deberías tener lógica para asignar un trabajador disponible.
		Trabajador* trabajadorAsignado = trabajadores[0];

		lavados.push_back(new Lavado(*it, cliente, trabajadorAsignado, "tipo_de_lavado", (*it)->calcularCosto()));

		cout << "Vehículo lavado con éxito." << endl;
	}
	else {
		cout << "Vehículo no encontrado." << endl;
	}
}

void AdmiLavadero::showWashedVehicles() {
	for (auto* lavado : lavados) {
		lavado->mostrar();
	}
}

void AdmiLavadero::getTotalProfit() {
	double beneficioTotal = 0;

	for (auto* lavado : lavados) {
		beneficioTotal += lavado->getCostoLavado();
	}

	double beneficioFinal = beneficioTotal * 0.65;

	cout << "El beneficio total es: $" << beneficioFinal << endl;
}