//Guardas 
#ifndef CRITERIO_H
#define CRITERIO_H
//Incluir librerias 
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
//Clase

class Criterio{
private:
    string titulo;
    string observacion;
    float ponderado;
    float calificacionUno;
    float calificacionDos;
public:
    Criterio();
    Criterio(string titulo, string observacion, float ponderado, float calificacionUno, float calificacionDos);
    void setTitulo(string titulo);
    string getTitulo();
    void setObservacion(string observacion);
    string getObservacion();
    void setPonderado(float ponderado);
    float getPonderado();
    void setCalificacionUno(float calificacionUno);
    float getCalificacionUno();
    void setCalificacionDos(float calificacionDos);
    float getCalificacionDos();
};

 
#endif