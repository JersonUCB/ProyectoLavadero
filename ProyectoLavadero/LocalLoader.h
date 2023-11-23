#pragma once
#include"Camioneta.h"
#include"Automovil.h"
#include"Moto.h"
#include"Cliente.h"
#include"Trabajador.h"
#include<string>
#include <vector>
class LocalLoader
{
public:
	LocalLoader();
	~LocalLoader();
	virtual vector<Camioneta*> vectorCamioneta();
	virtual vector<Automovil*> vectorAutomovil();
	virtual vector<Moto*> vectorMoto();
	virtual vector<Vehiculo*> vectorVehiculo();
	virtual vector<Cliente*> vectorCliente();
	virtual vector<Trabajador*> vectorTrabajador();
};

