#include "View.h"

void View::mostrarMenuGeneral(){
    int opc = -1;
    ofstream escribir;
    ifstream leer;

    string usuarioA;

    do {
        cout << "1. Nuevo Sistema \n";
        cout << "2. Cargar Sistema \n";
        cout << "0. Salir \n";
        std::cout << "OPC: ";
        std::cin >> opc;
        switch (opc){
        case 1:
            leer.open("sistemaActas.txt", ios::in);
            leer.seekg(0);
            leer.read((char*)&sistema, sizeof(sistema));
            leer.close();
            sistema.insertUsuario(sistema.nuevoUsuario());
            escribir.open("sistemaActas.txt", ios::trunc);
            escribir.clear();
            escribir.write((char*)&sistema, sizeof(sistema));
            escribir.close();
        break;
        case 2:
            cout<<"Ingrese el usuario: \n";
            cin>>usuarioA;
            sistema.loginUsuario(usuarioA);
            escribir.open("sistemaActas.txt", ios::trunc);
            escribir.write((char*)&sistema, sizeof(sistema));
            escribir.close();
        break;
        }
    } 
    while (opc != 0);
}