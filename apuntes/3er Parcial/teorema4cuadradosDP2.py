import math

def es_cuadrado_perfecto(x): # función para verificar si un número es un cuadrado perfecto
    raiz = int(math.sqrt(x)) # raiz cuadrada de x
    return raiz * raiz == x # si la raiz cuadrada de x al cuadrado es igual a x, entonces x es un cuadrado perfecto

def descomponer_en_cuadrados(n):
    # verificar si n es un cuadrado perfecto
    if es_cuadrado_perfecto(n):  
        raiz = int(math.sqrt(n))
        return {
            "numero_inicial": n,
            "cuadrados": f"{raiz}²",
            "min_cuadrados": 1
        }

    # dp[i] = número mínimo de cuadrados que suman i
    dp = [float('inf')] * (n + 1) # inicializar con infinito
    dp[0] = 0  # caso base
    predecesor = [-1] * (n + 1)  # almacena el mejor cuadrado, inicializar con -1

    # construccion dp
    for i in range(1, n + 1):
        j = 1 # inicializar j e iniciar comprobación con el cuadrado 1
        while j * j <= i: # iterar sobre los cuadrados
            if dp[i] > dp[i - j * j] + 1: # si el número de cuadrados es mayor al número de cuadrados anteriores
                dp[i] = dp[i - j * j] + 1 # actualizar el número de cuadrados
                predecesor[i] = j * j  # guardar el cuadrado utilizado
            j += 1 # incrementar el cuadrado

    # obtener la lista de cuadrados que suman el valor de entrada
    resultado = []
    while n > 0: 
        cuadrado_usado = predecesor[n] # obtener el cuadrado utilizado
        resultado.append(f"{int(math.sqrt(cuadrado_usado))}²") # agregar el cuadrado a la lista sacandole la raiz cuadrada
        n -= cuadrado_usado # restar el cuadrado utilizado

    respuesta = {
        "numero_inicial": n,
        "cuadrados": " + ".join(resultado),
        "min_cuadrados": len(resultado)
    }
    return respuesta

# ejemplo
numero = int(input())
resultado = descomponer_en_cuadrados(numero)

# Imprimir el resultado
print(f"Número inicial: {numero}")
print(f"Números: {resultado['cuadrados']}")
print(f"Número mínimo de cuadrados: {resultado['min_cuadrados']}")