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
	virtual vector<Cliente*> vectorCliente();
	virtual vector<Moto*> vectorMoto();
	virtual vector<Trabajador*> vectorTrabajador();
};


