//25/09/24
//Binary Indexed Tree
// 7 & 9 = 1         
// 2 | 4 = 6

//10 -> 1010    10 >> 2 => 10 = 2 //seria como realizar 10/2/2 = 2
//Fenwick Tree

#include <iostream>

int main() {
    std::cout <<(37&22);

    return 0;
}

//f(6) = s(5,6) + s(1,4) =
//f(1) = s(1,1) =
//f(6)-f(2-1) =
//para intervalo (2,6)

//Suma(3,7)
//f(7)-f(3-1)=
//f(7) = s(7,7)+s(5,6)+s(1,4)
//f(2) = s(1,2)  

//Dado un array de números enteros hacer consultas por rango donde como resultado me diga si es número positivo, negativo o cero, el  numero maximo de los enteros es 10^32
//Complejidad 2^n