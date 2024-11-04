import math

def fn(n, delta=0):
    n0 = n
    x0 = int(math.sqrt(n)) - delta
    y0 = x0 ** 2
    f = []
    n -= y0
    f.append(f"{x0}²")
    
    while n > 0:
        x1 = int(math.sqrt(n))
        y1 = x1 ** 2
        n -= y1
        f.append(f"{x1}²")
    
    if len(f) > 4:
        return fn(n0, delta + 1)
    
    respuesta = {
        "numero_inicial": n0,
        "iteraciones": delta,
        "numeros": " + ".join(f)
    }
    return respuesta

# Leer el valor de entrada para el número
numero = int(input("Ingresa un número entero para descomponer en suma de cuadrados: "))

# Ejecutar la función con el número y delta predeterminado a 0
resultado = fn(numero)

# Imprimir el resultado
print(f"Numero inicial: {resultado['numero_inicial']}")
print(f"Iteraciones: {resultado['iteraciones']}")
print(f"Numeros: {resultado['numeros']}")