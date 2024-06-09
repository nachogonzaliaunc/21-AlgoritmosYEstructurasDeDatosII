<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 3.3 - Backtracking</p>

## Ejercicio 1 - [Solución](ej01.md)
Modificar el código del algoritmo que resuelve el problema de la moneda utilizando backtracking, de manera que devuelva qué monedas se utilizan, en vez de sólo la cantidad.

## Ejercicio 2 - [Solución](ej02.md)
En un extraño país las denominaciones de la moneda son 15, 23 y 29, un turista quiere comprar un recuerdo pero también quiere conservar el mayor número de monedas posibles. Los recuerdos cuestan 68, 74, 75, 83, 88 y 89. Asumiendo que tiene suficientes monedas para comprar cualquiera de ellos, cuál de ellos elegirá? qué monedas utilizará para pagarlo? Justificar claramente y mencionar el método utilizado.

```
Para cada uno de los siguientes ejercicios:
• Identificar qué parámetros debe tomar la función recursiva que resuelve el problema.
• Describir con palabras qué calcula la misma, en función de sus argumentos.
• Definir la función recursiva en notación matemática y opcionalmente en código.
• Indicar cuál es la llamada principal que obtiene el resultado pedido en el ejercicio.
```

## Ejercicio 3 - [Solución](ej03.md)
Una panadería recibe *n* pedidos por importes *m1,...,mn*, pero sólo queda en depósito una cantidad *H* de harina en buen estado. Sabiendo que los pedidos requieren una cantidad *h1,...,hn* de harina *(respectivamente)*, determinar el máximo importe que es posible obtener con la harina disponible.

## Ejercicio 4 - [Solución](ej04.md)
Usted se encuentra en un globo aerostático sobrevolando el océano cuando descubre que empieza a perder altura porque la lona está levemente dañada. Tiene consigo *n* objetos cuyos pesos *p1,...,pn* y valores *v1,...,vn* conoce. Si se desprende de al menos *P* kilogramos logrará recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de los objetos supera holgadamente *P*. Cuál es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa?

## Ejercicio 5 - [Solución](ej05.md)
Sus amigos quedaron encantados con el teléfono satelital, para las próximas vacaciones ofrecen pagarle un alquiler por él. Además del día de partida y de regreso (*pi* y *ri*) cada amigo ofrece un monto *mi* por día. Determinar el máximo valor alcanzable alquilando el teléfono.

## Ejercicio 6 - [Solución](ej06.md)
Un artesano utiliza materia prima de dos tipos: A y B. Dispone de una cantidad *MA* y *MB* de cada una de ellas. Tiene a su vez pedidos de fabricar *n* productos *p1,...,pn* (uno de cada uno). Cada uno de ellos tiene un valor de venta *v1,...,vn* y requiere para su elaboración cantidades *a1,...,an* de materia prima de tipo *A* y *b1,...,bn* de materia prima de tipo *B*. Cuál es el mayor valor alcanzable con las cantidades de materia prima disponible?

## Ejercicio 7 - [Solución](ej07.md)
En el problema de la mochila se buscaba el máximo valor alcanzable al seleccionar entre *n* objetos de valores *v1,...,vn* y pesos *w1,...,wn*, respectivamente, una combinación de ellos que quepa en una mochila de capacidad *W*. Si se tienen dos mochilas con capacidades *W1* y *W2*, cuál es el valor
máximo alcanzable al seleccionar objetos para cargar en ambas mochilas?

## Ejercicio 8 - [Solución](ej08.md)
Una fábrica de automóviles tiene dos líneas de ensamblaje y cada línea tiene *n* estaciones de trabajo, *S1,1,...,S1,n* para la primera y *S2,1,...,S2,n* para la segunda. Dos estaciones *S1,i* y *S2,i* (para i = 1,...,n), hacen el mismo trabajo, pero lo hacen con costos *a1,i* y *a2,i* respectivamente, que pueden ser diferentes. Para fabricar un auto debemos pasar por n estaciones de trabajo *Si1,1,Si2,2...,Sin,n* no necesariamente todas de la misma línea de montaje (ik = 1,2). Si el automóvil está en la estación *Si,j*, transferirlo a la otra línea de montaje (es decir continuar en Si',j+1 con i' != i) cuesta *ti,j*. Encontrar el costo mínimo de fabricar un automóvil usando ambas líneas.

## Ejercicio 9 - [Solución](ej09.md)
El juego ↖U↑P↗ consiste en mover una ficha en un tablero de *n* filas por *n* columnas desde la fila inferior a la superior. La ficha se ubica al azar en una de las casillas de la fila inferior y en cada movimiento se desplaza a casillas adyacentes que estén en la fila superior a la actual, es decir, la
ficha puede moverse a:<br>
• la casilla que está inmediatamente arriba,<br>
• la casilla que está arriba y a la izquierda (si la ficha no está en la columna extrema izquierda),<br>
• la casilla que está arriba y a la derecha (si la ficha no está en la columna extrema derecha).<br>
Cada casilla tiene asociado un número entero cij (i,j = 1,...,n) que indica el puntaje a asignar cuando la ficha esté en la casilla. El puntaje final se obtiene sumando el puntaje de todas las casillas recorridas por la ficha, incluyendo las de las filas superior e inferior. Determinar el máximo y el mínimo puntaje que se puede obtener en el juego. 

*Los dos últimos ejercicios, también pueden resolverse planteando un grafo dirigido y recurriendo al algoritmo de Dijkstra. De qué manera? Serán soluciones más eficientes?*
```
Si. Con progranación dinámica, y serían mucho más eficientes
```