//Guardas 
#ifndef VIEW_H
#define VIEW_H
//Incluir librerias 
#include <stdio.h>
#include <iostream>
#include <string>
#include "DireccionPos.h"
#include <fstream>

using namespace std;
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