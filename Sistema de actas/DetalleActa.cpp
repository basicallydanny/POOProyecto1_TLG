#include "DetalleActa.h"

DetalleActa::DetalleActa(){

}
float DetalleActa::obtenerCalificacionFinal(){
    //TODO Metodo que recorra el vector y saque las notas multiplicadas los ponderados
}
float DetalleActa::getCalificacionFinal(){
    return this->calificacionFinal;
}
string DetalleActa::getObservacionesAdicionales(){
    return this->observacionesAdicionales;
}
void DetalleActa::setObservacionesAdicionales(string obersavion){
    this->observacionesAdicionales = obersavion;
}