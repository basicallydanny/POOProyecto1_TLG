#ifndef DIRECCIONPOS_H
#define DIRECCIONPOS_H
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

#include "Acta.h"
#include "Personal.h"

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
    void VerCriterio();
    void verResumen();
    void editarCriterios();
    void newCriterio();
    void eliminarCriterio();
    void generarReporte(Acta acta);
    void evaluarActa();
    void verReprobadosyAprobados();
    string cadenaAMinuscula(string cadena);
};

#endif