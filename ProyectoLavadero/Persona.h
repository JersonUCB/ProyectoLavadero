#pragma once

#include <string>
using namespace std;

class Persona {
protected:
    int id;
    string nombre;
    string telefono;

public:
    Persona(int id, string nombre, string telefono);
    virtual ~Persona();

    int getId();
    string getNombre();
    string getTelefono();
};

