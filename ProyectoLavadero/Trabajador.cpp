#include "Trabajador.h"

Trabajador::Trabajador(int id, string nombre, string telefono, string cargo, float salario) :Persona(id, nombre, telefono)
{
	this->cargo = cargo;
	this->salario = salario;
}

Trabajador::~Trabajador()
{
}

string Trabajador::getCargo()
{
	return cargo;
}

float Trabajador::getSalario()
{
	return salario;
}
