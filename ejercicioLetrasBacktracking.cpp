#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

//Dado un conjunto de letras de 'a' a 'z' verificar si es posible formar la palabra 'x'
//[a,b,b,d,e,a,p,l,z,n]

//Subconjuntos sumas (poda)
int arrayLength = 10;
string x = "pala"; //suma que se quiere encontrar
vector<char> words(arrayLength);

/*int f(string suma, int pos){
    if(suma == x){
        return 1;
    }
    if(pos >= words.size()) {
        return 0;
    }
    //return f(suma+numbers[pos], pos+1) + f(suma, pos+1); //hasta acá sería solamente fuerza bruta
    int sol = f(suma, pos+1);                //poda
    if((suma+words[pos]).Contains(x[pos])){
        sol += f(suma + words[pos], pos+1);
    }
    return sol;
}*/

string word = "pala";
vector<char> abe(10);
vector<bool> vis(10);

int f(int pos_word){
    if(pos_word==word.size()){
        return 1;
    }
    for(int i = 0; i < 10; i++) {
        if(vis[i]==false){
            if(abe[i]==word[pos_word]) {
                vis[i] = 1;
                return f(pos_word+1);
            }
        }
    }
    return 0;
}

int main(){
    for(int i = 0; i < 10; i++){
        cin>>abe[i];
    }
    if(f(0)){
        cout<<"si existe"<<endl;
    }else {
        cout<<"no existe"<<endl;
    }
}
