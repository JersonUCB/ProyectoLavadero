#include "AdmiLavadero.h"
#include "QuickSort.h"

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
			RegistrarVehiculo();
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			RegistrarEmpleado();
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			RegistrarNuevoCliente();
			system("pause");
			system("cls");
			break;
		}


		case 4:
		{
			LavarVehiculo();
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			MostrarVehiculosLavados();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
		    ObtenerBeneficioTotal();
			system("pause");
			system("cls");
			break;
		}

		case 7:
		{
			MostrarVehiculosEnEspera();
			system("pause");
			system("cls");
			break;
		}

		case 8:
		{
			cin.ignore();
			string nombre;
			cout << "Ingrese el nombre del Trabajador que desea buscar" << endl;
			getline(cin, nombre);

			BuscarTrabajadorPorNombre(nombre);
			system("pause");
			system("cls");
			break;
		}

		case 9:
		{
			MostrarLavadosInstaciados();
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			mostrarTrabajadoresPorSalarioAscendente();
			system("pause");
			system("cls");
			break;
		}
		case 11:
		{
            MostrarClientesPremium();
			system("pause");
			system("cls");
			break;
		}
		case 12:
		{
			string placa;
			cout << "Ingrese la placa del vehiculo a buscar: ";
			cin >> placa;
			buscarVehiculoPorPlaca(placa);
			system("pause");
			system("cls");
			break;
		}
		case 13:
		{
			int id;
			cout << "Ingrese el ID del cliente a buscar: ";
			cin >> id;

			buscarClientePorID(id);
			system("pause");
			system("cls");
			break;
		}
		case 14:
		{
			cambiarTipoLavadoAPremium();
			system("pause");
			system("cls");
			break;
		}
		case 16:
		{
			MostrarCliente();
			system("pause");
			system("cls");
			break;
		}
		case 17:
		{
			MostrarEmpleado();
			system("pause");
			system("cls");
			break;
		}
		case 18:
		{
			MostrarVehiculo();
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
	LocalLoader* localLoader = new StaticLocalLoader();
	//LocalLoader* localLoader = new TxTLocalLoader();

	trabajadores = localLoader->vectorTrabajador();
	clientes = localLoader->vectorCliente();
	vehiculos = localLoader->vectorVehiculo();

	automoviles = localLoader->vectorAutomovil();
	motos = localLoader->vectorMoto();
	camionetas = localLoader->vectorCamioneta();

	delete localLoader;

	showMenu();
}

void AdmiLavadero::RegistrarVehiculo() {
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

void AdmiLavadero::RegistrarEmpleado()
{
	Trabajador* trabajador;
	trabajador = consola.showRegisterNewEmployee();
	trabajadores.push_back(trabajador);
	cout << "El trabajador ha sido registrado" << endl;
}

void AdmiLavadero::RegistrarNuevoCliente()
{
	Cliente* cliente;
	cliente = consola.showRegisterNewClient();
	clientes.push_back(cliente);
	cout << "El Cliente ha sido registrado" << endl;
}


void AdmiLavadero::LavarVehiculo()
{
	cout << "Vehiculos disponibles para lavar:" << endl;
	bool hayVehiculosEnEspera = false;

	for (Vehiculo* vehiculo : vehiculos) {
		if (vehiculo->getEstado() == "en espera")
		{
			cout << vehiculo->getModelo() << " - " << vehiculo->getPlaca() << " " << vehiculo->getMarca() << endl;
			hayVehiculosEnEspera = true;
		}
	}

	if (!hayVehiculosEnEspera)
	{
		cout << "No hay vehiculos disponibles para lavar." << endl;
		return;
	}

	string modeloSeleccionado;
	cout << "Ingrese el modelo del vehiculo que desea lavar: ";
	cin.ignore();
	getline(cin, modeloSeleccionado);

	Vehiculo* vehiculoSeleccionado = nullptr;

	for (Vehiculo* vehiculo : vehiculos)
	{
		if (vehiculo->getEstado() == "en espera" && vehiculo->getModelo() == modeloSeleccionado)
		{
			vehiculoSeleccionado = vehiculo;
			break;
		}
	}

	if (vehiculoSeleccionado != nullptr)
	{
		vehiculoSeleccionado->mostrar();

		Trabajador* trabajadorAsignado = nullptr;
		cout << "Seleccione el ID del trabajador para lavar el vehiculo: " << endl;
		for (int i = 0; i < trabajadores.size(); i++) {
			cout << "ID trabajador: " << trabajadores[i]->getId() << ". " << trabajadores[i]->getNombre() << endl;
		}

		int option;
		cin >> option;

		if (option > 0 && option <= trabajadores.size()) {
			trabajadorAsignado = trabajadores[option - 1];

			// Selección del cliente
			Cliente* clienteSeleccionado = nullptr;
			cout << "Seleccione el ID del cliente para el lavado: " << endl;
			for (int i = 0; i < clientes.size(); i++) {
				cout << "ID cliente: " << clientes[i]->getId() << ". " << clientes[i]->getNombre() << endl;
			}

			cin >> option;

			if (option > 0 && option <= clientes.size()) {
				clienteSeleccionado = clientes[option - 1];

				// Selección del tipo de lavado
				int opcionTipoLavado;
				cout << "Seleccione el tipo de lavado:" << endl;
				cout << "1. Estandar" << endl;
				cout << "2. Medio" << endl;
				cout << "3. Premium" << endl;
				cin >> opcionTipoLavado;

				// Verificar y cambiar el tipo de lavado seleccionado
				Lavado* lavadoSeleccionado = new Lavado(vehiculoSeleccionado, cliente, trabajadorAsignado, vehiculoSeleccionado->calcularCosto());
				switch (opcionTipoLavado) {
				case 1:
					// Estándar
					lavadoSeleccionado->setTipoLavadoEstandar();
					break;
				case 2:
					// Medio
					lavadoSeleccionado->setTipoLavadoMedio();
					break;
				case 3:
					// Premium
					lavadoSeleccionado->setTipoLavadoPremium();
					break;
				default:
					cout << "Opcion no valida." << endl;
					return;
				}

				vehiculoSeleccionado->setEstado("lavado");

				lavados.push_back(new Lavado(vehiculoSeleccionado, cliente, trabajadorAsignado, vehiculoSeleccionado->calcularCosto()));

				cout << "Trabajador asignado con exito al lavado." << endl;
				cout << "Vehiculo lavado con exito." << endl;
			}
			else {
				cout << "Opcion no valida." << endl;
				return;
			}
		}
		else {
			cout << "Opcion no valida." << endl;
			return;
		}
	}
	else {
		cout << "Vehiculo no encontrado." << endl;
	}
}


void AdmiLavadero::MostrarVehiculosLavados() {
	if (lavados.empty())
	{
		cout << "Message: >>> No hay vehiculos lavados aun <<< " << endl;
	}
	else 
	{
		for (Lavado* lavado : lavados) {
			lavado->mostrar();
		}
	}
}

void AdmiLavadero::ObtenerBeneficioTotal() {
	double beneficioTotal = 0;

	for (Lavado* lavado : lavados) {
		beneficioTotal += lavado->getCostoLavado();
	}

	double beneficioFinal = beneficioTotal * 0.65;

	cout << "El beneficio total es: $" << beneficioFinal << endl;
}

void AdmiLavadero::MostrarVehiculosEnEspera()
{
	cout << "Vehiculos en espera:" << endl;

	for (auto* vehiculo : vehiculos) {
		if (vehiculo->getEstado() == "en espera") {
			vehiculo->mostrar();
		}
	}

	cout << endl;
}

void AdmiLavadero::BuscarTrabajadorPorNombre(string nombre)
{
	bool encontrado = false;
	for (auto trabajador : trabajadores)
	{
		if (trabajador->getNombre() == nombre)
		{
			trabajador->mostrar();
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "Trabajador no encontrado." << endl;
	}
}

void AdmiLavadero::MostrarCliente()
{
	for (Cliente* var : clientes)
	{
		var->mostrar();
	}
}

void AdmiLavadero::MostrarEmpleado()
{
	for (Trabajador* var : trabajadores)
	{
		var->mostrar();
	}
}

void AdmiLavadero::MostrarVehiculo()
{
	for (Vehiculo* var : vehiculos)
	{
		var->mostrar();
	}
}

void AdmiLavadero::MostrarClientesPremium()
{
	for (Cliente* var : clientes)
	{
		if (var->getTipoCliente() == "Premium" || var->getTipoCliente() == "premium")
		{
			var->mostrar();
		}
	}
}

void AdmiLavadero::MostrarLavadosInstaciados()
{
	cout << "La cantidad de lavados instanciados es: " << Lavado::getCantidadInstancias() << endl;
}

void AdmiLavadero::mostrarTrabajadoresPorSalarioAscendente()
{
	vector<Trabajador*> copiaTrabajadores = trabajadores;

	// Definir un comparador para ordenar los trabajadores por salario
	auto customComparator = [](Trabajador* a, Trabajador* b)
	{
		return a->getSalario() < b->getSalario(); // Orden ascendente por salario
	};

	// Ordenar el vector de trabajadores por salario utilizando QuickSort
	QuickSort<Trabajador>::sort(copiaTrabajadores, customComparator);

	cout << "-----> Trabajadores ordenados por salario de manera ascendente <-----" << endl;
	for (auto trabajador : copiaTrabajadores) {
		trabajador->mostrar();
		cout << "------------------------------" << endl;
	}
	
}


void AdmiLavadero::buscarVehiculoPorPlaca(string placa)
{
	Vehiculo* encontrado = nullptr;

	for (auto vehiculo : vehiculos)
	{
		if (vehiculo->getPlaca() == placa)
		{
			encontrado = vehiculo;
			break;
		}
	}
	// Verificar si se encontro el vehiculo
	if (encontrado != nullptr)
	{
		// Mostrar los detalles del vehiculo encontrado
		encontrado->mostrar();

		// Verificar si el vehiculo esta lavado o en espera
		if (encontrado->getEstado() == "en espera")
		{
			cout << "El vehiculo aun no ha sido lavado." << endl;
		}
		else
		{
			cout << "El vehiculo ya ha sido lavado." << endl;
		}
	}
	else {
		cout << "No se encontro ningun vehiculo con la placa ingresada." << endl;
	}
}

void AdmiLavadero::buscarClientePorID(int id)
{
	bool encontrado = false;
	for (auto cliente : clientes)
	{
		if (cliente->getId() == id)
		{
			cliente->mostrar();
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "Cliente no encontrado." << endl;
	}
}

void AdmiLavadero::cambiarTipoLavadoAPremium()
{
	// Mostrar lavados existentes para elegir uno a cambiar
	cout << "Lavados existentes:" << endl;
	for (int i = 0; i < lavados.size(); ++i) {
		cout << i + 1 << ". ";
		lavados[i]->mostrar();
		cout << endl;
	}

	int opcionLavado;
	cout << "Seleccione el numero del lavado que desea cambiar a Premium: ";
	cin >> opcionLavado;

	if (opcionLavado > 0 && opcionLavado <= lavados.size()) {
		// Cambiar el tipo del lavado seleccionado a Premium
		lavados[opcionLavado - 1]->setTipoLavadoPremium();
		cout << "Tipo de lavado cambiado a Premium con exito." << endl;
	}
	else {
		cout << "Opcion no valida." << endl;
	}
}