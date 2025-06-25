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

void agregarContacto(int &contadorContactos, contactoEmail cont[]){
    cout << "Ingrese el nombre del contacto " << contadorContactos + 1 << ":" << endl;
    cin.ignore();
    getline(cin, cont[contadorContactos].nombre);
    cout << "Ingrese el sexo (m/f):" << endl;
    cin >> cont[contadorContactos].sexo;
    cout << "Ingrese la edad:" << endl;
    cin >> cont[contadorContactos].edad;
    cout << "Ingrese el número:" << endl;
    cin >> cont[contadorContactos].telefono;
    cout << "Ingrese el email:" << endl;
    cin.ignore();
    getline(cin, cont[contadorContactos].email);
    cout << "Ingrese la nacionalidad:" << endl;
    getline(cin, cont[contadorContactos].nacionalidad);
    contadorContactos++;
}

void eliminarContacto(){

}

void mostrarListadoGeneral(){

}

void mostrarListadoPorServidor(){

}

void menu(){
    SetConsoleOutputCP(CP_UTF8);
    const int MAX_CONTACTOS = 100;
    contactoEmail contactos[MAX_CONTACTOS];
    int contadorContactos = 0;
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
                agregarContacto(contadorContactos, contactos);
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
    menu();
    return 0;
}