//Guardas 
#ifndef VIEW_H
#define VIEW_H
//Incluir librerias 
#include <iostream>
#include <string>
#include "DireccionPos.h"

using std::cout;
using std::cin;
using std::string;
//Clase
class View{
private:
    DireccionPos sistema;    
public:
    void mostrarMenuGeneral();
};


#endif