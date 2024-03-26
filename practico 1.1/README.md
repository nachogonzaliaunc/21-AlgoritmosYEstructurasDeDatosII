<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 1.1 - Ordenación elemental</p>

## Ejercicio 1 - [Solución](ej01.md)
Escribir algoritmos para resolver cada uno de los siguientes problemas sobre un arreglo a de posiciones 1 a n, utilizando **do**. Elegir en cada caso entre estos dos encabezados el que sea más adecuado:

```
proc nombre (in/out a:array[1..n] of nat)
    ...
end proc
```
```
proc nombre (out a:array[1..n] of nat)
    ...
end proc
```



## Ejercicio 2 - [Solución](ej02.md)
Transformar cada uno de los algoritmos anteriores en uno equivalente que utilice **`for ... to`** 



## Ejercicio 3 - [Solución](ej03.md)
Escribir un algoritmo que reciba un arreglo *a* de posiciones 1 a n y determine si el arreglo recibido está ordenado o no. Explicar en palabras **`qué`** hace el algoritmo. Explicar en palabras **`cómo`** lo hace.



## Ejercicio 4 - [Solución](ej04.md)
Ordenar los siguientes arreglos, utilizando el algoritmo de **`ordenación por selección`** visto en clase. Mostrar en cada paso de iteración cuál es el elemento seleccionado y cómo queda el arreglo después de cada intercambio.
- a) `[7, 1, 10, 3, 4, 9, 5]`

- b) `[5, 4, 3, 2, 1]`

- c) `[1, 2, 3, 4, 5]`



## Ejercicio 5 - [Solución](ej05.md)
Calcular de la manera más exacta y simple posible el número de asignaciones a la variable `t` de los
siguientes algoritmos.
```bash
a)
t := 0
for i := 1 to n do
    for j := 1 to n2 do
        for k := 1 to n3 do
            t := t + 1
        od
    od
od
```
```bash
b)
t := 0
for i := 1 to n do
    for j := 1 to i do
        for k := j to j + 3 do
            t := t + 1
        od
    od
od
```



## Ejercicio 6 - [Solución](ej06.md)
Descifrar `qué` hacen los siguientes algoritmos, explicar `cómo` lo hacen y reescribirlos asignando nombres adecuados a todos los identificadores
```bash
proc p (in/out a: array[1..n] of T)
    var x: nat
    for i:= n downto 2 do
        x:= f(a,i)
        swap(a,i,x)
    od
end proc
```
```bash
fun f (a: array[1..n] of T, i: nat) ret x: nat
    x:= 1
    for j:= 2 to i do
        if a[j] > a[x] then 
            x:= j 
        fi
    od
end fun
```



## Ejercicio 7 - [Solución](ej07.md)
Ordenar los arreglos del ejercicio 4 utilizando el algoritmo de **`ordenación por inserción`**. Mostrar en cada paso de iteración las comparaciones e intercambios realizados hasta ubicar el elemento en su posición.
- a) `[7, 1, 10, 3, 4, 9, 5]`

- b) `[5, 4, 3, 2, 1]`

- c) `[1, 2, 3, 4, 5]`



## Ejercicio 8 - [Solución](ej08.md)
Calcular el orden del número de asignaciones a la variable `t` de los siguientes algoritmos.
```bash
a)
t := 1
do t < n
    t := t ∗ 2
od
```
```bash
b)
t := n
do t > 0
    t := t div 2
od
```
```bash
c)
for i := 1 to n do
    t := i
    do t > 0
        t := t div 2
    od
od
```
```bash
d)
for i := 1 to n do
    t := i
    do t > 0
        t := t − 2
    od
od
```



## Ejercicio 9 - [Solución](ej09.md)
Calcular el orden del número de comparaciones del algoritmo del ejercicio 3.



## Ejercicio 10 - [Solución](ej10.md)
Descifrar `qué` hacen los siguientes algoritmos, explicar `cómo` lo hacen y reescribirlos asignando
nombres adecuados a todos los identificadores
```bash
proc q (in/out a: array[1..n] of T)
    for i:= n-1 downto 1 do
        r(a,i)
    od
end proc
```
```bash
proc r (in/out a: array[1..n] of T, in i: nat)
    var j: nat
    j:= i
    while (j < n) ∧ (a[j] > a[j+1]) do
        swap(a,j+1,j)
        j:= j+1
    od
end proc
```