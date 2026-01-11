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
                cout << "Error: falta el nombre de la carpeta." << endl;
            } else {
                crearEntrada(argumento, true);
            }
        } 
        else if (comando == "touch") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre del archivo." << endl;
            } else {
                crearEntrada(argumento, false);
            }
        } 
        else if (comando == "cd") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre del directorio." << endl;
            } else {
                cambiarDirectorio(argumento);
            }
        }
        else {
            cout << "Comando no reconocido." << endl;
        }
    }

    return 0;
}