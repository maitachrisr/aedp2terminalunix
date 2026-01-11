#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    string comando, argumento, destino;
    
    cout << "--- Terminal Unix V.1.0.1.2 ---" << endl;

    while (true) {
        cout << obtenerRuta(actual) << "> ";
        cin >> comando;

        if (comando == "exit") {
            // Recuerda que al salir debes guardar los cambios en el archivo original para la persistencia 
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
                cout << "Error: mv requiere origen y destino." << endl;
            } else {
                moverEntrada(argumento, destino);
            }
        }
        else {
            cout << "Comando no reconocido." << endl;
        }
    }

    return 0;
}
