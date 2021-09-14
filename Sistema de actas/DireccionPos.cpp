#include <iostream>
#include "DireccionPos.h"

using namespace std;

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
         << "4. Añadir Nuevo Criterio\n"
         << "5. Eliminar Criterio Existente\n"
         << "o. EXIT\n"
         << "OPC:";
         cin >> opc; cout << "\n ";
         switch(opc){
            case 1:
                verResumen();
                break;
            case 2:
                VerCriterio();
                break;
            case 3:
                editarCriterios();
                break;   
            case 0: 
               break;
         }
     } while (opc != 0);
     return;
}

void DireccionPos::crearActa(){
    string fecha, nombreEstudiante, nombreTrabajo, tipoTrabajo, nombreDirector, coNombreDirector, juradoUno, juradoDos;
    int ExisteCoDirector = -1, opc = -1, numeroActa;

    cout << "Creando una nueva de grado\n";
    cout << "Ingrese fecha: ";
    cin.ignore();
    getline(cin, fecha);
    cout << "Ingrese el numero del acta: ";
    cin >> numeroActa;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombreEstudiante);
    cout << "Ingrese el tipo de trabajo: ";
    getline(cin, tipoTrabajo);
    cout << "Ingrese el nombre del trabajo: ";
    getline(cin, nombreTrabajo);
    cout << "Ingrese el director: ";
    getline(cin, nombreDirector);
    cout << "¿Existe co-director?\n1. No\n2. Si\n";
    cin >> ExisteCoDirector;
    if (ExisteCoDirector == 1){
        coNombreDirector = "N/A";
    }
    else{
        cout << "Ingrese el nombre del co director: ";
        cin.ignore();
        getline(cin, coNombreDirector);
    }
    cout << "Ingrese el jurado 1: ";
    getline(cin, juradoUno);
    cout << "Ingrese el jurado 2: ";
    getline(cin, juradoDos);
    cout << "Acta creada, se muestra su informacion\n";
    Acta actaP(fecha, numeroActa,nombreEstudiante, nombreTrabajo, tipoTrabajo, nombreDirector, coNombreDirector, juradoUno, juradoDos, criterios);
    actaP.mostrarActa();
     cout << "¿Desea guardar el acta?\n1. No\n2. Si\n";
    cin >> opc;
    if (opc == 1){
        return;
    }
    else{
        listaActas.push_back(actaP);
        cout << "Acta creada y guardada.\n";
    }
}

void DireccionPos::VerActas(){
    for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++){
        pActas->mostrarActa();
        cout << "\n";
    }
}

void DireccionPos::verResumen(){
    for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++){
        cout << pActas->getNumeroActa() << "\n";
        cout << pActas->getFecha() << "\n";
        cout << pActas->getNombreAutor() << "\n";
        cout << pActas->getEstado() << "\n";
        cout << pActas->getCalificacionFinal() << "\n";
        cout << pActas->getJuradoUno() << "\n";
        cout << pActas->getJuradoDos() << "\n";
        cout << pActas->getDirector() << "\n";
        cout << "\n";
    }
}

void DireccionPos::VerCriterio(){
    int contador = 1;
    for (vector<Criterio>::iterator pCriterios = criterios.begin(); pCriterios != criterios.end(); pCriterios++){
        cout << "Criterio numero " << ++contador << ".\n";
        cout << pCriterios->getTitulo() << "\n";
        cout << pCriterios->getPonderado() << "\n";
    }
}

void DireccionPos::editarCriterios(){
    int opcion = -1;
    string titulo;
    float ponderacion;
    VerCriterio();
    cout << "Que criterio desea editar: ";
    cin >> opcion;
    cout << "Nuevo Titualo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "nueva ponderacion: ";
    cin >> ponderacion;
    criterios[opcion].setTitulo(titulo);
    criterios[opcion].setPonderado(ponderacion);
}

string intAString(int codigo){
  std::string text;
  ostringstream outs; 
  outs << codigo;
  text = outs.str();   
  return text;
}        

void DireccionPos::generarReporte(Acta acta){
    vector <Criterio> copiaCriterio = acta.getCriterios();
    std::string reporte = "Reporte" + intAString(acta.getNumeroActa()) + ".txt";  
    ofstream write (reporte.c_str());
    write << "ACTA: " << acta.getNumeroActa() << "\n\n";
    write << "ACTA DE EVALUACIÓN DE TRABAJO DE GRADO";
    write << "Autor:       " << acta.getNombreAutor() << "\n";
    write << "Director:    " << acta.getDirector() << "\n";
    write << "CoDirector:  " << acta.getCodirector() << "\n";
    write << "Enfasis en:   Sistemas y Computación \n";
    write << "Modalidad:   " << acta.getTipoTrabajo()<< "\n";
    write << "Jurado 1:   " << acta.getJuradoUno()<< "\n";
    write << "Jurado 2:   " << acta.getJuradoDos()<< "\n";

    write << "En atención al desarrollo de este Trabajo de Grado y al documento y sustentación que presentó el(la) autor(a)"  
    << "los Jurados damos las siguientes calificaciones parciales y observaciones (los criterios a evaluar y sus" <<
    "ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo de Grado de Maestría):";

    for (vector<Criterio>::iterator pCriterios = copiaCriterio.begin(); pCriterios != copiaCriterio.end(); pCriterios++){
		write << pCriterios->getTitulo() << "/n";
        float notafinal = (pCriterios->getCalificacionUno() + pCriterios->getCalificacionDos()) / 2;
        write << "Calificacion Parcial: " << notafinal << "          " << pCriterios->getPonderado() << "/n";
        write << "Observaciones: " << pCriterios->getObservacion() << "/n";
	}
    write.close();
}

