#include "DetalleActa.h"

//gets y sets
void DetalleActa::setCalificacionFinal(float calificacionFinal){
    this->calificacionFinal = calificacionFinal;
}

float DetalleActa::getCalificacionFinal(){
    return this->calificacionFinal;
}

void DetalleActa::setObsAdicionales(string observasion){
    this->observacionesAdicionales = observasion;
}

string DetalleActa::getObsAdicionales(){
    return this->observacionesAdicionales;
}

//metodos

void DetalleActa::addCriterio(string titulo, string observacion, float ponderado, float calificacion){
    Criterio crit( titulo, observacion, ponderado, calificacion );
    listaCriterios.push_back( crit );
    this->numCriterios++;
}

void DetalleActa::delCriterio(string titulo){}

vector<Criterio> DetalleActa::getCriterios(){
    return listaCriterios;
}