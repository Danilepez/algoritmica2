//BINARY SEARCH

//Solo se utiliza cuando nuestro arreglo está ordenado
//Ejecuta una condición en un par de elementos
//Se utiliza en base de datos, para realizar la busqueda en id's enteros
//Objeto ---> Ordenar

//Existen dos formas de codificar:
//Caja Negra: no interesa el proceso, no se sabe que hará la función, solo importa si da true o false
//Caja Blanca: saber a detalle todo el proceso
//Es recomendable empezar con caja negra

#include <bits/stdc++.h> 
#include <cmath>  // Para usar pow()
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N pow(10,32);  // Número máximo de búsqueda


bool f(long long mid, long long x){
    return mid*mid >= x;
}

int binarySearch(long long n){
    long left = 0;
    long long right = MAX_N;
    long long mid = (left + right)/2;//si el array es numero par se toma el de la izquierda
    while(left<right){
        if(f(mid,n)){ //requiere una condicion individual (lo que queremos preguntar) //f(mid)
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left+right)/2;
    }
    return mid;
}