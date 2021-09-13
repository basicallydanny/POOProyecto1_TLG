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

void DetalleActa::delCriterio(string titulo){
    vector<Criterio>::iterator pCriterios = listaCriterios.begin();
    while(pCriterios != listaCriterios.end()){
        if(pCriterios->getTitulo() == titulo){
            pCriterios = listaCriterios.erase( pCriterios );
            break;
        }
        else{
            ++pCriterios;
        }
    }
}

vector<Criterio> DetalleActa::getCriterios(){
    return listaCriterios;
}