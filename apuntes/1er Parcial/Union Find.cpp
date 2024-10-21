//Union Find
//Agrupar nodos sin usar dfs ni bfs

//para saber cuantos grupos hay se debe contar cuantos padres del mismo padre existen
//1er paso crear array de padres
//2do paso 

#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int n = 10;
vector<int> parents(n);

void init() {
    for(int i= 0; i < n; i++){
        parents[i]=i;
    }
}

int find(int node) {
    int father = parents[node];
    if(node == father){
        return node;
    } else {
        parents[node] = find(father);
        return parents[node];
    }
}

// tratar de unir el nodo a con el nodo b
void union_(int a, int b) {
    int fatherIzq = find(a);
    int fatherDer = find(b);
    parents[fatherDer] = fatherIzq;
}

bool sameComponent(int a, int b){
    return find(a)==find(b);
}

int contNodes(int node){
    int fatherA = find(node); //es mejor almacenar en una variable lo que se repetirá en un bucle para disminuir complejidad
    int acc = 0;
    for(int i=0; i<n; i++){
        if(find(i)==fatherA){
            acc++;
        }
    }
    return acc;
}

//comprimir el árbol 

void print(){
    for(int i = 0; i<10; i++){
        cout<<"["<<parents[i]<<"]";
    }
    cout<<endl;
}

int main(){
    init();
    int cases = 5;
    while(cases--){
        int a, b;
        cin>>a>>b;
        union_(a,b);
        print();
    }
}