#include <iostream>
using namespace std;

struct Nodo {
    string nombre;
    bool esCarpeta;
    string contenido; // Solo si es archivo
    Nodo* padre;
    Nodo* primerHijo;
    Nodo* hermanoDerecho;

    Nodo(string n, bool carpeta, Nodo* p) {
        nombre = n;
        esCarpeta = carpeta;
        padre = p;
        primerHijo = NULL;
        hermanoDerecho = NULL;
        contenido = "";
    }
};

// Variables Globales de Navegación
Nodo* raiz = new Nodo("/", true, NULL);
Nodo* actual = raiz;

// --- Funciones de Utilidad ---

// Busca un hijo por nombre en el directorio actual
Nodo* buscarHijo(Nodo* dir, string nombre) {
    Nodo* temp = dir->primerHijo;
    while (temp != NULL) {
        if (temp->nombre == nombre) return temp;
        temp = temp->hermanoDerecho;
    }
    return NULL;
}

// Comando mkdir y touch (la lógica es similar)
void crearEntrada(string nombre, bool esCarpeta) {
    if (buscarHijo(actual, nombre)) {
        cout << "Error: Ya existe un archivo o carpeta con ese nombre.\n";
        return;
    }
    Nodo* nuevo = new Nodo(nombre, esCarpeta, actual);
    if (actual->primerHijo == NULL) {
        actual->primerHijo = nuevo;
    } else {
        Nodo* temp = actual->primerHijo;
        while (temp->hermanoDerecho != NULL) temp = temp->hermanoDerecho;
        temp->hermanoDerecho = nuevo;
    }
}

// Comando ls
void listar() {
    Nodo* temp = actual->primerHijo;
    while (temp != NULL) {
        cout << (temp->esCarpeta ? "[DIR] " : "[FILE] ") << temp->nombre << "  ";
        temp = temp->hermanoDerecho;
    }
    cout << endl;
}

// Comando cd
void cambiarDirectorio(string nombre) {
    if (nombre == "..") {
        if (actual->padre != NULL) actual = actual->padre;
    } else if (nombre == "/") {
        actual = raiz;
    } else {
        Nodo* destino = buscarHijo(actual, nombre);
        if (destino && destino->esCarpeta) {
            actual = destino;
        } else {
            cout << "Error: Directorio no encontrado.\n";
        }
    }
}

// Función para obtener la ruta actual (recursiva)
string obtenerRuta(Nodo* nodo) {
    if (nodo == raiz) return "/";
    return obtenerRuta(nodo->padre) + (nodo->padre == raiz ? "" : "/") + nodo->nombre;
}