//Máximo Común Divisor
//Numero que podrá dividir a los numeros, resto es igual a 0
//El algoritmo de euclides parte de la geometría(visualmente)
//Cuando el gcd de (x,y) = 1, esos números se llaman coprimos
//X = C * Y + R (con las iteraciones Y se vuelve el siguiente x y r se vuelve el siguiente y)
//Cuando dos números son coprimos significa que ya no se puede simplificar la fraccion

#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int gcd(int x, int y) {
    if(y == 0){
        return x;
    } else {
        gcd(y,x%y);
    }
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}