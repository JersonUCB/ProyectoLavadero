#include "StaticLocalLoader.h"

StaticLocalLoader::StaticLocalLoader()
{
}

StaticLocalLoader::~StaticLocalLoader()
{
}

vector<Camioneta*> StaticLocalLoader::vectorCamioneta()
{
	vector<Camioneta*> camionetas;
	camionetas.push_back(new Camioneta("ABC123", "Toyota", "Hilux", 2022, "en espera", true));
	camionetas.push_back(new Camioneta("DEF456", "Ford", "Ranger", 2023, "en espera", false));
	camionetas.push_back(new Camioneta("GHI789", "Chevrolet", "Colorado", 2021, "en espera", true));
	camionetas.push_back(new Camioneta("KJF345", "NISSAN", "Nide", 2021, "en espera", true));
	camionetas.push_back(new Camioneta("GHI789", "Ford", "Colorado", 2021, "en espera", false));
	return camionetas;
}

vector<Automovil*> StaticLocalLoader::vectorAutomovil()
{
	 vector<Automovil*> automoviles;
	 automoviles.push_back(new Automovil("JKL012", "Honda", "Civic", 2022, "Lavado", 4));
	 automoviles.push_back(new Automovil("MNO345", "Ford", "Focus", 2023, "En espera", 5));
	 automoviles.push_back(new Automovil("PQR678", "Toyota", "Corolla", 2021, "Lavado", 3));
	 automoviles.push_back(new Automovil("STU901", "Chevrolet", "Malibu", 2022, "En espera", 4));
	 automoviles.push_back(new Automovil("VWX234", "Nissan", "Altima", 2023, "Lavado", 5));
	 return automoviles;
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

vector<Moto*> StaticLocalLoader::vectorMoto()
{
	vector<Moto*> motos;
	motos.push_back(new Moto("ABC001", "Honda", "CBR300", 2022, "En espera", true));
	motos.push_back(new Moto("DEF002", "Yamaha", "YZF-R6", 2023, "Lavado", false));
	motos.push_back(new Moto("GHI003", "Suzuki", "GSX-R750", 2021, "En espera", true));
	motos.push_back(new Moto("JKL004", "Kawasaki", "Ninja 650", 2022, "Lavado", false));
	motos.push_back(new Moto("MNO005", "Ducati", "Monster 821", 2023, "En espera", true));

	return motos;
}

vector<Trabajador*> StaticLocalLoader::vectorTrabajador()
{
     vector<Trabajador*> trabajadores;
	 trabajadores.push_back(new Trabajador(1, "Ana González", "111111111", "Lavador", 1500));
	 trabajadores.push_back(new Trabajador(2, "Carlos Rodriguez", "222222222", "Recepcionista", 1200));
	 trabajadores.push_back(new Trabajador(3, "Elena Pérez", "333333333", "Encargado de Turno", 2500));
	 trabajadores.push_back(new Trabajador(4, "Mario López", "444444444", "Asistente de Limpieza", 1100));
	 trabajadores.push_back(new Trabajador(5, "Luisa Martínez", "555555555", "Supervisor", 3000));
	 return trabajadores;
}

