// HECHO POR CHRISTOPHER MAITA, ANGEL RUEDAS Y GERMAN MATHEO

#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    string comando, argumento, destino;
    
    cout << "--- Terminal Unix V.1.0.2.0 ---" << endl;

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
        else if (comando == "mv") {
            if (!(cin >> argumento >> destino)) {
                cout << "Error: faltan argumentos (mv <nombre> <destino>)." << endl;
            } else {
                moverEntrada(argumento, destino);
            }
        }
        else if (comando == "del") {
            if (!(cin >> argumento)) {
                cout << "Error: falta el nombre a eliminar." << endl;
            } else {
                eliminarEntrada(argumento);
            }
        }
        else {
            cout << "Comando no reconocido." << endl;
        }
    }

    return 0;
}
