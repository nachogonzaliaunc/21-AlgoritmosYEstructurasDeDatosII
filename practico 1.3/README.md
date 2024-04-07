<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 1.3 - Recurrencias y jerarquía de funciones</p>

## Ejercicio 1 - [Solución](ej01.md)
Calcular el orden de complejidad de los siguientes algoritmos:

```bash
a)
proc f1 (in n: nat)
    if n ≤ 1 then skip
    else
        for i:= 1 to 8 do f1(n div 2) od
        for i:= 1 to n³ do t:= 1 od
```
```bash
b)
proc f2 (in n: nat)
    for i:= 1 to n do
        for j:= 1 to i do t:= 1 od
    od
    if n > 0 then
        for i:= 1 to 4 do f2(n div 2) od
```



## Ejercicio 2 - [Solución](ej02.md)
Dado un arreglo a: **array**[1..n] **of nat** se define una *cima* de a como un valor k en el intervalo 1,...,n tal que *a[1..k]* está ordenado crecientemente y *a[k..n]* está ordenado decrecientemente.

- a) Escribir un algoritmo que determine si un arreglo dado tiene cima.
- b) Escribir un algoritmo que encuentre la cima de un arreglo dado (asumiendo que efectivamente
tiene una cima) utilizando una búsqueda secuencial, desde el comienzo del arreglo hacia el final.
- c) Escribir un algoritmo que resuelva el mismo problema del inciso anterior utilizando la idea de
búsqueda binaria.
- d) Calcular y comparar el orden de complejidad de ambos algoritmos.



## Ejercicio 3 - [Solución](ej03.md)
El siguiente algoritmo calcula el mínimo elemento de un arreglo a: **array**[1..n] **of nat** mediante la técnica de programación *divide y vencerás*. Analizar la eficiencia de **`minimo(1, n)`**.

```bash
fun minimo(a: array[1..n] of nat, i,k: nat) ret m: nat
    if (i = k) then m:= a[i]
    else
        j:= (i + k) div 2
        m:= min(minimo(a, i, j), minimo(a,j+1,k))
    fi
end fun
```



## Ejercicio 4 - [Solución](ej04.md)
Ordenar utilizando ⊏ y ≈ los órdenes de las siguientes funciones. No calcular límites, utilizar las propiedades algebraicas.

- a)
  - n log 2ⁿ
  - 2ⁿ log n
  - n!log n
  - 2ⁿ
- b)
  - n⁴ + 2 log n
  - log((nⁿ)⁴)
  - 2^(4 log n)
  - 4ⁿ
  - n³ log n

- c)
  - log n!
  - n log n
  - log(nⁿ)



## Ejercicio 5 - [Solución](ej05.md)
Sean K y L constantes, y f el siguiente procedimiento:

```bash
proc f(in n: nat)
    if n ≤ 1 then skip
    else
        for i:= 1 to K do f(n div L) od
        for i:= 1 to n⁴ do operacion_de_O(1) od
```
Determinar posibles valores de K y L de manera que el procedimiento tenga orden:
- a) n⁴ log n
- b) n⁴
- c) n⁵



## Ejercicio 6 - [Solución](ej06.md)
Escribir algoritmos cuyas complejidades sean (asumiendo que el lenguaje no tiene multiplicaciones ni logaritmos, o sea que no podés escribir **for** i:= 1 **to** n² + 2log n **do**...**od**):
- a) n² + 2log n
- b) n² log n
- c) 3ⁿ