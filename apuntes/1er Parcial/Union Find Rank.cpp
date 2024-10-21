#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

//Union -> Rangos


int n = 10;
vector<int> parents(n);
vector<int> ranks(n);

void init() {
    for(int i= 0; i < n; i++){
        parents[i]=i;
    }
    for(int i= 0; i < n; i++){
        ranks[i]=0;
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

void unionR(int x, int y){
    int fatherIzq = find(x);
    int fatherDer = find(y);
    if(ranks[fatherIzq]>ranks[fatherDer]){
        parents[fatherDer]=fatherIzq;
    } else {
        parents[fatherIzq]=fatherDer;
        if(ranks[fatherIzq]==ranks[fatherDer]){
            ranks[fatherDer]++;
        }
    }
}