#include <iostream>
#include <string>
#include "DireccionPos.h"
#include "Acta.h"

enum tipoPersonal { noValido = 0, asistente, jurado, director };

tipoPersonal convert(const std::string& str){
    if(str == "noValido") return noValido;
    if(str == "Asistente") return asistente;
    else if(str == "Jurado") return jurado;
    else if(str == "Director") return director;
}

void DireccionPos::loginUsuario(string user){
    string loginID = "noValido";

    for (map<int,Personal>::iterator pPersonal = personalAdmin.begin();
		 pPersonal != personalAdmin.end(); pPersonal++){
        if ( user == pPersonal->second.getNombre() )
        loginID = pPersonal->second.getCargo();
	}

    int opc = convert(loginID);

    switch (opc){
    case asistente:
        mostrarMenuAsistente(); break;
    case jurado:
        mostrarMenuJurado(); break;
    case director:
        mostrarMenuDirector(); break;
    default:
        cout << "Usuario no valido"; break;
    }

}

void DireccionPos::mostrarMenuAsistente(){
     int opc;
     do{
        cout << "MENU ASISTENTE\n"
        << "1. Crear Acta\n"
        << "2. Ver Actas\n"
        << "0. EXIT\n"
        << "OPC:";
        cin >> opc; cout << "\n";
        switch(opc){
            case 1:
                crearActa();
                break;
            case 2:
                VerActas();
                break;
            case 0: 
                break;
        }
    } while (opc != 0);
}

void DireccionPos::mostrarMenuJurado(){
    int opc;
     do{
         cout << "\n\n MENU JURADO \n"
         << "1. Evaluar Tesis de Maestria\n"
         << "2. Ver Tesis Aprobadas y Reprobadas\n"
         << "o. EXIT\n"
         << "OPC:";
         cin >> opc; cout << "\n ";
         switch(opc){
              case 1:
               ; break;
              case 2:
               ; break;
              case 0: 
               break;
         }
     } while (opc != 0);
     return;
}

void DireccionPos::mostrarMenuDirector(){
    int opc;
     do{
         cout << "\n\n MENU DIRECTOR \n"
         << "1. Ver Resumen de Actas\n"
         << "2. Ver Criterios Actuales\n"
         << "3. Editar Criterios Actuales\n"
         << "o. EXIT\n"
         << "OPC:";
         cin >> opc; cout << "\n ";
         switch(opc){
              case 1:
               ; break;
              case 2:
               ; break;
              case 3:
               ; break;
              case 0: 
               break;
         }
     } while (opc != 0);
     return;
}

/*void mostrarCriterios(){

}*/

void DireccionPos::crearActa(){
    string fecha, numeroActa,nombreEstudiante, nombreTrabajo, tipoTrabajo, nombreDirector, coNombreDirector, juradoUno, juradoDos;
    int ExisteCoDirector = -1, opc = -1;
    cout << "Creando una nueva de grado\n";
    cout << "Ingrese fecha: ";
    cin >> fecha;
    cout << "Ingrese el numero del acta: ";
    cin >> numeroActa;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombreEstudiante;
    cout << "Ingrese el tipo de trabajo: ";
    cin >> tipoTrabajo;
    cout << "Ingrese el nombre del trabajo: ";
    cin >> nombreTrabajo;
    cout << "Ingrese el director: ";
    cin >> nombreDirector;
    cout << "¿Existe co-director?\n1. No\n2. Si\n";
    cin >> ExisteCoDirector;
    if (ExisteCoDirector == 1){
        coNombreDirector = "N/A";
    }
    else{
        cout << "Ingrese el nombre del co director: ";
        cin >> coNombreDirector;
    }
    cout << "Ingrese el jurado 1: ";
    cin >> juradoUno;
    cout << "Ingrese el jurado 2: ";
    cin >> juradoDos;
    cout << "Acta creada, se muestra su informacion\n";
    Acta actaP(fecha, numeroActa,nombreEstudiante, nombreTrabajo, tipoTrabajo, nombreDirector, coNombreDirector, juradoUno, juradoDos);
    actaP.mostrarActa();
     cout << "¿Desea guardar el acta?\n1. No\n2. Si\n";
    cin >> opc;
    if (opc == 1){
        return;
    }
    else{
        listaActas.push_back(actaP);
        cout << "Acta creada y guardada\n";
    }
}

void DireccionPos::VerActas(){
    
    for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++)
    {
        pActas->mostrarActa();
        cout << "\n";
    }
    
}