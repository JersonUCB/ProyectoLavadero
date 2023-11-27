#include "Lavado.h"
//#include "Lavado.h"

int Lavado::cantidadInstancias = 0;

string tipoLavadoToString(TipoLavado tipo)
{
    switch (tipo) {
    case estandar:
        return "Estandar";
    case medio:
        return "Medio";
    case premium:
        return "Premium";
    default:
        return "Desconocido";
    }
}
Lavado::Lavado(Vehiculo* vehiculo, Cliente* cliente, Trabajador* trabajador,  double costoLavado)
{
    this->vehiculo = vehiculo;
    this->cliente = cliente;
    this->trabajador = trabajador;
    this->costoLavado = costoLavado;
    this->tipo = estandar;
    Lavado::cantidadInstancias = Lavado::cantidadInstancias + 1;
}

Lavado::~Lavado()
{
}

void Lavado::mostrar()
{
    cout << "----------- DETALLES DEL LAVADO -----------" << endl;
    cout << "Tipo de lavado: " << tipoLavadoToString(tipo) << endl;


    // Mostrar detalles del vehículo
    vehiculo->mostrar();

    
    /*cout << "----------- DATOS DEL CLIENTE ------------" << endl;
    cliente->mostrar();
    
    cout << "----------- DATOS DEL TRABAJADOR ----------" << endl;
    trabajador->mostrar();
    */
    cout << "Costo total del lavado: $" << costoLavado << endl;
}


double Lavado::getCostoLavado()
{
    return costoLavado;
}

void  Lavado::setTipoLavadoEstandar()
{
    tipo = estandar;
}

void  Lavado::setTipoLavadoMedio()
{ 
    tipo = medio;
}

void Lavado::setTipoLavadoPremium()
{
    tipo = premium;
}

int Lavado::getCantidadInstancias()
{
    return cantidadInstancias;
}

inline string Lavado::encode()
{
    return "String encode";
}
