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

void agregarContacto(contactoEmail cont[], int &contadorContactos){
    cout << "\nIngrese el nombre del contacto número " << contadorContactos + 1 << ":" << endl;
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

void eliminarContacto(contactoEmail cont[], int &contadorContactos){
    if (contadorContactos != 0){
        int indice;
        cout << "\nIngrese el número del contacto que desea eliminar:" << endl;
        cin >> indice;
        if (indice > 0 && indice <= contadorContactos){
            for (int i = indice - 1; i < contadorContactos - 1; i++){
                cont[i] = cont[i + 1];
            }
            contadorContactos--;
            cout << "Contacto eliminado correctamente." << endl;
        }else {
            cout << "\nNúmero de contacto no encontrado..." << endl;
        }
    }else {
        cout << "\nUsted todavía no agregó ningún contacto" << endl;
    }
}

void mostrarListadoGeneral(contactoEmail cont[], int contadorContactos){
    if (contadorContactos != 0){
        cout << "\nLos contactos actuales son:\n\n";
        for (int i = 0; i < contadorContactos; i++){
            cout << "Contacto número " << i + 1 << endl;
            cout << "Nombre: " << cont[i].nombre << endl;
            cout << "Sexo: " << cont[i].sexo << endl;
            cout << "Edad: " << cont[i].edad << endl;
            cout << "Teléfono: " << cont[i].telefono << endl;
            cout << "Email: " << cont[i].email << endl;
            cout << "Nacionalidad: " << cont[i].nacionalidad << endl;
        }
    }else {
        cout << "\nUsted todavía no agregó ningún contacto..." << endl;
    }
}

void mostrarListadoPorServidor(contactoEmail cont[], int contadorContactos){

    if (contadorContactos != 0){
        int indices[100];
        for (int i = 0; i < contadorContactos; i++){
            indices[i] = i;
        }
        cout << "\nListado de contactos ordenados por servidor de correo:\n\n";
        for (int i = 0; i < contadorContactos - 1; i++){
            for (int j = i + 1; j < contadorContactos; j++){
                int posicion1 = 0;
                while (cont[indices[i]].email[posicion1] != '@'){
                    posicion1++;
                }
                int posicion2 = 0;
                while (cont[indices[j]].email[posicion2] != '@'){
                    posicion2++;
                }
                int a = posicion1 + 1;
                int b = posicion2 + 1;
                bool mayor = false;
                while (cont[indices[i]].email[a] != '\0' && cont[indices[j]].email[b] != '\0'){
                    if (cont[indices[i]].email[a] > cont[indices[j]].email[b]){
                        mayor = true;
                        break;
                    } else if (cont[indices[i]].email[a] < cont[indices[j]].email[b]){
                        mayor = false;
                        break;
                    }
                    a++;
                    b++;
                }
                if (!mayor && cont[indices[i]].email[a] != '\0' && cont[indices[j]].email[b] == '\0') {
                    mayor = true;
                }
                if (mayor){
                    int temp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = temp;
                }
            }
        }
    }else {
        cout << "\nUsted todavía no agregó ningún contacto..." << endl;
    }
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
                agregarContacto(contactos, contadorContactos);
                break;
            case 'b':
                eliminarContacto(contactos, contadorContactos);
                break;
            case 'c':
                mostrarListadoGeneral(contactos, contadorContactos);
                break;
            case 'd':
                mostrarListadoPorServidor(contactos, contadorContactos);
                break;
            case 'e':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Error, ingrese una letra correcta..." << endl;
                break;
        }
        cin.ignore();
        cin.get();
        system("cls");
    }while (opcion != 'e');

    cout << "Fin del programa..." << endl;
}

int main (){
    menu();
    return 0;
}