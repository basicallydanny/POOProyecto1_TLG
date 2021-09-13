#include "View.h"

View::View(){}

void View::mostrarMenuGeneral(){
    int opc = -1;
    do {
        cout << "1. Cargar Sistema \n";
        cout << "2. Nuevo Sistema \n";
        cout << "0. Salir \n";
        std::cout << "OPC: ";
        std::cin >> opc;

        switch (opc){
        case 1:
            // TODO: guardar actas y personal
        case 2:
            // TODO: cargar actas y personal
        }
    } while (opc != 0);
}