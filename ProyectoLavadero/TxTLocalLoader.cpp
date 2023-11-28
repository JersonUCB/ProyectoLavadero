#include "TxTLocalLoader.h"

TxTLocalLoader::TxTLocalLoader()
{
}

TxTLocalLoader::~TxTLocalLoader()
{
}

vector<Camioneta*> TxTLocalLoader::vectorCamioneta()
{
	vector<Camioneta*> camionetas;
	string placa, marca, modelo;
	int anio = 0;
	string estado;
	bool cargaAbierta;
	ifstream archivo1;
	archivo1.open("Camionetas.txt", ios::in);
	if (archivo1.fail())
	{
		cout << "No se pudo Abrir el Archivo de Camionetas" << endl;
		archivo1.close();
		return camionetas;
	}
	while (archivo1.good())
	{
		archivo1 >> placa >> marca >> modelo >> anio >> estado >> cargaAbierta;
		camionetas.push_back(new Camioneta(placa, marca, modelo, anio, estado, cargaAbierta));
	}
	archivo1.close();
	return camionetas;
}

vector<Automovil*> TxTLocalLoader::vectorAutomovil()
{
	vector<Automovil*>automoviles;
	string placa, marca, modelo;
	int anio = 0;
	string estado;
	int numPuertas;
	ifstream archivo1;
	archivo1.open("Automoviles.txt", ios::in);
	if (archivo1.fail())
	{
		cout << "No se pudo Abrir el Archivo de Automoviles" << endl;
		archivo1.close();
		return automoviles;
	}
	while (archivo1.good())
	{
		archivo1 >> placa >> marca >> modelo >> anio >> estado >> numPuertas;
		automoviles.push_back(new Automovil(placa, marca, modelo, anio, estado, numPuertas));
	}
	archivo1.close();
	return automoviles;
}

vector<Moto*> TxTLocalLoader::vectorMoto()
{
	vector<Moto*>motos;
	string placa, marca, modelo;
	int anio = 0;
	string estado;
	bool electrica;
	ifstream archivo1;
	archivo1.open("Motos.txt", ios::in);
	if (archivo1.fail())
	{
		cout << "No se pudo Abrir el Archivo de Motos" << endl;
		archivo1.close();
		return motos;
	}
	while (archivo1.good())
	{
		archivo1 >> placa >> marca >> modelo >> anio >> estado >> electrica;
		motos.push_back(new Moto(placa, marca, modelo, anio, estado, electrica));
	}
	archivo1.close();
	return motos;
}

vector<Vehiculo*> TxTLocalLoader::vectorVehiculo()
{
	vector<Vehiculo*> vehiculos;
	string tipoVehiculo;

	ifstream archivo1("Vehiculos.txt");
	if (archivo1.fail()) {
		cout << "No se pudo abrir el Archivo de Vehículos" << std::endl;
		archivo1.close();
		return vehiculos;
	}

	while (archivo1 >> tipoVehiculo) {
		Vehiculo* nuevoVehiculo = nullptr;

		if (tipoVehiculo == "Automovil") {
			vector<Automovil*> automoviles = vectorAutomovil();
			for (Automovil* autoPtr : automoviles) {
				vehiculos.push_back(autoPtr);
			}
			//vehiculos.insert(vehiculos.end(), automoviles.begin(), automoviles.end());
		}
		else if (tipoVehiculo == "Camioneta") {
			vector<Camioneta*> camionetas = vectorCamioneta();
			//vehiculos.insert(vehiculos.end(), camionetas.begin(), camionetas.end());
			for (Camioneta* camionetaPtr : camionetas) {
				vehiculos.push_back(camionetaPtr);
			}
		}
		else if (tipoVehiculo == "Moto") {
			vector<Moto*> motos = vectorMoto();
			//vehiculos.insert(vehiculos.end(), motos.begin(), motos.end());
			for (Moto* motoPtr : motos) {
				vehiculos.push_back(motoPtr);
			}
		}
		else {
			cout << "Tipo de vehiculo no reconocido: " << tipoVehiculo << std::endl;
			break;
		}
	}

	archivo1.close();
	return vehiculos;
}

vector<Cliente*> TxTLocalLoader::vectorCliente()
{
	vector<Cliente*>clientes;
	int id = 0;
	string nombre, telefono, tipoCliente;
	ifstream archivo1;
	archivo1.open("Clientes.txt", ios::in);
	if (archivo1.fail())
	{
		cout << "No se pudo Abrir el Archivo de Clientes" << endl;
		archivo1.close();
		return clientes;
	}
	while (archivo1.good())
	{
		archivo1 >> id >> nombre >> telefono >> tipoCliente;
		clientes.push_back(new Cliente(id, nombre, telefono, tipoCliente));
	}
	archivo1.close();
	return clientes;
}

vector<Trabajador*> TxTLocalLoader::vectorTrabajador()
{
	vector<Trabajador*>trabajadores;
	int id = 0;
	string nombre, telefono, cargo;
	float salario;
	ifstream archivo1;
	archivo1.open("Trabajadores.txt", ios::in);
	if (archivo1.fail())
	{
		cout << "No se pudo Abrir el Archivo de Trabajadores" << endl;
		archivo1.close();
		return trabajadores;
	}

	while (archivo1.good())
	{
		archivo1 >> id >> nombre >> telefono >> cargo >> salario;
		trabajadores.push_back(new Trabajador(id, nombre, telefono, cargo, salario));
	}

	archivo1.close();
	return trabajadores;
}



