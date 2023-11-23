#pragma once
#include "LocalLoader.h"
#include <vector>
class StaticLocalLoader :public LocalLoader
{
public:
	StaticLocalLoader();
	~StaticLocalLoader();
	 vector<Camioneta*> vectorCamioneta();
	 vector<Automovil*> vectorAutomovil();
	 vector<Moto*> vectorMoto();
	 vector<Vehiculo*> vectorVehiculo();
	 vector<Cliente*> vectorCliente();
	 vector<Trabajador*> vectorTrabajador();
};


