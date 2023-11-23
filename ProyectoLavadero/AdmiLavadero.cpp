#include "AdmiLavadero.h"
//#include "AdmiLavadero.h"
#include <algorithm>  // Para incluir la función sort

void AdmiLavadero::showMenu()
{
	int option;
	do {
		consola.showMenu();
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
			registerNewEmployee();
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			registerNewClient();
			system("pause");
			system("cls");
			break;
		}


		case 4:
		{
			washVehicle();
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			showWashedVehicles();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
		    getTotalProfit();
			system("pause");
			system("cls");
			break;
		}
		case 16:
		{
			showCliente();
			system("pause");
			system("cls");
			break;
		}
		case 17:
		{
			showEmployee();
			system("pause");
			system("cls");
			break;
		}
		case 18:
		{
			showVehicle();
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
	//StaticLocalLoader
	trabajadores = datos.vectorTrabajador();
	clientes = datos.vectorCliente();
	vehiculos = datos.vectorVehiculo();

	automoviles = datos.vectorAutomovil();
	motos = datos.vectorMoto();
	camionetas = datos.vectorCamioneta();

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

	Vehiculo* nuevoVehiculo = nullptr;

	int opcion = consola.tipoVehiculo();
	switch (opcion) {
	case 1:
	{
		int numPuertas=consola.numeroPuertas();
		nuevoVehiculo = new Automovil(placa, marca, modelo, anio, "en espera", numPuertas);
		this->automoviles.push_back(new Automovil(placa, marca, modelo, anio, "en espera", numPuertas));
		break;
	}

	case 2:
		bool esElectrica;
		esElectrica= consola.motoElectrica();
		nuevoVehiculo = new Moto(placa, marca, modelo, anio, "en espera", esElectrica);
		this->motos.push_back(new Moto(placa, marca, modelo, anio, "en espera", esElectrica));
		break;
	case 3:
		bool cargaAbierta;
		cargaAbierta= consola.cajaCubierta();
		nuevoVehiculo = new Camioneta(placa, marca, modelo, anio, "en espera", cargaAbierta);
		this->camionetas.push_back(new Camioneta(placa, marca, modelo, anio, "en espera", cargaAbierta));
		break;
	default:
		cout << "Opcion no valida." << endl;
		return;
	}

	vehiculos.push_back(nuevoVehiculo);
	cout << "Vehiculo registrado con exito." << endl;
}

void AdmiLavadero::registerNewEmployee()
{
	Trabajador* trabajador;
	trabajador = consola.showRegisterNewEmployee();
	trabajadores.push_back(trabajador);
	cout << "El trabajador ha sido registrado" << endl;
}

void AdmiLavadero::registerNewClient()
{
	Cliente* cliente;
	cliente = consola.showRegisterNewClient();
	clientes.push_back(cliente);
	cout << "El Cliente ha sido registrado" << endl;
}


void AdmiLavadero::washVehicle() {
	string placa;
	cout << "Ingrese la placa del vehiculo a lavar: ";
	cin >> placa;

	auto it = find_if(vehiculos.begin(), vehiculos.end(),
		[placa](Vehiculo* v) { return v->getPlaca() == placa; });

	if (it != vehiculos.end()) {
		(*it)->setEstado("lavado");


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

void AdmiLavadero::showCliente()
{
	for (Cliente* var : clientes)
	{
		var->mostrar();
	}
}

void AdmiLavadero::showEmployee()
{
	for (Trabajador* var : trabajadores)
	{
		var->mostrar();
	}
}

void AdmiLavadero::showVehicle()
{
	for (Vehiculo* var : vehiculos)
	{
		var->mostrar();
	}
}
