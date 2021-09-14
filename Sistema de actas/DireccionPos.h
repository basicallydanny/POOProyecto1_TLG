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
#include <sstream>
#include <fstream>
using namespace std;


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
using std::getline;

class DireccionPos{
private:
    int contActas, cantUsuarios;
    map <int, Personal> personalAdmin;
    vector<Acta>listaActas;
    vector<Criterio>criterios;
public:
    void loginUsuario(string);
    Personal nuevoUsuario();
    void insertUsuario(Personal usuario);
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
    void verResumen();
    void editarCriterios();
    void añadirCriterio();
    void eliminarCriterio();
    void generarReporte(Acta acta);
    void evaluarActa();
    void verReprobadosyAprobados();
};

#endif