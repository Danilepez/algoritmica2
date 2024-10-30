#include <bits/stdc++.h> 

using namespace std;

// Online C++ compiler to run C++ program online


// contar todos los numeros donde la suma de sus digitos es par 
// 278 -> sumPares = 17 -> 0;
// 279 -> sumPares = 18 -> true

// KISS 
bool isPrime(int d) {
  return d == 2 || d == 3 || d == 5 || d==7;
}

int dp[10000][2][1000];
long long solveDP(string & number, int index, bool tight, int hasPrime) {
    
    // CASE BASE
    if(index == number.length()) {
        return hasPrime > 0;
    }

    if(dp[index][tight][hasPrime] == -1) {
        int limit = 9;
        if(tight) {
            limit = number[index] - '0';
        }
        long long hasPrimes = 0;
        for( int digit = 0 ; digit<= limit ;digit++) { 
            bool newTight;
            if( digit < (number[index] - '0')) {
                newTight = 0;
            }else {
                newTight = tight;
            }
            hasPrimes += solveDP(number,index+1,newTight, hasPrime + isPrime(digit));
        }
        dp[index][tight][hasPrime] = hasPrimes;
    }
    return dp[index][tight][hasPrime];
}

int main() {
    // Write C++ code here
    string number; 
    cin>>number;
    memset(dp, -1, sizeof dp);
    cout<<solveDP(number, 0 , true, false);

    return 0;
}