#include <iostream>
#include "DireccionPos.h"

using namespace std;

enum tipoPersonal { jurado = 1, director, asistente };

tipoPersonal convert(const std::string& str){
    if(str == "Asistente") return asistente;
    else if(str == "Jurado") return jurado;
    else if(str == "Director") return director;
}

Personal DireccionPos::nuevoUsuario(){
    string nombre;
    int cargo;
    Personal usuarioNuevo;

    cout<<"Ingrese el nombre de usuario: \n";
    cin>>nombre;
    fflush(stdin);
    usuarioNuevo.setNombre(nombre);
    cout<<"Que cargo tiene?\n1.Jurado\n2.Director\n3.Asistente\n";
    cin>>cargo;
    switch (cargo){
    case 1:
        usuarioNuevo.setCargo("Jurado");
        break;
    case 2:
        usuarioNuevo.setCargo("Director");
        break;
    case 3:
        usuarioNuevo.setCargo("Asistente");
        break;
    default:
        cout<<"Entrada no valida\n";
        break;
    }
    return usuarioNuevo;
}

void DireccionPos::insertUsuario(Personal usuario){
    this->personalAdmin.insert(std::pair<int,Personal>(cantUsuarios++,usuario));
}

void DireccionPos::loginUsuario(string user){
    string loginID;
    for (map<int,Personal>::iterator pPersonal = personalAdmin.begin();
		pPersonal != personalAdmin.end(); pPersonal++){
        if ( cadenaAMinuscula(user) == cadenaAMinuscula(pPersonal->second.getNombre()) ){
            loginID = pPersonal->second.getCargo();
            cout << "Identificado como:" << loginID;
        }
	}
    int opc = convert(loginID);
    switch (opc){
    case 1:
        mostrarMenuJurado(); break;
    case 2: 
        mostrarMenuDirector(); break;
    case 3:
        mostrarMenuAsistente(); break;
    default:
        cout << "Usuario no valido\n"; break;
    }
}

void DireccionPos::mostrarMenuAsistente(){
     int opc;
     do{
        while ((getchar()) != '\n');
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
         while ((getchar()) != '\n');
         cout << "\n MENU JURADO \n"
         << "1. Evaluar Tesis de Maestria\n"
         << "2. Ver Tesis Aprobadas y Reprobadas\n"
         << "0. EXIT\n"
         << "OPC:";
         cin >> opc; cout << "\n ";
         switch(opc){
            case 1:
                evaluarActa();
            break;
            case 2:
                verReprobadosyAprobados();
            break;
            case 0: 
            break;
         }
     } while (opc != 0);
     return;
}

void DireccionPos::mostrarMenuDirector(){
    int opc = -1;
     do{
         while ((getchar()) != '\n');
         cout << "\n MENU DIRECTOR \n"
         << "1. Ver Resumen de Actas\n"
         << "2. Ver Criterios Actuales\n"
         << "3. Editar Criterios Actuales\n"
         << "4. Anadir Nuevo Criterio\n"
         << "5. Eliminar Criterio Existente\n"
         << "6. Anadir Nuevo Personal\n"
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
            case 4:
                newCriterio();
            break;
            case 5:
                eliminarCriterio(); 
            break;
            case 6: 
                nuevoUsuario();
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
    cout << "Creando una nueva acta de grado\n";
    cout << "Ingrese fecha: ";
    cin.ignore();
    getline(cin, fecha);
    cout << "Ingrese el numero del acta: ";
    cin >> numeroActa;
    while ((getchar()) != '\n');
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombreEstudiante);
    while ((getchar()) != '\n');
    cout << "Ingrese el tipo de trabajo: ";
    getline(cin, tipoTrabajo);
    while ((getchar()) != '\n');
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
    while ((getchar()) != '\n');
    cout << "Ingrese el jurado 1: ";
    getline(cin, juradoUno);
    while ((getchar()) != '\n');
    cout << "Ingrese el jurado 2: ";
    getline(cin, juradoDos);
    cout << "Acta creada, se muestra su informacion:\n";
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
    int contadorActa = 1;
    for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++){
        cout << "Acta #" << ++contadorActa << "\n";
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
    if (opcion < 1 || opcion > criterios.size()){
        return;   
    }
    else{
        cout << "Nuevo Titulo: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "nueva ponderacion: ";
        cin >> ponderacion;
        criterios[opcion - 1].setTitulo(titulo);
        criterios[opcion - 1].setPonderado(ponderacion);
    }
}

void DireccionPos::newCriterio(){
    string titulo;
    float ponderacion;
    cout << "Ingrese el titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese la ponderacion: ";
    cin >> ponderacion;
    Criterio critPlus;
    critPlus.setTitulo(titulo);
    critPlus.setPonderado(ponderacion);
    criterios.push_back(critPlus);
    cout << "Criterio creado y actualizados\n"; 
    for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++){
        pActas->getCriterios().push_back(critPlus);
    } 
}

void DireccionPos::eliminarCriterio(){
    int opcion = -1;
    VerCriterio();
    cout << "Que criterio desea eliminar: ";
    cin >> opcion;
    if (criterios.size() < opcion && opcion > 0){
        criterios.erase(criterios.begin()+ opcion - 1);
        cout << "Criterio eliminado y actualizados\n"; 
        for (vector<Acta>::iterator pActas = listaActas.begin(); pActas != listaActas.end(); pActas++){
            pActas->getCriterios().erase(criterios.begin()+ opcion - 1);
        } 
    }else{
        cout << "Indice Invalido\n";
        return;
    }
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

void DireccionPos::evaluarActa(){
    int opcion = -1;
    int exportar = -1;
    float calificacionUno = 0, calificacionDos = 0;
    string observacion;
    VerActas();
    cout << "Que acta va a evaluar: ";
    cin >> opcion;
    if (opcion > listaActas.size() || opcion < 1){
        cout << "Indice invalido";
        return;
    }
    else{
        for (vector<Criterio>::iterator pCriterio = listaActas[opcion].getCriterios().begin(); pCriterio != listaActas[opcion].getCriterios().end(); pCriterio++ ){
            cout << "Criterio: " << pCriterio->getTitulo() << "\n";
            cout << "Ingrese la nota del jurado " << listaActas[opcion].getJuradoUno() << ": ";
            cin >> calificacionUno;
            cout << "Ingrese la nota del jurado " << listaActas[opcion].getJuradoDos() << ": ";
            cin >> calificacionDos;
            cout << "Ingrese la observacion: ";
            cin.ignore();
            getline(cin, observacion);
            pCriterio->setObservacion(observacion);
            pCriterio->setCalificacionUno(calificacionUno);
            pCriterio->setCalificacionDos(calificacionDos);
        }
    listaActas[opcion].obtenerCalificacionFinal(); 
    generarReporte(listaActas[opcion]);      
    cout << "La nota es de: " << listaActas[opcion].getCalificacionFinal() << "El trabajo es: " << listaActas[opcion].getEstado() << "\n"; 
    }
    cout << "\nDesea generar un reporte del acta?\n 1. Si \n2. No\nOPC:";
    cin >> exportar;
    if ( exportar == 1 ){
        generarReporte(listaActas[opcion]);
    }
}

void DireccionPos::verReprobadosyAprobados(){
    cout << "Aprobados: \n";
    for (vector<Acta>::iterator pActa = listaActas.begin(); pActa != listaActas.end(); pActa++){
        if (pActa->getEstado() == "Aprobado"){
            pActa->mostrarActa();
        }
    }
    cout << "Reprobados: \n";
    for (vector<Acta>::iterator pActa = listaActas.begin(); pActa != listaActas.end(); pActa++){
        if (pActa->getEstado() == "Reprobado"){
            pActa->mostrarActa();
        }
    }
}

string DireccionPos::cadenaAMinuscula(string cadena){
    string cadenaMinuscula;
    for (int i = 0; i < cadena.size(); i++){
        cadenaMinuscula.push_back(tolower(cadena[i]));
    }
    return cadenaMinuscula;
}