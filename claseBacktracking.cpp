#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

//Backtracking

//Fuerza Bruta Lento
//Divide y Venceras(Varios problemas distintos) Complicado Rapido
//DP (Subproblemas similares entre sí) Complicado Rapido 
//Greedy-Codicioso  Errores


//Fuerza Bruta
//PODA
//Cuadrado Mágico

//Problema de las 8 reinas


//Subconjuntos sumas (poda)
int arrayLength = 5;
int x = 7; //suma que se quiere encontrar
vector<int> numbers(arrayLength);

int f(int suma, int pos){
    if(suma == x){
        return 1;
    }
    if(pos >= numbers.size()) {
        return 0;
    }
    //return f(suma+numbers[pos], pos+1) + f(suma, pos+1); //hasta acá sería solamente fuerza bruta
    int sol = f(suma, pos+1);                //poda
    if(suma+numbers[pos]<=7){
        sol += f(suma + numbers[pos], pos+1);
    }
    return sol;
}

int main(){
    for(int i = 0; i < 5; i++){
        cin>>numbers[i];
    }
    cout<<f(0,0)<<endl;
}