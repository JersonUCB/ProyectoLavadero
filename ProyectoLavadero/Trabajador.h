#pragma once
#include "Persona.h"
class Trabajador :public Persona
{
public:
	Trabajador(int id, string nombre, string telefono, string cargo, float salario);
	~Trabajador();
	string getCargo();
	float getSalario();
	void mostrar();
private:
	string cargo;
	float salario;
};

