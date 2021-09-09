//Guardas 
#ifndef DIRECCIONPOS_H
#define DIRECCIONPOS_H
//Incluir librerias 
#include <iostream>
#include <string>
#include <vector>
#include "Acta.h"
#include "Personal.h"


using std::cout;
using std::cin;
using std::string;
using std::vector;
//Clase

class DireccionPos
{
private:
    int contActas;
    vector<Acta>listaActas;
public:
    void mostrarMenuAsistente();
    void mostrarMenuDirector();
    void mostrarMenuJurado();
    void mostrarCriterios();
};



#endif