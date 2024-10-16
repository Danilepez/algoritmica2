#include <bits/stdc++.h>
#include <chrono>  // Para medir el tiempo
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
#define MAX_N 101  // Máximo número de nodos

int grafo[MAX_N][MAX_N];  // Capacidad del grafo
int path[MAX_N];          // Para guardar el camino aumentante

// Algoritmo Ford-Fulkerson con DFS incluido en el mismo flujo
int maxFlow(int s, int t,int &iteraciones) {
    int flujoMaximo = 0;
    iteraciones = 0;

    while (true) {
        iteraciones++;
        // DFS O(V + E)
        memset(path, -1, sizeof(path));  // Inicializar el camino como no visitado
        stack<int> pilita;
        vector<int> visitados(MAX_N, 0);  // Vector de visitados
        pilita.push(s);
        path[s] = s;

        // DFS para encontrar el camino aumentante
        while (!pilita.empty() && path[t] == -1) {  // Mientras no encontremos un camino hasta t
            int nodoActual = pilita.top();
            pilita.pop();

            if (!visitados[nodoActual]) {
                visitados[nodoActual] = 1;

                // Explorar los vecinos del nodo actual
                for (int i = 0; i < MAX_N; i++) {
                    if (grafo[nodoActual][i] > 0 && path[i] == -1) {  // Si hay capacidad y no ha sido visitado
                        pilita.push(i);
                        path[i] = nodoActual;  // Guardar el predecesor
                    }
                }
            }
        }

        // Si no encontramos un camino hasta el sumidero, terminamos
        if (path[t] == -1) {
            break;
        }

        // Encontrar el flujo mínimo a lo largo del camino encontrado
        int flujoMinimo = INT_MAX;
        for (int from = path[t], to = t; from != to; from = path[to = from]) {
            flujoMinimo = min(flujoMinimo, grafo[from][to]);  // Encontrar el mínimo flujo en el camino
        }

        // Actualizar las capacidades residuales en el grafo
        for (int from = path[t], to = t; from != to; from = path[to = from]) {
            grafo[from][to] -= flujoMinimo;  // Reducir capacidad en el grafo
            grafo[to][from] += flujoMinimo;  // Aumentar capacidad en el grafo residual
        }

        flujoMaximo += flujoMinimo;  // Sumar el flujo mínimo al flujo máximo total
    }

    return flujoMaximo;
}
int main() {
    input;
    int nodes, aristas, iteraciones = 0;
    
    // Leer el número de nodos y aristas
    while (cin >> nodes >> aristas) {
        int s = 1;  // Nodo fuente (puedes modificarlo según sea necesario)
        int t = nodes;  // Nodo sumidero (el último nodo, puede ajustarse también)
        memset(grafo, 0, sizeof(grafo));

        // Leer cada arista (from, to, capacidad)
        for (int i = 0; i < aristas; i++) {
            int from, to, capacidad;
            cin >> from >> to >> capacidad;
            grafo[from][to] = capacidad;  // Configurar la capacidad de la arista
            grafo[to][from] = 0;      // Configurar la capacidad residual de la arista
        }

        // Calcular el flujo máximo desde el nodo fuente (s) hasta el sumidero (t)
        cout<<"Flujo máximo: " << maxFlow(s,t,iteraciones)<<endl;
        cout << "Número de iteraciones: " << iteraciones << endl;
    }


    // Iniciar el cronómetro
    auto start = chrono::high_resolution_clock::now();

    // Aquí va tu código principal o la función que deseas medir
    // Ejemplo:
    // maxFlow(s, t);

    // Detener el cronómetro
    auto end = chrono::high_resolution_clock::now();

    // Calcular la duración
    chrono::duration<double> duration = end - start;
    
    // Imprimir el tiempo en segundos
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;


    return 0;
}
