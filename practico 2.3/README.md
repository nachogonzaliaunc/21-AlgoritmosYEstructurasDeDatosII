<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 2.3 - TADs: pilas y colas</p>

## Ejercicio 1 - [Solución](ej01.md)
Implementar el TAD Pila utilizando la siguiente representación:
```
implement Stack of T where

type Stack of T = List of T
```

## Ejercicio 2 - [Solución](ej02.md)
Implementar el TAD Pila utilizando la siguiente representación:
```
implement Stack of T where

type Node of T = tuple
                    elem: T
                    next: pointer to (Node of T)
                 end tuple

type Stack of T = pointer to (Node of T)
```

## Ejercicio 3 - [Solución](ej03.md)
a) Implementar el TAD Cola utilizando la siguiente representación, donde N es una constante de tipo nat:
```
implement Queue of T where

type Queue of T = tuple
                    elems: array[0..N-1] of T
                    size: nat
                  end tuple
```
b) Implementar el TAD Cola utilizando un arreglo como en el inciso anterior, pero asegurando que todas las operaciones estén implementadas en orden constante.<br>
💡Ayuda1: Quizás convenga agregar algún campo más a la tupla. ¿Estamos obligados a que el primer elemento de la cola esté representado con el primer elemento del arreglo?<br>
💡Ayuda2: Buscar en Google *aritmética modular*.