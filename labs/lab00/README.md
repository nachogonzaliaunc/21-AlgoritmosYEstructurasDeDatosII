<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">TALLER - 15 de marzo 2024</p>

# Laboratorio 0: Repaso de C
<p style="color:gray; font-size: 14px;">
    - Revisión 2024: Marco Rocchietti
</p>

## Objetivos

1. Repaso de programación básica en lenguaje C.
2. Repaso de compilación de programas.
3. Uso de editor de texto para trabajar.
4. Repaso de arreglos y estructuras en C.
5. Repaso de uso de las librerías **assert.h**, **stdio.h**, **stdbool.h**.
6. Lectura y comprensión de código.

## Ejercicio 1
En el archivo **[bounds.c](bounds.c)** implementar la función:
```c
struct bound_data check_bound(int value, int arr[], unsigned int length);
```
que determina si por un lado el `value` es <u>mayor o igual a todos</u> los elementos del arreglo `arr` (que tiene `length` elementos), por otro lado si es <u>menor o igual a todos</u> los elementos del arreglo, también indica si `value` se encuentra en `arr` y en caso de encontrarse indica en qué posición se lo encontró. Toda esta información es devuelta en una estructura `struct bound_data` que tiene la siguiente definción:
```c
struct bound_data {
	bool is_upperbound;
	bool is_lowerbound;
	bool exists;
	unsigned int where;
};
```
Los cuatro campos de la estructura son los siguientes: valor de verdad que indica si el valor es mayor o igual a todos los elementos del arreglo (`is_upperbound`), valor de verdad que indica si el valor es menor o igual a todos los elementos (`is_lowerbound`), valor de verdad que indica si el elemento existe en el arreglo (`exists`) y posición donde se encontró el elemento (`where`). Por ejemplo:
```c
int a[] = {0, -1, 9, 4};
result = check_bound(9, a, 4);
printf("%d", result.is_upperbound) // Imprime 1
printf("%d", result.is_lowerbound) // Imprime 0
printf("%d", result.exists) // Imprime 1
printf("%u", result.where) // Imprime 2
```
La función debe implementarse <u>usando un único ciclo</u> (`for` o `while`).

En la función **`main()`** se le debe solicitar al usuario que ingrese uno por uno los elementos del arreglo, para ello utilizar la función **`scanf()`** de la librería **`stdio.h`**. Una vez que se obtienen los elementos, se le debe pedir al usuario un valor para verificar con **`check_bound()`**. La salida por pantalla debe indicar si el valor que ingresó el usuario es *cota superior*, *cota inferior*, *mínimo* o *máximo*. Solo en caso de ser mínimo o máximo (esto significa que el valor se encuentra en el arreglo) mostrar por pantalla la posición donde se encontró el elemento.

### Ejecución
Primero compile el programa con el siguiente comando:
```bash
make bounds
```
Luego ejecute el programa con el siguiente comando:
```bash
make run_bounds
```
El programa le solicitará que ingrese los valores para su arreglo, mediante el mensaje de *`Ingrese el valor de la posicion x:`*, usted deberá ingresar el valor deseado y pulsar la tecla *Enter*.

Una vez que haya ingresado todos los valores para su arreglo, el programa mostrará en arreglo ingresado y le solicitará que ingrese un valor para verificar con **`check_bound()`**, mediante el mensaje de *`Ingrese el valor a comparar: `*, usted deberá ingresar el valor deseado y pulsar la tecla *Enter*.

Finalmente el programa mostrará por pantalla si el valor que ingresó el usuario es *cota superior*, *cota inferior*, *mínimo* o *máximo*. Solo en caso de ser mínimo o máximo (esto significa que el valor se encuentra en el arreglo) mostrará por pantalla la posición donde se encontró el elemento.

#### Ejemplo
```bash
Ingrese el largo del arreglo: 4

Ingrese el valor de la posicion 0: 0
Ingrese el valor de la posicion 1: -1
Ingrese el valor de la posicion 2: 9
Ingrese el valor de la posicion 3: 4

El arreglo ingresado es: [0, -1, 9, 4]

Ingrese el valor a comparar: 9

El valor es maximo y existe en el arreglo en la posicion 2
```


## Ejercicio 2
En el archivo **[tictactoe.c](tictactoe.c)** se encuentra una implementación del clásico juego <u><a href="https://es.wikipedia.org/wiki/Tres_en_l%C3%ADnea">tres en línea</a></u> (conocido como *tatetí* o *tictactoe*). El tablero 3x3 se representa como una matriz en C, declarada de la siguiente manera.
```c
char board[3][3] = {
	{ '-', '-', '-' },
	{ '-', '-', '-' },
	{ '-', '-', '-' }
};
```
Inicialmente todas las "celdas" del tablero se encuentran vacías, lo que se representa con el carácter **'-'**. Los caracteres **'X'** y **'O'** de acuerdo a su turno, teniendo la posibilidad de elegir con un número entero en qué celda desea marcar el tablero. Las nueve celdas del tablero se encuentran numeradas de la siguiente forma:
```c
.................................................
| 0: -		| 1: - 		| 2: - 		|
.................................................
| 3: - 		| 4: - 		| 5: - 		|
.................................................
| 6: - 		| 7: - 		| 8: - 		|
.................................................
```
El juego está incompleto puesto que no detecta cuándo hubo un ganador, o si hubo empate. Para ello se deben implementar correctamente las funciones:
```c
bool has_free_cell(char board[3][3])
```
que devuelve verdadero si hay una celda libre (marcada con '-') en el tablero **`board`**, y devuelve **false** en caso contrario:
```c
char get_winner(char board[3][3])
```
que devuelve el jugador ganador (**'X'** o **'O'**) si lo hubo, o **'-'** si todavía no hay ganador. Para ello se debe recorrer la matriz para verificar si alguna columna, fila o diagonal tiene 3 veces consecutivas el mismo carácter.
Se pide **leer el código y comprender** cómo se logra el funcionamiento del juego.

### Ejecución
Primero compile el programa con el siguiente comando:
```bash
make tictactoe
```
Luego ejecute el programa con el siguiente comando:
```bash
make run_tictactoe
```

La salida por pantalla debe ser la siguiente: 
```bash
TicTacToe [Completo :D]
	 ................................................
	 | 0: - 	 | 1: - 	 | 2: - 	 |
	 ................................................
	 | 3: - 	 | 4: - 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno X - Elija posición (número del 0 al 8):
```
Luego el programa le solicitará que ingrese un número del 0 al 8 con el objetivo de colocar la primera ficha de las X, usted deberá ingresar el número deseado y pulsar la tecla *Enter*.

Una vez que haya ingresado el número, el programa mostrará el tablero con la ficha de las X y le solicitará que ingrese un número del 0 al 8 con el objetivo de colocar la primera ficha de las O, usted deberá ingresar el número deseado y pulsar la tecla *Enter*.

El juego continuará hasta que se complete el tablero o haya un ganador, en caso de haber un ganador el programa mostrará por pantalla el ganador.

#### Ejemplo
```bash
TicTacToe [Completo :D]
	 ................................................
	 | 0: - 	 | 1: - 	 | 2: - 	 |
	 ................................................
	 | 3: - 	 | 4: - 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno X - Elija posición (número del 0 al 8): 0
	 ................................................
	 | 0: X 	 | 1: - 	 | 2: - 	 |
	 ................................................
	 | 3: - 	 | 4: - 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno O - Elija posición (número del 0 al 8): 2
	 ................................................
	 | 0: X 	 | 1: - 	 | 2: O 	 |
	 ................................................
	 | 3: - 	 | 4: - 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno X - Elija posición (número del 0 al 8): 1
	 ................................................
	 | 0: X 	 | 1: X 	 | 2: O 	 |
	 ................................................
	 | 3: - 	 | 4: - 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno O - Elija posición (número del 0 al 8): 4
	 ................................................
	 | 0: X 	 | 1: X 	 | 2: O 	 |
	 ................................................
	 | 3: - 	 | 4: O 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno X - Elija posición (número del 0 al 8): 3
	 ................................................
	 | 0: X 	 | 1: X 	 | 2: O 	 |
	 ................................................
	 | 3: X 	 | 4: O 	 | 5: - 	 |
	 ................................................
	 | 6: - 	 | 7: - 	 | 8: - 	 |
	 ................................................

Turno O - Elija posición (número del 0 al 8): 6
	 ................................................
	 | 0: X 	 | 1: X 	 | 2: O 	 |
	 ................................................
	 | 3: X 	 | 4: O 	 | 5: - 	 |
	 ................................................
	 | 6: O 	 | 7: - 	 | 8: - 	 |
	 ................................................
Ganó O
```

## Ejecicio 3
1. En un archivo nuevo **tictactoe_gen.c** programar una implementación modificada del ejercicio anterior para hacer un tictactoe que utilice un tablero 4x4 donde el criterio para ganar es que haya 4 marcas iguales en línea en vez de 3.
2. Modificar la implementación del apartado anterior (en el mismo archivo) para implementar un juego de tictactoe en un tablero 5x5. Si hicieron correctamente el apartado 1 debería salir cambiando un solo símbolo del código. Si requieren más cambios, rehacer el apartado 1.

### Ejecución
Primero compile el programa con el siguiente comando:
```bash
make tictactoe_gen
```
Luego ejecute el programa con el siguiente comando:
```bash
make run_tictactoe_gen
```

La salida por pantalla debe ser la siguiente (en caso de ser tamaño 5x5): 
```bash
TicTacToe [Completo :D]
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: - 	 | 3: - 	 | 4: - 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: - 	 | 8: - 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24):
```
Luego el programa le solicitará que ingrese un número del 0 al 24 con el objetivo de colocar la primera ficha de las X, usted deberá ingresar el número deseado y pulsar la tecla *Enter*.

Una vez que haya ingresado el número, el programa mostrará el tablero con la ficha de las X y le solicitará que ingrese un número del 0 al 24 con el objetivo de colocar la primera ficha de las O, usted deberá ingresar el número deseado y pulsar la tecla *Enter*.

El juego continuará hasta que se complete el tablero o haya un ganador, en caso de haber un ganador el programa mostrará por pantalla el ganador.

#### Ejemplo
```bash
TicTacToe [Completo :D]
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: - 	 | 3: - 	 | 4: - 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: - 	 | 8: - 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24): 4
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: - 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: - 	 | 8: - 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno O - Elija posición (número del 0 al 24): 2
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: - 	 | 8: - 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24): 8
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: - 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno O - Elija posición (número del 0 al 24): 7
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: - 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24): 12
	 ................................................................................
	 | 0: - 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: X 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno O - Elija posición (número del 0 al 24): 0
	 ................................................................................
	 | 0: O 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: X 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: - 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24): 16
	 ................................................................................
	 | 0: O 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: - 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: X 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: X 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno O - Elija posición (número del 0 al 24): 5
	 ................................................................................
	 | 0: O 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: O 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: X 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: X 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: - 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................

Turno X - Elija posición (número del 0 al 24): 20
	 ................................................................................
	 | 0: O 	 | 1: - 	 | 2: O 	 | 3: - 	 | 4: X 	 |
	 ................................................................................
	 | 5: O 	 | 6: - 	 | 7: O 	 | 8: X 	 | 9: - 	 |
	 ................................................................................
	 | 10: - 	 | 11: - 	 | 12: X 	 | 13: - 	 | 14: - 	 |
	 ................................................................................
	 | 15: - 	 | 16: X 	 | 17: - 	 | 18: - 	 | 19: - 	 |
	 ................................................................................
	 | 20: X 	 | 21: - 	 | 22: - 	 | 23: - 	 | 24: - 	 |
	 ................................................................................
Ganó X
```

## Comandos de ejecución
Los comandos de ejecución son los siguientes:
- Si desea compilar todos los programas, ejecute el siguiente comando:
  ```bash
  make all
  ```
  o 
  ```bash
  make
  ```
- Si desea compilar un programa en particular, ejecute el siguiente comando:
  ```bash
  make <nombre_del_programa>
  ```
- Si desea ejecutar un programa en particular, ejecute el siguiente comando:
  ```bash
  make run_<nombre_del_programa>
  ```

Los programas que se pueden ejecutar son:
- **bounds**
- **tictactoe**
- **tictactoe_gen**
