//Guardas 
#ifndef ACTA_H
#define ACTA_H
//Incluir librerias 
#include <iostream>
#include <string>
#include "DetalleActa.h"

using std::cout;
using std::cin;
using std::string;
//Clase
class Acta
{
private:
    string numero;
    string fecha;
    string nombreAutor;
    string nombreTrabajo;
    string tipoTrabajo;
    string director;
    string codirector;
    string juradoUno;
    string juradoDos;
    DetalleActa CuerpoActa;
public:

};


#endif