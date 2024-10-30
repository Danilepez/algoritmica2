#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

string juego(long long n){
    for(long long i = 0; i<=n; i ++){
        long long contador = i;
        long long movS = -2*i-1;
        long long movK = 2*i-1;
        long long mov = 0;
        if(contador%2 == 0 || contador == 0){
            mov += movS;
            if (contador == n){
                return "Sakurako";
            }
        } else {
            mov += movK;
            if (contador == n){
                return "Kosuke";
            }
        }
    }
}

int main(){
    long long posAct = 0;
    long long p,n;
    long long x = 0;
    cin>>p;
    while(p--){
    cin>>n;
        cout<<juego(n)<<endl;
    }
}
