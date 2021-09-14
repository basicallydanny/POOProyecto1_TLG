//Guardas 
#ifndef ACTA_H
#define ACTA_H
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
class Acta{
private:

    int numeroActa;
    string fecha;
    string nombreAutor;
    string nombreTrabajo;
    string tipoTrabajo;
    string director;
    string codirector;
    string juradoUno;
    string juradoDos;
    string estado;
    float calificacionFinal;
    string observacionesAdicionales;
    vector<Criterio>listaCriterios;


public:

    Acta();
    Acta(string fecha, int numeroActa, string nombreEstudiante, string nombreTrabajo,
    string tipoTrabajo, string nombreDirector, string coNombreDirector, string juradoUno,
    string juradoDos, vector<Criterio>criterios);

    //gets & sets

    int getNumeroActa();
    void setNumeroActa(int numeroActa);
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
    string getEstado();
    void setEstado(string estado);
    string getJuradoDos();
    void setJuradoDos(string juradoDos);
    void setCalificacionFinal(float calificacionFinal);
    float getCalificacionFinal();
    string getObsAdicionales();
    void setObsAdicionales(string observasion);
    void setCriterios(vector<Criterio>criterios);
    void mostrarActa();
    vector <Criterio> getCriteros() const { return listaCriterios; }
};


#endif