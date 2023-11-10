#include "Persona.h"

Persona::Persona(int id, string nombre, string telefono)
{
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
}

Persona::~Persona()
{
}

int Persona::getId()
{
    return id;
}

string Persona::getNombre()
{
    return nombre;
}

string Persona::getTelefono()
{
    return telefono;
}
