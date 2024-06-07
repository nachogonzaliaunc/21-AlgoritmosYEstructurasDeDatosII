<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 3.2 - Algorítmos voraces sobre grafos</p>

## Ejercicio 1 - [Solución](ej01.md)
Ejecutar paso a paso, graficando las soluciones parciales, el algoritmo de Prim que computa el árbol generador mínimo sobre los grafos con nodos {1,2,...,8} y costos dados por una función w:
```
a)
w((1, 2)) = 7       w((2, 3)) = 4       w((3, 6)) = 4       w((5, 6)) = 6
w((1, 6)) = 3       w((2, 4)) = 2       w((3, 8)) = 6       w((6, 7)) = 5
w((1, 7)) = 5       w((2, 5)) = 1       w((4, 6)) = 8       w((8, 5)) = 2
w((1, 3)) = 3       w((3, 4)) = 5       w((5, 4)) = 3       w((8, 7)) = 3
```
``` 
b)
w((1, 2)) = 3       w((2, 3)) = 1       w((3, 6)) = 3       w((5, 6)) = 6
w((1, 6)) = 2       w((2, 4)) = 1       w((3, 8)) = 7       w((6, 7)) = 6
w((1, 7)) = 8       w((2, 5)) = 5       w((4, 6)) = 1       w((8, 5)) = 1
w((1, 3)) = 1       w((3, 4)) = 9       w((5, 4)) = 2       w((8, 7)) = 5
```


## Ejercicio 2 - [Solución](ej02.md)
Ejecutar paso a paso el algoritmo de Dijkstra que computa el camino de costo mínimo entre un nodo dado y los restantes nodos de un grafo, sobre los dos grafos especificados en el ejercicio anterior.

Considerar 1 como el nodo inicial. Explicitar en cada paso el conjunto de nodos para los cuales ya se ha computado el costo mínimo y el arreglo con tales costos.


## Ejercicio 3 - [Solución](ej03.md)
Usted quiere irse de vacaciones y debe elegir una ciudad entre K posibles que le interesan. Como no dispone de mucho dinero, desea que el viaje de ida hacia la ciudad pueda realizarse con a lo sumo L litros de nafta.

a) Dar un algoritmo que, dado un grafo representado por una matriz E: array[1..n,1..n] of Nat, donde el elemento E[i,j] indica el costo en litros de nafta necesario para ir desde la ciudad i hasta la ciudad j; un conjunto C de vértices entre 1 y n, representando las ciudades que quieren visitarse; un vértice v, representando la ciudad de origen del viaje; y un natural L, indicando la cantidad de litros de nafta total que puede gastar; devuelva un conjunto D de aquellos vértices de C que puede visitar con los L litros.

b) Ejecutar el algoritmo implementado en el inciso anterior para el grafo descripto en el siguiente gráfico, con vértices 1,2,...11, tomando C = {11,5,10,7,8} como las ciudades de interés, disponiendo de L = 40 litros de nafta. ¿Cuáles son los posibles destinos de acuerdo a su presupuesto?

![Grafo](./assets/ej03/ej03-0.svg)