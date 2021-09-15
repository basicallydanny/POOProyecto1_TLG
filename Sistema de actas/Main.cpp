#include "View.h"

int main(){
    View javeriana;
    DireccionPos sistema;
    string login;
    cout<<"Creacion de usuario director:\n";
    sistema.insertUsuario(sistema.nuevoUsuario());
    cout<<"Creacion de usuario asistente:\n";
    sistema.insertUsuario(sistema.nuevoUsuario());
    cout<<"Creacion de usuario jurado:\n";
    sistema.insertUsuario(sistema.nuevoUsuario());
    cout<<"Ingrese el nombre del director: \n";
    cin>>login;
    sistema.loginUsuario(login);
    cout<<"Ingrese el nombre del asistente: \n";
    cin>>login;
    sistema.loginUsuario(login);
    cout<<"Ingrese el nombre del jurado: \n";
    cin>>login;
    sistema.loginUsuario(login);
    //javeriana.mostrarMenuGeneral();
    system("pause");
    return 0;
}
