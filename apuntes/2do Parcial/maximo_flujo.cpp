//Máximo Flujo

//Cuando usabamos dfs o bfs dabamos por hecho que el peso de las aristas entre nodos era 1, 
//Peso vs Capacidad
//El peso es algo constante, la capacidad se puede llenar pero no siempre se puede llenar, ejemplo teleferico, la capacidad es de 10 pero no es constante
//Este algoritmo trata de sacar el máximo provecho de la capacidad de las aristas
//Se disparan varios DFS hasta llegar al nodo final S
//El flujo desde el nodo inicial F
//F-3 = 8 //se mandan 8 unidades de flujo al nodo 3
//F-3-4-S
//F-3-4
//F-3-S
//F-1-2-S

//Se utiliza un grafo residual para saber cuánto flujo vuelve a F