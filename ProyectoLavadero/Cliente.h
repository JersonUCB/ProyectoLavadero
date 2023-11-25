#pragma once
#include "Persona.h"

class Cliente : public Persona {
private:
    string TipoCliente;
public:
    Cliente(int id, string nombre, string telefono, string tipoCliente);
    ~Cliente();

    string getTipoCliente();
    void mostrar();
};
