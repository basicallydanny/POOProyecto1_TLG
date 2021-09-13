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
class DetalleActa{
private:
    float calificacionFinal;
    string observacionesAdicionales;
    vector<Criterio>listaCriterios;
    int numCriterios;
public:
//constructor
    DetalleActa(){
        this->calificacionFinal = 0.0;
        this->observacionesAdicionales = "";
        this->numCriterios = 0;
    }
//gets y sets
    void setCalificacionFinal(float calificacionFinal);
    float getCalificacionFinal();
    string getObsAdicionales();
    void setObsAdicionales(string observasion);
    void addCriterio(string titulo, string observacion, float ponderado, float calificacion1, float calificacion2);
    void delCriterio(string titulo);
    vector<Criterio> getCriterios();
};



#endif