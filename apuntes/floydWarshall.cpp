//Este algoritmo es una variante del algoritmo de Dijkstra, pero en lugar de encontrar el camino más corto entre dos nodos, encuentra el camino más corto entre todos los pares de nodos.
//Su complejidad es O(V^3), donde V es el número de nodos.
//Se utiliza Dinamic Programming para resolver el problema.
//DP siempre da como resultado todas las soluciones posibles, por lo que es útil para encontrar el camino más corto entre todos los pares de nodos.
//Si n < 100 usar Floyd Warshall, sino usar Dijkstra u otro algoritmo.
//Se inicializa con infinito la matriz de distancias, y se llena con las distancias directas entre nodos.

//1er Paso: Inicializar la matriz con infinito
//2do Paso: Llenar la matriz de la aristas con las distancias directas
//3er Paso: Inicializar la diagonal de la matriz con 0