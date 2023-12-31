#include "Consola.h"


int Consola::tipoVehiculo()
{
	int tipoVehiculo;
	cout << "Seleccione el tipo de vehiculo:" << endl;
	cout << "1. Automovil" << endl;
	cout << "2. Moto" << endl;
	cout << "3. Camioneta" << endl;
	
	cout << "Ingrese la opcion: ";
	cin >> tipoVehiculo;
	return tipoVehiculo;
}

int Consola::numeroPuertas()
{
	int numPuertas;
	cout << "Ingrese el numero de puertas del automovil: ";
	cin >> numPuertas;
	return numPuertas;
}

bool Consola::motoElectrica()
{
	bool esElectrica;
	cout << "�Es la moto electrica? (1 para Si / 0 para No): ";
	cin >> esElectrica;
	return esElectrica;
}

bool Consola::cajaCubierta()
{
	bool cargaAbierta;
	cout << "�Es la camioneta de carga abierta? (1 para Si / 0 para No): ";
	cin >> cargaAbierta;
	return cargaAbierta;
}

void Consola::showMenu()
{
	cout << "1. Registrar nuevo vehiculo" << endl;
	cout << "2. Registrar nuevo Trabajador" << endl;
	cout << "3. Registrar nuevo Cliente" << endl;
	cout << "4. Lavar un vehiculo " << endl;
	cout << "5. Mostrar todos los datos de los vehiculos que se han lavado" << endl;
	cout << "6. Obtener el beneficio total" << endl;
	cout << "7. Mostrar los datos de los vehiculos que estan en espera" << endl;
	cout << "8. Buscar trabajadores segun su nombre" << endl;
	cout << "9. Mostrar la cantidad de lavados instanciados" << endl;
	cout << "10. Mostrar todos los trabajadores segun su salario de manera ascendente" << endl;
	cout << "11. Mostrar clientes Premium" << endl;
	cout << "12. Buscar un vehiculo por placa" << endl;
	cout << "13. Buscar cliente por id" << endl;
	cout << "14. Cambiar el tipo de un lavado a premium" << endl;
	cout << "16. mostrar clientes" << endl;
	cout << "17. mostrar trabajadores" << endl;
	cout << "18. mostrar vehiculos" << endl;
	cout << "0. Salir" << endl;
	cout << "Digite una opcion: " << endl;
}

Trabajador* Consola::showRegisterNewEmployee()
{
	int id;
	string nombre, telefono, cargo;
	float salario;
	cout << "Ingrese id del Trabajador: ";
	cin >> id;
	cout << "Ingrese Nombre del Trabajador: ";
	cin >> nombre;
	cout << "Ingrese Telefono del Trabajador: ";
	cin >> telefono;
	cout << "Ingrese Cargo del Trabajador: ";
	cin >> cargo;
	cout << "Ingrese salario del Trabajador: ";
	cin >> salario;
	Trabajador*  trabajador = new Trabajador(id, nombre, telefono, cargo, salario);
	return trabajador;
}

Cliente* Consola::showRegisterNewClient()
{
	int id;
	string nombre, telefono, TipoCliente;
	cout << "Ingrese id del Cliente: ";
	cin >> id;
	cout << "Ingrese Nombre del Cliente: ";
	cin >> nombre;
	cout << "Ingrese Telefono del Cliente: ";
	cin >> telefono;
	cout << "Ingrese si el Tipo de Cliente (el tipo puede ser: estandar, premium, platino) : ";
	cin >> TipoCliente;
	Cliente* cliente = new Cliente(id, nombre, telefono, TipoCliente);

	return cliente;
}
