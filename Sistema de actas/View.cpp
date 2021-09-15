#include "View.h"

void View::mostrarMenuGeneral(){
    int opc = -1;
    fstream archivo;
    string usuarioA;
    archivo.open("archivo.txt", ios::out);
    archivo.close();

    do {
        cout << "1. Nuevo Sistema \n";
        cout << "2. Cargar Sistema \n";
        cout << "0. Salir \n";
        std::cout << "OPC: ";
        std::cin >> opc;
        switch (opc){
        case 1:

            cout<<"Creacion de usuario jurado:\n";
            sistema.insertUsuario(sistema.nuevoUsuario());
            cout<<"Creacion de usuario asistente:\n";
            sistema.insertUsuario(sistema.nuevoUsuario());
            cout<<"Creacion de usuario director:\n";
            sistema.insertUsuario(sistema.nuevoUsuario());
            cout<<"Ingrese el nombre del usuario que ingresara: \n";
            cin>>usuarioA;
            sistema.loginUsuario(usuarioA);

            archivo.open("archivo.txt", ios::app);
            archivo.write((char*)&sistema, sizeof(sistema));
            archivo.close();
        break;
        case 2:
            archivo.open("archivo.txt", ios::in);
            archivo.read((char*)&sistema, sizeof(sistema));
            archivo.close();

            cout<<"Ingrese el nombre del usuario que ingresara: \n";
            cin>>usuarioA;
            sistema.loginUsuario(usuarioA);

            archivo.open("archivo.txt", ios::trunc);
            archivo.write((char*)&sistema, sizeof(sistema));
            archivo.close();
        break;
        }
    } 
    while (opc != 0);
}