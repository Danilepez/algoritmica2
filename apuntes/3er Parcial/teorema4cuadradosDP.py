import math

def es_cuadrado_perfecto(x):
    raiz = int(math.sqrt(x))
    return raiz * raiz == x

def descomponer_en_cuadrados(n):
    # Verificar si n es un cuadrado perfecto
    if es_cuadrado_perfecto(n):
        raiz = int(math.sqrt(n))
        return {
            "numero_inicial": n,
            "cuadrados": f"{raiz}²",
            "min_cuadrados": 1
        }
    
    # Crear una lista donde dp[i] será el número mínimo de cuadrados que suman i
    dp = [float('inf')] * (n + 1)
    dp[0] = 0  # Caso base: la suma de 0 es 0 cuadrados
    predecesor = [-1] * (n + 1)  # Almacena el mejor cuadrado usado para alcanzar cada `i`

    # Llenar la tabla dp
    for i in range(1, n + 1):
        j = 1
        while j * j <= i:
            if dp[i] > dp[i - j * j] + 1:
                dp[i] = dp[i - j * j] + 1
                predecesor[i] = j * j  # Guardamos el cuadrado utilizado
            j += 1

    # Obtener la lista de cuadrados que suman el valor dado
    resultado = []
    while n > 0:
        cuadrado_usado = predecesor[n]
        resultado.append(f"{int(math.sqrt(cuadrado_usado))}²")
        n -= cuadrado_usado

    # Formatear la salida
    respuesta = {
        "numero_inicial": n,
        "cuadrados": " + ".join(resultado),
        "min_cuadrados": len(resultado)
    }
    return respuesta

# Ejemplo de uso
numero = int(input())
resultado = descomponer_en_cuadrados(numero)

# Imprimir el resultado
print(f"Número inicial: {numero}")
print(f"Números: {resultado['cuadrados']}")
print(f"Número mínimo de cuadrados: {resultado['min_cuadrados']}")
