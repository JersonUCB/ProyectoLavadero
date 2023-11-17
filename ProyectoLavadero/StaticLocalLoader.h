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
	 vector<Cliente*> vectorCliente();
	 vector<Moto*> vectorMoto();
	 vector<Trabajador*> vectorTrabajador();
};

