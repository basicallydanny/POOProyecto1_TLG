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
}

void DetalleActa::delCriterio(string titulo){
    auto iterador = listaCriterios.begin();
    while(iterador != listaCriterios.end()){
        if(iterador->getTitulo() == titulo){
            iterador = listaCriterios.erase( iterador );
            break;
        }
        else{
            ++iterador;
        }
    }
}

vector<Criterio> DetalleActa::getCriterios(){
    return listaCriterios;
}