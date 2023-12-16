#include<iostream>
#include<cstring>

using namespace std;

// Declaración de constantes
const int MAX_NODOS = 100;

// Declaración de variables globales
int grafo[MAX_NODOS][MAX_NODOS];
int numNodos = 0;

// Declaración de funciones
void inicializarGrafo();
void insertarNodo();
void eliminarNodo();
void insertarArista(int origen, int destino);
void eliminarArista(int origen, int destino);
bool existeCamino(int origen, int destino);
bool esSimetrico();
void mostrarMatrizAdyacencia();;


int main() {
    // Inicializar grafo
    inicializarGrafo();

    // Mostrar menú y solicitar opción al usuario
    char opcion;
    do {
    	
    	system("cls");
    	
    	cout << "\nPC1 DE ALGORITMOS - EDWIN FLORES"<<endl;
    	cout << "\n----------------------------------------"<<endl;
        cout << "Menu de opciones:\n";
        cout << "----------------------------------------"<<endl;
        
        cout << "a) Determinar si entre nodos existe un camino\n";
        cout << "b) Insertar un nodo en el grafo\n";
        cout << "c) Eliminar un nodo del grafo\n";
        cout << "d) Determinar si el grafo es asimetrico o simetrico\n";
        cout << "e)crear una matriz de adyacencia"<<endl;
        cout << "f) Salir\n";

        cout << "----------------------------------------"<<endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'a': {
                // Solicitar nodos de origen y destino
                int origen, destino;
                cout << "Digite el nodo de origen: ";
                cin >> origen;
                cout << "Digite el nodo de destino: ";
                cin >> destino;

                // Verificar si existe un camino entre los nodos
                if (existeCamino(origen, destino)) {
                    cout << "Sí existe un camino entre los nodos " << origen << " y " << destino << endl;
                } else {
                    cout << "No existe un camino entre los nodos " << origen << " y " << destino << endl;
                }
                
                
                system("pause");
                
                break;
            }
            case 'b': {
                // Insertar un nodo en el grafo
                insertarNodo();
                
                
                system("pause");
                
                break;
            }
            case 'c': {
                // Eliminar un nodo del grafo
                eliminarNodo();
                
                system("pause");
                break;
            }
            case 'd': {
                // Determinar si el grafo es asimétrico o simétrico
                if (esSimetrico()) {
                    cout << "El grafo es simetrico" << endl;
                } else {
                    cout << "El grafo es asimetrico" << endl;
                }
                
                system("pause");
                break;
            }
            case 'e':{
            	//Mostrar matriz de adyacencia
            	mostrarMatrizAdyacencia();
            	system("pause");
            case 'f': {
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                // Opción inválida
                cout << "Opcion invalida, intente de nuevo" << endl;
                
                system("pause");
                break;
            }
        }
    } 

    
}while (opcion != 'e');
return 0;
}

void inicializarGrafo() {
    // Valores de la matriz de adyacencia
    int valores[MAX_NODOS][MAX_NODOS] = {{0, 0, 0, 1},
                                         {1, 0, 1, 1},
                                         {1, 0, 0, 1},
                                         {0, 0, 1, 0}};

    // Copiar los valores a la matriz del grafo
    for (int i = 0; i < numNodos; i++) {
        for (int j = 0; j < numNodos; j++) {
            grafo[i][j] = valores[i][j];
        }
    }
}


void mostrarMatrizAdyacencia() {
    // Mostrar la matriz de adyacencia
    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < numNodos; i++) {
        for (int j = 0; j < numNodos; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

void insertarNodo() {
    // Verificar si se ha alcanzado el máximo de nodos permitidos
    if (numNodos == MAX_NODOS) {
        cout << "Error: se ha alcanzado el máximo de nodos permitidos" << endl;
        return;
    }

    // Insertar el nuevo nodo en la posición siguiente al último nodo existente
    numNodos++;
    cout << "Se ha insertado el nodo " <<numNodos << " correctamente" << endl;
}

	void eliminarNodo() {
	// Verificar si hay nodos en el grafo
	if (numNodos == 0) {
	cout << "Error: no hay nodos en el grafo" << endl;
	return;
	}

// Solicitar el nodo a eliminar
int nodoEliminar;
cout << "Digite el numero del nodo a eliminar: ";
cin >> nodoEliminar;

// Verificar si el nodo existe
if (nodoEliminar < 1 || nodoEliminar > numNodos) {
    cout << "Error: el nodo " << nodoEliminar << " no existe" << endl;
    return;
}

// Eliminar el nodo del grafo
for (int i = nodoEliminar; i < numNodos; i++) {
    // Copiar la fila i+1 en la fila i
    memcpy(grafo[i], grafo[i+1], sizeof(grafo[i]));

    // Mover la columna i+1 a la columna i
    for (int j = i+1; j <= numNodos; j++) {
        grafo[j-1][i] = grafo[j][i+1];
    }
}

// Actualizar el número de nodos en el grafo
numNodos--;
cout << "Se ha eliminado el nodo " << nodoEliminar << " correctamente" << endl;


}

void insertarArista(int origen, int destino) {
// Verificar si los nodos existen
if (origen < 1 || origen > numNodos || destino < 1 || destino > numNodos) {
cout << "Error: los nodos especificados no existen" << endl;
return;
}

// Insertar la arista
grafo[origen-1][destino-1] = 1;
cout << "Se ha insertado la arista (" << origen << "," << destino << ") correctamente" << endl;
}

void eliminarArista(int origen, int destino) {
// Verificar si los nodos existen
if (origen < 1 || origen > numNodos || destino < 1 || destino > numNodos) {
cout << "Error: los nodos especificados no existen" << endl;
return;
}

// Eliminar la arista
grafo[origen-1][destino-1] = 0;
cout << "Se ha eliminado la arista (" << origen << "," << destino << ") correctamente" << endl;


}

bool existeCamino(int origen, int destino) {
// Verificar si los nodos existen
if (origen < 1 || origen > numNodos || destino < 1 || destino > numNodos) {
cout << "Error: los nodos especificados no existen" << endl;
return false;
}

// Verificar si hay un camino directo entre los nodos
if (grafo[origen-1][destino-1] == 1) {
    return true;
}

// Verificar si hay un camino indirecto entre los nodos
bool visitados[numNodos];
memset(visitados, false, sizeof(visitados));
visitados[origen-1] = true;

for (int i = 0; i < numNodos; i++) {
    if (grafo[origen-1][i] == 1 && !visitados[i]) {
        visitados[i] = true;
        if (i == destino-1 || existeCamino(i+1, destino)) {
            return true;
        }
    }
}
return false;
}
bool esSimetrico() {
for (int i = 0; i < numNodos; i++) {
for (int j = i+1; j < numNodos; j++) {
if (grafo[i][j] != grafo[j][i]) {
return false;
}
}
}

return true;

}




	

