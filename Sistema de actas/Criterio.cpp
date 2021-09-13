#include "Criterio.h"

Criterio::Criterio(){

}
Criterio::Criterio(string titulo, string observacion, float ponderado, float calificacionUno, float calificacionDos){
    this->titulo = titulo;
    this->observacion = observacion;
    this->ponderado = ponderado;
    this->calificacionUno = calificacionUno;
    this->calificacionDos = calificacionDos;
}
void Criterio::setTitulo(string titulo){
    this->titulo = titulo;
}
string Criterio::getTitulo(){
    return this->titulo;
}
void Criterio::setObservacion(string observacion){
    this->observacion = observacion;
}
string Criterio::getObservacion(){
    return this->observacion;
}
void Criterio::setPonderado(float ponderado){
    this->ponderado = ponderado;
}
float Criterio::getPonderado(){
    return this->ponderado;
}
void Criterio::setCalificacionUno(float califiacionUno){
    this->calificacionUno = califiacionUno;
}
float Criterio::getCalificacionUno(){
    return this->calificacionUno;
}
void Criterio::setCalificacionDos(float califiacionDos){
    this->calificacionDos = califiacionDos;
}
float Criterio::getCalificacionDos(){
    return this->calificacionDos;
}
