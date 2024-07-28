<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 3.4 - Programación dinámica</p>

## Ejercicio 1 - [Solución](ej01.md)
Dar una definición de la función cambio utilizando la técnica de programación dinámica a partir de la siguiente definición recursiva (backtracking):
```
cambio(i, j) = | 0                                                  si j = 0
               | infinito                                           si j > 0 ∧ i = 0
               | min q∈{0,1,...,j÷di} (q + cambio(i−1, j−q ∗ di))   si j > 0 ∧ i > 0
```


## Ejercicio 2 - [Solución](ej02.md)
Para el ejercicio anterior, es posible completar la tabla de valores "de abajo hacia arriba"? Y "de derecha a izquierda"? En caso afirmativo, reescribir el programa. En caso negativo, justificar.


## Ejercicio 3 - [Solución](ej03.md)
Dar una definición de la función cambio utilizando la técnica de programación dinámica a partir de cada una de las siguientes definiciones recursivas (backtracking):
```
a) cambio(i, j) = | 0                                                       si j = 0
                  | 1 + min i′∈{1,2,...,i | di′≤ j} (cambio(i′, j −di′))    si j > 0

b) cambio(i, j) = | 0                                                       si j = 0
                  | infinito                                                si j > 0 ∧ i = n
                  | cambio(i+1, j)                                          si di > j > 0 ∧ i < n
                  | min(cambio(i + 1, j), 1 + cambio(i, j −di))             si j ≥ di > 0 ∧ i < n
```


## Ejercicio 4 - [Solución](ej04.md)
Para cada una de las soluciones que propuso a los ejercicios del 3 al 9 del práctico de backtracking, dar una definición alternativa que utilice la técnica de programación dinámica. En los casos de los ejercicios 3, 5 y 7 modificar luego el algoritmo para que no sólo calcule el valor óptimo sino que devuelva la solución que tiene dicho valor (por ejemplo, en el caso del ejercicio 3, cuáles serían los pedidos que debería atenderse para alcanzar el máximo valor).