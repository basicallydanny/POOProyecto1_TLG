#include "Acta.h"

Acta::Acta(){

}
Acta::Acta(string fecha, string numeroActa, string nombreEstudiante, string nombreTrabajo,
    string tipoTrabajo, string nombreDirector, string coNombreDirector, string juradoUno,
    string juradoDos){
        this->fecha = fecha;
        this->numeroActa = numeroActa;
        this->nombreAutor = nombreEstudiante;
        this->nombreTrabajo = nombreTrabajo;
        this->tipoTrabajo = tipoTrabajo;
        this->director = nombreDirector;
        if (coNombreDirector != "")
        {
            this->codirector = coNombreDirector;
        }
        else
        {
            this->codirector = "N/A";
        }
        this->juradoUno = juradoUno;
        this->juradoDos = juradoDos;
    }
string Acta::getNumeroActa()
{
    return this-> numeroActa;
}
void Acta::setNumeroActa(string numeroActa)
{
    this->numeroActa = numeroActa;
}
string Acta::getFecha(){
    return this->fecha;
}
void Acta::setFecha(string fecha){
    this->fecha = fecha;
}
string Acta::getNombreAutor(){
    return this->nombreAutor;
}
void Acta::setNombreAutor(string nombreAutor){
    this->nombreAutor = nombreAutor;
}
string Acta::getNombreTrabajo(){
    return this->nombreTrabajo;
}
void Acta::setNombreTrabajo(string nombreTrabajo){
    this->nombreTrabajo = nombreTrabajo;
}
string Acta::getTipoTrabajo(){
    return this->tipoTrabajo;
}
void Acta::setTipoTrabajo(string tipoTrabajo ){
    this->tipoTrabajo = tipoTrabajo;
}
string Acta::getDirector(){
    return this->director;
}
void Acta::setDirector(string director){
    this->director = director;
}
string Acta::getCodirector(){
    return this->codirector;
}
void Acta::setCodirector(string codirector){
    this->codirector = codirector;
}
string Acta::getJuradoUno(){
    return this->juradoUno;
}
void Acta::setJuradoUno(string juradoUno){
    this-> juradoUno = juradoUno;
}
string Acta::getJuradoDos(){
    return this->juradoDos;
}
void Acta::setJuradoDos(string juradoDOs){
    this->juradoDos=juradoDos;
}
