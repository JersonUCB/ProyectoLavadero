#include "AdmiLavadero.h"

AdmiLavadero::AdmiLavadero()
{
}

AdmiLavadero::AdmiLavadero(vector<Cliente*> clientes, vector<Trabajador*> trabajadores)
{
	this->clientes = clientes;
	this->trabajadores = trabajadores;
}

void AdmiLavadero::run()
{
	//menu();
}
