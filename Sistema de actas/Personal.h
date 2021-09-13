//Guardas 
#ifndef PERSONAL_H
#define PERSONAL_H
//Incluir librerias 
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
//Clase
class Personal{
private:
 string nombre;
 string cargo;
public:
    void setNombre(string nombre);
    string getNombre();
    void setCargo(string cargo);
    string getCargo();
};



#endif