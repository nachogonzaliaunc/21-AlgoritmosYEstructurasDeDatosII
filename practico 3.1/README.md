<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">Practico 3.1 - Algorítmos voraces</p>

## Ejercicio 1 - [Solución](ej01.md)
Demostrar que el algoritmo voraz para el problema de la mochila sin fragmentación no siempre obtiene la solución óptima. Para ello puede modificar el algoritmo visto en clase de manera de que no permita fragmentación y encontrar un ejemplo para el cual no halla la solución óptima.

## Ejercicio 2 - [Solución](ej02.md)
Considerar el problema de dar cambio. Probar o dar un contraejemplo:
si el valor de cada moneda es al menos el doble de la anterior, y la moneda de menor valor es 1, entonces el algoritmo voraz arroja siempre una solución óptima.

```
Para cada uno de los siguientes ejercicios:
• Describir cuál es el criterio de selección.
• En qué estructuras de datos se representará la información del problema?
• Explicar el algoritmo, es decir, los pasos a seguir para obtener el resultado. 
  No se pide que se "lea" el algoritmo ("se define una variable x", "se declara un for"),
  si no que se explique ("se recorre la lista/el arreglo/" o "se elije de tal conjunto 
  el que satisface...").
• Escribir el algoritmo en el lenguaje de programación de la materia.
```

## Ejercicio 3 - [Solución](ej03.md)
Se desea realizar un viaje en un automóvil con autonomía A (en kilómetros), desde la localidad l0 hasta la localidad ln pasando por las localidades l1, ... , ln−1 en ese orden. Se conoce cada distancia di ≤ A entre la localidad li−1 y la localidad li (para 1 ≤ i ≤ n), y se sabe que existe una estación de combustible en cada una de las localidades.

Escribir un algoritmo que compute el menor número de veces que es necesario cargar combustible para
realizar el viaje, y las localidades donde se realizaría la carga.

Suponer que inicialmente el tanque de combustible se encuentra vacío y que todas las estaciones de servicio cuentan con suficiente combustible.

## Ejercicio 4 - [Solución](ej04.md)
En numerosas oportunidades se ha observado que cientos de ballenas nadan juntas hacia la costa y quedan varadas en la playa sin poder moverse. Algunos sostienen que se debe a una pérdida de orientación posiblemente causada por la contaminación sonora de los océanos que interferiría con su capacidad de inter-comunicación. En estos casos los equipos de rescate realizan enormes esfuerzos para regresarlas al interior del mar y salvar sus vidas.

Se encuentran n ballenas varadas en una playa y se conocen los tiempos s1, s2, ... , sn que cada ballena es capaz de sobrevivir hasta que la asista un equipo de rescate. Dar un algoritmo voraz que determine el orden en que deben ser rescatadas para salvar el mayor número posible de ellas, asumiendo que llevar una ballena mar adentro toma tiempo constante t, que hay un único equipo de rescate y que una ballena no muere mientras está siendo regresada mar adentro.

## Ejercicio 5 - [Solución](ej05.md)
Sos el flamante dueño de un teléfono satelital, y se lo ofrecés a tus n amigos para que lo lleven con ellos cuando salgan de vacaciones el próximo verano. Lamentablemente cada uno de ellos irá a un lugar diferente y en algunos casos, los períodos de viaje se superponen. Por lo tanto es imposible prestarle el
teléfono a todos, pero quisieras prestárselo al mayor número de amigos posible.

Suponiendo que conoces los días de partida y regreso (pi y ri respectivamente) de cada uno de tus amigos,

Cuál es el criterio para determinar, en un momento dado, a quien conviene prestarle el equipo?

Tener en cuenta que cuando alguien lo devuelve, recién a partir del día siguiente puede usarlo otro. Escribir un algoritmo voraz que solucione el problema.

## Ejercicio 6 - [Solución](ej06.md)
Para obtener las mejores facturas y medialunas, es fundamental abrir el horno el menor número de veces posible. Por supuesto que no siempre es fácil ya que no hay que sacar nada del horno demasiado temprano, porque queda cruda la masa, ni demasiado tarde, porque se quema.

En el horno se encuentran n piezas de panadería (facturas, medialunas, etc). Cada pieza i que se encuentra en el horno tiene un tiempo mínimo necesario de cocción ti y un tiempo máximo admisible de cocción Ti.

Si se la extrae del horno antes de ti quedará cruda y si se la extrae después de Ti se quemará.

Asumiendo que abrir el horno y extraer piezas de él no insume tiempo, y que ti ≤ Ti para todo i ∈
{1, ... , n}, qué criterio utilizaría un algoritmo voraz para extraer todas las piezas del horno en perfecto estado (ni crudas ni quemadas), abriendo el horno el menor número de veces posible? 

Implementarlo.

## Ejercicio 7 - [Solución](ej07.md)
Un submarino averiado descansa en el fondo del océano con n sobrevivientes en su interior. Se conocen las cantidades c1, ... , cn de oxígeno que cada uno de ellos consume por minuto. El rescate de sobrevivientes se puede realizar de a uno por vez, y cada operación de rescate lleva t minutos.

a) Escribir un algoritmo que determine el orden en que deben rescatarse los sobrevivientes para salvar al mayor número posible de ellos antes de que se agote el total C de oxígeno.

b) Modificar la solución anterior suponiendo que por cada operación de rescate se puede llevar a la superficie a m sobrevivientes (con m ≤ n).

## Ejercicio 8 - [Solución](ej08.md)
Usted vive en la montaña, es invierno, y hace mucho frío. Son las 10 de la noche. Tiene una voraz estufa a leña y n troncos de distintas clases de madera. Todos los troncos son del mismo tamaño y en la estufa entra solo uno por vez. Cada tronco i es capaz de irradiar una temperatura ki mientras se quema, y dura una cantidad ti de minutos encendido dentro de la estufa. Se requiere encontrar el orden en que se utilizarán la menor cantidad posible de troncos a quemar entre las 22 y las 12 hs del día siguiente, asegurando que entre las 22 y las 6 la estufa irradie constantemente una temperatura no menor a K1; y entre las 6 y las 12 am, una temperatura no menor a K2.

## Ejercicio 9 - [Solución](ej09.md)
(sobredosis de limonada) Es viernes a las 18 y usted tiene ganas de tomar limonada con sus amigos. Hay n bares cerca, donde cada bar i tiene un precio Pi de la pinta de limonada y un horario de happy hour Hi, medido en horas a partir de las 18 (por ejemplo, si el happy hour del bar i es hasta las 19, entonces Hi = 1), en el cual la pinta costará un 50% menos. Usted toma una cantidad fija de 2 pintas por hora y no se considera el tiempo de moverse de un bar a otro. Se desea obtener el menor dinero posible que usted puede gastar para tomar limonada desde las 18 hasta las 02 am (es decir que usted tomará 16 pintas) eligiendo en cada hora el bar que más le convenga.