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
    string numeroActa;
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
    Acta();
    Acta(string fecha, string numeroActa, string nombreEstudiante, string nombreTrabajo,
    string tipoTrabajo, string nombreDirector, string coNombreDirector, string juradoUno,
    string juradoDos);
    //gets & sets
    string getNumeroActa();
    void setNumeroActa(string numeroActa);
    string getFecha();
    void setFecha(string fecha);
    string getNombreAutor();
    void setNombreAutor(string nombreAutor); 
    string getNombreTrabajo();
    void setNombreTrabajo(string nombreTrabajo);
    string getTipoTrabajo();
    void setTipoTrabajo(string tipoTrabajo );
    string getDirector();
    void setDirector(string director);
    string getCodirector();
    void setCodirector(string codirector);
    string getJuradoUno();
    void setJuradoUno(string juradoUno);
    string getJuradoDos();
    void setJuradoDos(string juradoDOs);
};


#endif