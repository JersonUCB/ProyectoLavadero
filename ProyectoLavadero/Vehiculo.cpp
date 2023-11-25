#include "Vehiculo.h"

Vehiculo::Vehiculo(string placa, string marca, string modelo, int anio, string estado)
{
	this->placa = placa;
	this->marca = marca;
	this->modelo = modelo;
	this->anio = anio;
	this->estado = estado;
}

Vehiculo::~Vehiculo()
{
}

string Vehiculo::getMarca()
{
	return marca;
}

string Vehiculo::getEstado()
{
	return estado;
}

string Vehiculo::getPlaca()
{
	return placa;
}

string Vehiculo::getModelo()
{
	return modelo;
}

void Vehiculo::mostrar()
{
	cout << "------------INFO VEHICULO--------------" << endl;
	cout << "Placa: " << placa << endl;
	cout << "Marca: " << marca << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Anio: " << anio << endl;
	cout << "Estado: " << estado << endl;
}