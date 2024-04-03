<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 1.2 - Ordenación avanzada</p>

## Ejercicio 1 - [Solución](ej01.md)
a) Ordenar los arreglos del ejercicio 4 del práctico anterior utilizando el algoritmo de **`ordenación por intercalación`**.

- a) `[7, 1, 10, 3, 4, 9, 5]`

- b) `[5, 4, 3, 2, 1]`

- c) `[1, 2, 3, 4, 5]`


b) En el caso del inciso a) del ejercicio 4, dar la secuencia de llamadas al procedimiento `merge_sort_rec`
con los valores correspondientes de sus argumentos.


## Ejercicio 2 - [Solución](ej02.md)
a) Escribir el procedimiento **`intercalar_cada`** que recibe un arreglo a:**array**[1..2ⁿ] **of int** y un número natural i: **nat**; e intercala el segmento a[1,2ⁱ] con a[2ⁱ+1,2∗2ⁱ], el segmento a[2∗2ⁱ+1, 3∗2ⁱ] con a[3∗2ⁱ+1, 4 ∗2ⁱ], etc. Cada uno de dichos segmentos se asumen ordenados. Por ejemplo, si el arreglo contiene los valores
```c
[3, 7, 1, 6, 1, 5, 3, 4];
```
y se lo invoca con i = 1 el algoritmo deberá devolver el arreglo
```c
[1, 3, 6, 7, 1, 3, 4, 5]
```

Si se lo vuelve a invocar
con este nuevo arreglo y con i = 2, devolverá 
```c
[1, 1, 3, 3, 4, 5, 6, 7]
```
que ya está completamente ordenado. El algoritmo asume que cada uno de estos segmentos está ordenado, y puede utilizar el **[procedimiento de intercalación](https://famaf.aulavirtual.unc.edu.ar/pluginfile.php/5592/course/section/693/02.ordenacion.avanzada.pdf)** dado en clase.

b) Utilizar el algoritmo **`intercalar_cada`** para escribir una versión iterativa del algoritmo de **`ordenación por intercalación`**. La idea es que en vez de utilizar recursión, invoca al algoritmo del inciso anterior sucesivamente con i = 0, 1, 2, 3, etc.



## Ejercicio 3 - [Solución](ej03.md)
a) Ordenar los arreglos del ejercicio 4 del práctico anterior utilizando el algoritmo de **`ordenación rápida`**.

- a) `[7, 1, 10, 3, 4, 9, 5]`

- b) `[5, 4, 3, 2, 1]`

- c) `[1, 2, 3, 4, 5]`

b) En el caso del inciso a), dar la secuencia de llamadas al procedimiento **`quick_sort_rec`** con los valores correspondientes de sus argumentos.



## Ejercicio 4 - [Solución](ej04.md)
Escribir una variante del procedimiento **`partition`** que en vez de tomar el primer elemento del segmento `a[izq, der]` como pivot, elige el valor intermedio entre el primero, el último y el que se encuentra en medio del segmento. Es decir, si el primer valor es 4, el que se encuentra en el medio es 20 y el último
es 10, el algoritmo deberá elegir como pivot al último.



## Ejercicio 5 - [Solución](ej05.md)
Escribir un algoritmo que dado un arreglo a:**array**[1..n] **of int** y un número natural k ≤ n devuelve el elemento de a que quedaría en la celda a[k] si a estuviera ordenado. Está permitido realizar intercambios en a, pero no ordenarlo totalmente. La idea es explotar el hecho de que el procedimiento **`partition`** del **`quick_sort`** deja al pivot en su lugar correcto.



## Ejercicio 6 - [Solución](ej06.md)
El procedimiento **`partition`** que se dio en clase separa un fragmento de arreglo principalmente en dos segmentos: 
- menores o iguales al pivot por un lado y
- mayores o iguales al pivot por el otro.
  
Modificar ese algoritmo para que separe en tres segmentos:
- los menores al pivot,
- los iguales al pivot y
- los mayores al pivot.

En vez de devolver solamente la variable `pivot`, deberá devolver `pivot_izq` y `pivot_der` que informan al algoritmo **`quick_sort_rec`** las posiciones inicial y final del segmento de repeticiones del pivot. Modificar el algoritmo **`quick_sort_rec`** para adecuarlo al nuevo procedimiento **`partition`**.