#include "View.h"



void View::mostrarMenuGeneral(){
    int opc = -1;
    fstream file_obj;
    string usuarioA;

    do {
        cout << "1. Cargar Sistema \n";
        cout << "2. Nuevo Sistema \n";
        cout << "0. Salir \n";
        std::cout << "OPC: ";
        std::cin >> opc;

        switch (opc){
        case 1:
            file_obj.open("sistemaActas.txt", ios::out);
            file_obj.read((char*)&sistema, sizeof(sistema));
            file_obj.close();
            sistema.insertUsuario(sistema.nuevoUsuario());
            file_obj.open("sistemaActas.txt", ios::trunc);
            file_obj.write((char*)&sistema, sizeof(sistema));
            file_obj.close();
            
        break;
        case 2:
            file_obj.open("sistemaActas.txt", ios::trunc);
            cout<<"Ingrese el usuario: \n";
            cin>>usuarioA;
            sistema.loginUsuario(usuarioA);
            file_obj.write((char*)&sistema, sizeof(sistema));
            file_obj.close();
        break;
        }
    } 
    while (opc != 0);
}