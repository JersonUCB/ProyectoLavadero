#pragma once
#include "Cliente.h"
#include "Trabajador.h"
#include "Lavado.h"
#include <vector>

class AdmiLavadero
{
private:

	vector<Cliente*> clientes;
	vector<Trabajador*> trabajadores;
	//vector<>

public:
	AdmiLavadero();
	AdmiLavadero(vector<Cliente*> clientes, vector<Trabajador*> trabajadores);

	void run();

};

