//MST: Minimum Spanning Tree (Árbol de Expansión Mínimo)
//Se utiliza para encontrar un arbol que conecte todos los nodos tal que las aristas tengan el menor peso posible
//primero se ordenan todas las aristas
//1) Sort(Aristas por el peso)
//2) Unir las aristas que no formas ciclo
//3) Repetir hasta que todos los nodos esten conectados

#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 10000    // Maximo numero de vertices o nodos

using namespace std; 

// parent y rango sirven para el union find 
int parent[MAX_N];
int rango[MAX_N];

int n, m; // n numero de nodos y m numero de aristas 

void init() {
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ 
    int origen;
    int destino; 
    double peso; 
    Arista(){}
    // sobrecarga del operador < para ordenar las aristas
    // sort 
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N]; 

Arista MST[MAX_N]; // n-1 aristas 

int numAristasArbol;
double kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    double peso;

    double total = 0; // total del arbol de expansión minimo 

    numAristasArbol = 0; // contar el numero de aristas 

    init(); // Iniciar el union Find 
    // sort(array, array+n)
    // array = [a,b,c,d,e]
    // n = 5
    // sort(array, array+5)
    sort(aristas,aristas + nroAristas); // ordena las aristas
    // sor utiliza el operador < 

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { // estos 2 dos nodos forman un ciclo 
            total += peso; 
            unionRango(origen,destino);  // unimos los nodos
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            numAristasArbol++; // incrementados la posicion para la futura arista
            
        }
    }
    return total;
}

bool tieneCiclo(int nroNodos, vector<pair<int, int>>& aristas, int nroAristas) {
    init();  // Inicializar la estructura de union-find

    for (int i = 0; i < nroAristas; i++) {
        int origen = aristas[i].first;
        int destino = aristas[i].second;

        // Si los nodos ya están en el mismo componente, entonces hay un ciclo
        if (sameComponent(origen, destino)) {
            return true;  // Se encontró un ciclo
        }

        // Unimos los dos nodos en la misma componente
        unionRango(origen, destino);
    }
    return false;  // No se encontró ningún ciclo
}


int main(){
    input;
    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i=0; i<m; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        printf("%.2lf\n",kruskal(n,m));
        // Imprimo el arbol de expasion minimo
        for(int i = 0 ;i <numAristasArbol;i++) {
            cout<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;
        }
    }

    int n = 4; // Número de nodos
    vector<pair<int, int>> aristas = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    int m = aristas.size(); // Número de aristas

    if (tieneCiclo(n, aristas, m)) {
        cout << "True (el grafo tiene un ciclo)." << endl;
    } else {
        cout << "False (el grafo no tiene un ciclo)." << endl;
    } 
    
    return 0;
}
