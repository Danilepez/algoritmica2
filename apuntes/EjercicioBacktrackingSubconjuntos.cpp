#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

//Mostrar todos los subconjuntos de K elementos compuesto del Array V
//V=[2,3,7,8,7,2,1]
//K=2

int k;
vector<int> numbers(10);
vector<bool> vis(10);


//Entender bien los parametros por referencia
//cuando se realiza recursividad se utiliza c+1 y no c++ en los parametros del for
//& saca la posicion en la que está almacenado el vector

int f(vector<int>estado, vector<vector<int>> &soluciones){
    if(estado.size()==k){
        soluciones.push_back(estado);
    } else {
        for(int i = 0; i <numbers.size(); i++){
            if(vis[i]==0 && estado.size()<k){
                estado.push_back(numbers[i]);
                vis[i] = 1;
                f(estado,soluciones);
                estado.pop_back();
                vis[i] = 0;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        cin>>numbers[i];
        vis[i] = 0;
    }
    cin>>k;
    vector<int> currentState;
    vector<vector<int>> soluciones;
    f(numbers, soluciones);
    for(int i = 0; i < soluciones.size(); i++){
        for (int j = 0; j < k; j++) {
            cout<<"["<<soluciones[i][j]<<"]";
        }
        cout<<endl;
    }
}