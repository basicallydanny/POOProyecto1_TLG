//Guardas 
#ifndef DETALLEACTA_H
#define DETALLEACTA_H
//Incluir librerias 
#include <iostream>
#include <string>
#include <vector>
#include "Criterio.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

//Clase
class DetalleActa
{
private:
    float calificacionFinal;
    string observacionesAdicionales;
    vector<Criterio>listaCriterios;
public:
    DetalleActa();
    float obtenerCalificacionFinal();
    float getCalificacionFinal();
    string getObservacionesAdicionales();
    void setObservacionesAdicionales(string obersavion);

};



#endif