#pragma once
#include "Persona.h"

class Cliente : public Persona {
public:
    Cliente(int id, string nombre, string telefono, string tipoCliente);
    ~Cliente();

    string getTipoCliente();
    //Lavado* lavado;
private:
    string TipoCliente;
};
