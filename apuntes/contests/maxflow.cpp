#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101       

#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1000; // Definir un valor máximo para la cantidad de nodos
int grafo_residual[MAX_NODES][MAX_NODES]; // matriz de capacidades residuales
int maxFlowResult, flowCurrent, sourceNode, sinkNode; // max_flow, flujo actual, nodo fuente, nodo sumidero
vector<int> parent; // parent almacena el árbol BFS

void findAugmentingPath(int currentNode, int minCapacity) { 
    if (currentNode == sourceNode) { 
        flowCurrent = minCapacity; 
        return; 
    } 
    else if (parent[currentNode] != -1) { 
        findAugmentingPath(parent[currentNode], min(minCapacity, grafo_residual[parent[currentNode]][currentNode])); 
        grafo_residual[parent[currentNode]][currentNode] -= flowCurrent; 
        grafo_residual[currentNode][parent[currentNode]] += flowCurrent; 
    } 
}

int calculateMaxFlow() {
    maxFlowResult = 0;
    while (true) { 
        flowCurrent = 0;
        vector<int> distance(MAX_NODES, INT_MAX); 
        distance[sourceNode] = 0; 
        queue<int> nodeQueue; 
        nodeQueue.push(sourceNode);
        parent.assign(MAX_NODES, -1);
        
        // BFS para encontrar el camino de aumento
        while (!nodeQueue.empty()) {
            int currentNode = nodeQueue.front(); 
            nodeQueue.pop();
            if (currentNode == sinkNode) break;
            for (int nextNode = 0; nextNode < MAX_NODES; nextNode++) {
                if (grafo_residual[currentNode][nextNode] > 0 && distance[nextNode] == INT_MAX) {
                    distance[nextNode] = distance[currentNode] + 1;
                    nodeQueue.push(nextNode);
                    parent[nextNode] = currentNode;
                }
            }
        }
        
        findAugmentingPath(sinkNode, INT_MAX); 
        if (flowCurrent == 0) break;
        maxFlowResult += flowCurrent;
    }
    return maxFlowResult;
}

int main() {
    // Configurar el grafo con las capacidades y asignar los valores de sourceNode (nodo fuente) y sinkNode (nodo sumidero)
    // grafo_residual[i][j] debe representar la capacidad del nodo i al nodo j

    // Ejemplo de configuración de un grafo (esto se puede modificar según el problema):
    sourceNode = 0; // Nodo fuente
    sinkNode = 5; // Nodo sumidero
    grafo_residual[0][1] = 10;
    grafo_residual[0][2] = 5;
    grafo_residual[1][3] = 10;
    grafo_residual[2][4] = 7;
    grafo_residual[3][5] = 10;
    grafo_residual[4][5] = 10;

    // Llamada a la función para obtener el flujo máximo
    cout << calculateMaxFlow() << endl; 

    return 0;
}
