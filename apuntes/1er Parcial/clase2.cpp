//20/09/24

//Segement Tree
//Es un árbol de segmentos

//problema: [7,3,7,1,8,7,6,0], queremos saber la suma entre los indices x-y, podemos crear otro array con la suma acumulada
//pero al array original podemos cambiarle un valor y el array de suma acumulada no se actualiza, entonces se usa un arbol binario con divide y vencerás
//para que se actualice en O(log n) porque es binario y tambien porque se divide en 2

//Se crea un árbol binario con los valores del array original
//si la operación a usar en el árbol es monoide, se puede usar un segment tree

//Monoide: tiene 3 reglas:
//1.- Tiene que pertenecer a un conjunto Σ
//2.- Asociatividad: Una operacion (A+B)+C = A+(B+C) == (A+C)+B
//3.- Elemento neutro: A + ω = A // ω es el elemento neutro

//Para el máximo el elemento neutro es -∞
//Para el mínimo el elemento neutro es ∞
//Para la suma el elemento neutro es 0
//Para el producto el elemento neutro es 1
