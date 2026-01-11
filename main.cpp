#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    string comando, argumento;
    
    cout << "--- Terminal Unix V.1.0.1.0 ---" << endl;

    while (true) {
        cout << obtenerRuta(actual) << "> ";
        cin >> comando;

        if (comando == "exit") {
            break;
        } 
        else if (comando == "ls") {
            listar();
        } 
        else if (comando == "mkdir") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre de la carpeta.\n";
                cin.clear();
                cin.ignore(1000,'\n');
            } else {
                crearEntrada(argumento, true);
            }
        } 
        else if (comando == "touch") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre del archivo.\n";
                cin.clear();
                cin.ignore(1000,'\n');
            } else {
                crearEntrada(argumento, true);
            }
        } 
        else if (comando == "cd") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre del directorio.\n";
                cin.clear();
                cin.ignore(1000,'\n');
            } else {
                cambiarDirectorio(argumento);
            }
        }
        else {
            cout << "Comando no reconocido." << "\n";
        }
    }

    return 0;
}