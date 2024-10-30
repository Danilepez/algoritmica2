#include <bits/stdc++.h> 

using namespace std;

// Online C++ compiler to run C++ program online


// contar todos los numeros donde la suma de sus digitos es par 
// 278 -> sumPares = 17 -> 0;
// 279 -> sumPares = 18 -> true
int dp[10000][2][1000];
long long solveDP(string & number, int index, bool tight, int sumPares) {
    
    // CASE BASE
    if(index == number.length()) {
        return sumPares%2 == 0;
    }

    if(dp[index][tight][sumPares] == -1) {
        int limit = 9;
        if(tight) {
            limit = number[index] - '0';
        }
        long long sumaDigitos = 0;
        for( int digit = 0 ; digit<= limit ;digit++) { 
            bool newTight;
            if( digit < (number[index] - '0')) {
                newTight = 0;
            }else {
                newTight = tight;
            }
            sumaDigitos += solveDP(number,index+1,newTight, digit + sumPares);
        }
        dp[index][tight][sumPares] = sumaDigitos;
    }
    return dp[index][tight][sumPares];
}

int main() {
    // Write C++ code here
    string number; 
    cin>>number;
    memset(dp, -1, sizeof dp);
    cout<<solveDP(number, 0 , true, 0);

    return 0;
}