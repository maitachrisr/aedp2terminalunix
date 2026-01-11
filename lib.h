// HECHO POR CHRISTOPHER MAITA, ANGEL RUEDAS Y GERMAN MATHEO

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

Nodo* raiz = new Nodo("/", true, nullptr);
Nodo* actual = raiz;

// --- Funciones de utilidad ---

// busca un hijo por nombre en el directorio actual
Nodo* buscarHijo(Nodo* dir, string nombre) {
    if (dir == nullptr) return nullptr;
    
    Nodo* temp = dir->primerHijo;
    while (temp != nullptr) {
        if (temp->nombre == nombre) return temp;
        temp = temp->hermanoDerecho;
    }
    return nullptr;
}

// comando mkdir y touch
void crearEntrada(string nombre, bool esCarpeta) {
    if (nombre == ""){
        cout << "Error: nombre invalido.\n";
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

// comando ls
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

// comando cd
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

// funcion para obtener la ruta actual
string obtenerRuta(Nodo* nodo) {
    if (nodo == raiz) return "/";

    return obtenerRuta(nodo->padre) + 
        (nodo->padre == raiz ? "" : "/") + 
        nodo->nombre;
}

// funcion para eliminar un nodo y liberar su memoria recursivamente
void eliminarRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return;
    eliminarRecursivo(nodo->primerHijo);
    eliminarRecursivo(nodo->hermanoDerecho);
    delete nodo;
}

// comando del
void eliminarEntrada(string nombre) {
    if (nombre == "." || nombre == "..") return;

    Nodo* anterior = nullptr;
    Nodo* objetivo = actual->primerHijo;

    while (objetivo != nullptr && objetivo->nombre != nombre) {
        anterior = objetivo;
        objetivo = objetivo->hermanoDerecho;
    }

    if (!objetivo) {
        cout << "Error: No se encontro el archivo o carpeta.\n";
        return;
    }

    // desconectar el nodo
    if (anterior == nullptr) {
        actual->primerHijo = objetivo->hermanoDerecho;
    } else {
        anterior->hermanoDerecho = objetivo->hermanoDerecho;
    }

    objetivo->hermanoDerecho = nullptr; 
    eliminarRecursivo(objetivo);
    cout << "Eliminado correctamente.\n";
}

// comando mv
void moverEntrada(string nombre, string destinoNombre) {
    // busca el nodo a mover
    Nodo* anterior = nullptr;
    Nodo* objetivo = actual->primerHijo;
    while (objetivo != nullptr && objetivo->nombre != nombre) {
        anterior = objetivo;
        objetivo = objetivo->hermanoDerecho;
    }

    // busca el destino
    Nodo* destino = buscarHijo(actual, destinoNombre);

    if (!objetivo) {
        cout << "Error: No se encontro el origen.\n";
        return;
    }
    if (!destino || !destino->esCarpeta) {
        cout << "Error: El destino no existe o no es una carpeta.\n";
        return;
    }

    // desconectar de la ubicacion original
    if (anterior == nullptr) actual->primerHijo = objetivo->hermanoDerecho;
    else anterior->hermanoDerecho = objetivo->hermanoDerecho;

    // conectar al nuevo destino
    objetivo->padre = destino;
    objetivo->hermanoDerecho = destino->primerHijo;
    destino->primerHijo = objetivo;
}