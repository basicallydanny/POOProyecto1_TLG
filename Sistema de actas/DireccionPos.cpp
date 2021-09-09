#include "DireccionPos.h"
#include "Acta.h"

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
    cout << "Ingrese el director: ";
    cin >> nombreDirector;
    cout << "¿Existe co-director?\n1. No\n2. Si";
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
     cout << "¿Desea guardar el acta?\n1. No\n2. Si";
    cin >> opc;
    if (opc == 1){
        return;
    }
    else{
        listaActas.push_back(actaP);
        cout << "Acta creada y guardada\n";
    }
}