//3x+12y=1200
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

bool esSolucion = 0;
vector<vector<int>> resultado;

int gcd_extended(int a, int b, int *x, int *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    int temp1,temp2; // temp1-> x temp2 -> y
    int gcd = gcd_extended(b%a,a,&temp1, &temp2);
    *x = temp2 - (b/a)*temp1;
    *y = temp1;

    return gcd;
}