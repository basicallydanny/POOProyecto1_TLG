#include "Criterio.h"

Criterio::Criterio(){

}
Criterio::Criterio(string titulo, string observacion, float ponderado, float calificacion){
    this->titulo = titulo;
    this->observacion = observacion;
    this->ponderado = ponderado;
    this->califiacion = califiacion;
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
void Criterio::setCalificacion(float calificacion){
    this->califiacion = califiacion;
}
float Criterio::getCalificacion(){
    return this->califiacion;
}
