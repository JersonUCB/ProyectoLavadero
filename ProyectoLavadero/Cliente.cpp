#include "Cliente.h"
#include "Cliente.h"

Cliente::Cliente(int id, string nombre, string telefono, string TipoCliente) :Persona(id, nombre, telefono)
{
    this->TipoCliente = TipoCliente;
}

Cliente::~Cliente()
{
}

string  Cliente::getTipoCliente()
{

    return TipoCliente;
}

void Cliente::mostrar()
{
    cout << "-----> Cliente <-----" << endl;
    Persona::mostrar();
    cout << "tipo de cliente: " << TipoCliente << endl;
}
