//Guardas 
#ifndef DIRECCIONPOS_H
#define DIRECCIONPOS_H
//Incluir librerias 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Acta.h"
#include "Personal.h"


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
using std::getline;

class DireccionPos{
private:
    int contActas;
    map <int, Personal> personalAdmin;
    vector<Acta>listaActas;

public:
    void loginUsuario(string);
    void mostrarMenuAsistente();
    void mostrarMenuDirector();
    void mostrarMenuJurado();
    void mostrarCriterios();
    void mostrarActa();
    void crearActa();
    void modificarActa();
    void VerActas();
    void newCriterio();
    void deleteCriterio();
    void VerCriterio();
};

#endif