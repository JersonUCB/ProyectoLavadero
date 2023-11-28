#pragma once
#include "LocalLoader.h"
#include<fstream>
//#include<iostream>
#include<string>

class TxTLocalLoader : public LocalLoader
{
public:
	TxTLocalLoader();
	~TxTLocalLoader();
	vector<Camioneta*> vectorCamioneta();
	vector<Automovil*> vectorAutomovil();
	vector<Moto*> vectorMoto();
	vector<Vehiculo*> vectorVehiculo();
	vector<Cliente*> vectorCliente();
	vector<Trabajador*> vectorTrabajador();
};

