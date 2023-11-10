#include "Lavado.h"

Lavado::Lavado(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador, string tipo, double costoLavado)
{

}

Lavado::~Lavado()
{
}

void Lavado::mostrar() {
    cout << "----------- DETALLES DEL LAVADO -----------" << endl;
    cout << "Tipo de lavado: " << tipo << endl;
    cout << "Descripción: " << descripcion << endl;

    // Mostrar detalles del vehículo
    vehiculo->mostrar();

    // Mostrar detalles del cliente
    cout << "----------- DATOS DEL CLIENTE ------------" << endl;
    cout << "ID Cliente: " << cliente->getId() << endl;
    cout << "Nombre: " << cliente->getNombre() << endl;
    cout << "Teléfono: " << cliente->getTelefono() << endl;

    // Mostrar detalles del trabajador
    cout << "----------- DATOS DEL TRABAJADOR ----------" << endl;
    cout << "ID Trabajador: " << trabajador->getId() << endl;
    cout << "Nombre: " << trabajador->getNombre() << endl;
    cout << "Teléfono: " << trabajador->getTelefono() << endl;
    cout << "Cargo: " << trabajador->getCargo() << endl;
    cout << "Salario: $" << trabajador->getSalario() << endl;

    cout << "Costo total del lavado: $" << costoLavado << endl;
}


double Lavado::getCostoLavado()
{
	return costoLavado;
}
