#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    string comando, argumento;
    
    cout << "--- Unix Terminal Sim v1.0.0.0 ---" << endl;

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
            cin >> argumento;
            crearEntrada(argumento, true);
        } 
        else if (comando == "touch") {
            cin >> argumento;
            crearEntrada(argumento, false);
        } 
        else if (comando == "cd") {
            cin >> argumento;
            cambiarDirectorio(argumento);
        }
        else {
            cout << "Comando no reconocido." << endl;
        }
    }

    return 0;
}