#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct contactoEmail{
    string nombre;
    char sexo;
    int edad;
    int telefono;
    string email;
    string nacionalidad;
};

void agregarContacto(){

}

void eliminarContacto(){

}

void mostrarListadoGeneral(){

}

void mostrarListadoPorServidor(){

}

void menu(){
    char opcion;
    cout << "Programa que simula un Gestor de Contactos\n";
    do{
        cout << "a) Agregar un contacto" << endl;
        cout << "b) Eliminar un contacto" << endl;
        cout << "c) Mostrar listado general de contactos registrados hasta el momento" << endl;
        cout << "d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas" << endl;
        cout << "e) Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion){
            case 'a':
                agregarContacto();
                break;
            case 'b':
                eliminarContacto();
                break;
            case 'c':
                mostrarListadoGeneral();
                break;
            case 'd':
                mostrarListadoPorServidor();
                break;
            case 'e':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Error, ingrese una letra correcta..." << endl;
                break;
        }
    }while (opcion != 'e');

    cout << "Fin del programa..." << endl;
}

int main (){
    SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}