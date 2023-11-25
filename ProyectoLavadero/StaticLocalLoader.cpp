#include "StaticLocalLoader.h"

StaticLocalLoader::StaticLocalLoader()
{
}

StaticLocalLoader::~StaticLocalLoader()
{
}

vector<Automovil*> StaticLocalLoader::vectorAutomovil()
{
	 vector<Automovil*> automoviles;
	 automoviles.push_back(new Automovil("JKL012", "Honda", "Civic", 2022, "lavado", 2));
	 automoviles.push_back(new Automovil("MNO345", "Ford", "Focus", 2023, "en espera", 2));
	 automoviles.push_back(new Automovil("PQR678", "Toyota", "Corolla", 2021, "lavado", 4));
	 automoviles.push_back(new Automovil("STU901", "Chevrolet", "Cruze", 2022, "en espera", 4));
	 automoviles.push_back(new Automovil("VWX234", "Nissan", "Rogue", 2023, "lavado", 5));
	 return automoviles;
}
vector<Camioneta*> StaticLocalLoader::vectorCamioneta()
{
	vector<Camioneta*> camionetas;
	camionetas.push_back(new Camioneta("ABC123", "Toyota", "Hilux", 2022, "en espera", true));
	camionetas.push_back(new Camioneta("DEF456", "Ford", "Ranger", 2023, "en espera", false));
	camionetas.push_back(new Camioneta("GHI789", "Chevrolet", "Colorado", 2021, "en espera", true));
	camionetas.push_back(new Camioneta("KJF345", "NISSAN", "Frontier", 2021, "en espera", true));
	camionetas.push_back(new Camioneta("GHI789", "Mitsubishi", "Triton", 2021, "en espera", false));
	return camionetas;
}

vector<Moto*> StaticLocalLoader::vectorMoto()
{
	vector<Moto*> motos;
	motos.push_back(new Moto("ABC001", "Honda", "CBR300", 2022, "en espera", true));
	motos.push_back(new Moto("DEF002", "Yamaha", "YZF-R6", 2023, "lavado", false));
	motos.push_back(new Moto("GHI003", "Suzuki", "GSX-R750", 2021, "en espera", true));
	motos.push_back(new Moto("JKL004", "Kawasaki", "Ninja 650", 2022, "lavado", false));
	motos.push_back(new Moto("MNO005", "Ducati", "Monster 821", 2023, "en espera", true));

	return motos;
}


vector<Vehiculo*> StaticLocalLoader::vectorVehiculo()
{
	vector<Vehiculo*> vehiculos;
	vehiculos.push_back(new Automovil("JKL012", "Honda", "Civic", 2022, "lavado", 2));
	vehiculos.push_back(new Automovil("MNO345", "Ford", "Focus", 2023, "en espera", 2));
	vehiculos.push_back(new Automovil("PQR678", "Toyota", "Corolla", 2021, "lavado", 4));
	vehiculos.push_back(new Automovil("STU901", "Chevrolet", "Cruze", 2022, "en espera", 4));
	vehiculos.push_back(new Automovil("VWX234", "Nissan", "Rogue", 2023, "lavado", 5));

	vehiculos.push_back(new Moto("ABC001", "Honda", "CBR300", 2022, "en espera", true));
	vehiculos.push_back(new Moto("DEF002", "Yamaha", "YZF-R6", 2023, "lavado", false));
	vehiculos.push_back(new Moto("GHI003", "Suzuki", "GSX-R750", 2021, "en espera", true));
	vehiculos.push_back(new Moto("JKL004", "Kawasaki", "Ninja 650", 2022, "lavado", false));
	vehiculos.push_back(new Moto("MNO005", "Ducati", "Monster 821", 2023, "en espera", true));

	vehiculos.push_back(new Camioneta("ABC123", "Toyota", "Hilux", 2022, "en espera", true));
	vehiculos.push_back(new Camioneta("DEF456", "Ford", "Ranger", 2023, "en espera", false));
	vehiculos.push_back(new Camioneta("GHI789", "Chevrolet", "Colorado", 2021, "en espera", true));
	vehiculos.push_back(new Camioneta("KJF345", "NISSAN", "Frontier", 2021, "en espera", true));
	vehiculos.push_back(new Camioneta("GHI789", "Mitsubishi", "Triton", 2021, "en espera", false));

	return vehiculos;
}



vector<Trabajador*> StaticLocalLoader::vectorTrabajador()
{
     vector<Trabajador*> trabajadores;
	 trabajadores.push_back(new Trabajador(1, "Ana Gonzalez", "111111111", "Lavador", 1500));
	 trabajadores.push_back(new Trabajador(2, "Carlos Rodriguez", "222222222", "Recepcionista", 1200));
	 trabajadores.push_back(new Trabajador(3, "Elena Perez", "333333333", "Encargado de Turno", 2500));
	 trabajadores.push_back(new Trabajador(4, "Mario Lopez", "444444444", "Asistente de Limpieza", 1100));
	 trabajadores.push_back(new Trabajador(5, "Luisa Martínez", "555555555", "Supervisor", 3000));
	 return trabajadores;
}

vector<Cliente*> StaticLocalLoader::vectorCliente()
{
	vector<Cliente*> clientes;
	clientes.push_back(new Cliente(1, "Juan Perez", "123456789", "Estandar"));
	clientes.push_back(new Cliente(2, "Maria Rodriguez", "987654321", "Premium"));
	clientes.push_back(new Cliente(3, "Carlos Gomez", "555555555", "Estandar"));
	clientes.push_back(new Cliente(4, "Laura Torres", "333333333", "Premium"));
	clientes.push_back(new Cliente(5, "Pedro Hernandez", "777777777", "Estandar"));
	return clientes;
}
