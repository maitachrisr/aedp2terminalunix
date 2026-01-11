#include <iostream>
using namespace std;

struct Nodo {
    string nombre;
    bool esCarpeta;
    // string contenido; // reservado para futuras funciones
    Nodo* padre;
    Nodo* primerHijo;
    Nodo* hermanoDerecho;

    Nodo(string n, bool carpeta, Nodo* p) {
        nombre = n;
        esCarpeta = carpeta;
        padre = p;
        primerHijo = nullptr;
        hermanoDerecho = nullptr;
    }
};

// Variables Globales de Navegación
Nodo* raiz = new Nodo("/", true, nullptr);
Nodo* actual = raiz;

// --- Funciones de Utilidad ---

// Busca un hijo por nombre en el directorio actual
Nodo* buscarHijo(Nodo* dir, string nombre) {
    if (dir == nullptr) return nullptr;
    
    Nodo* temp = dir->primerHijo;
    while (temp != nullptr) {
        if (temp->nombre == nombre) return temp;
        temp = temp->hermanoDerecho;
    }
    return nullptr;
}

// Comando mkdir y touch (la lógica es similar)
void crearEntrada(string nombre, bool esCarpeta) {
    if (nombre == ""){
        cout << "Error: nombre invalido.\n"
    }
    
    if (buscarHijo(actual, nombre)) {
        cout << "Error: Ya existe un archivo o carpeta con ese nombre.\n";
        return;
    }

    Nodo* nuevo = new Nodo(nombre, esCarpeta, actual);

    if (actual->primerHijo == nullptr) {
        actual->primerHijo = nuevo;
    } else {
        Nodo* temp = actual->primerHijo;
        while (temp->hermanoDerecho != nullptr) 
            temp = temp->hermanoDerecho;
        
        temp->hermanoDerecho = nuevo;
    }
}

// Comando ls
void listar() {
    if (actual->primerHijo == nullptr) {
        cout << "(directorio vacio)\n";
        return;
    }

    Nodo* temp = actual->primerHijo;
    while (temp != NULL) {
        cout << (temp->esCarpeta ? "[DIR] " : "[FILE] ") 
            << temp->nombre << "  ";
        temp = temp->hermanoDerecho;
    }
    cout << endl;
}

// Comando cd
void cambiarDirectorio(string nombre) {
    
    if (nombre == "..") {
        if (actual->padre != nullptr) 
        actual = actual->padre;
    } 
    else if (nombre == "/") {
        actual = raiz;
    } 
    else {
        Nodo* destino = buscarHijo(actual, nombre);

        if (!destino) {
            cout << "Error: No existe el directorio.\n";
        } 
        else if (!destino->esCarpeta) {
            cout << "Error: No es una carpeta.\n";
        }
        else {
            actual = destino;
        }
    }
}

// Función para obtener la ruta actual (recursiva)
string obtenerRuta(Nodo* nodo) {
    if (nodo == raiz) return "/";

    return obtenerRuta(nodo->padre) + 
        (nodo->padre == raiz ? "" : "/") + 
        nodo->nombre;
}