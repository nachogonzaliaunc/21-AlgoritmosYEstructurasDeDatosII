<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">TALLER - 23 de mayo 2024</p>

# Laboratorio 6: Árboles binarios de búsqueda
<p style="color:gray; font-size: 14px;">
    - Revisión 2024: Marco Rocchietti
</p>

## Objetivos
1. Implementar el TAD ABB con sus operaciones elementales
2. Familiarizarse con una interfaz de usuario básica TUI
3. Definir la invariante de representación de un ABB
4. Manejo de Strings en C
5. Implementar un TAD String
6. Implementar un TAD Diccionario
7. Utilizar valgrind para eliminar memory leaks
8. Utilizar gdb para erradicar bugs en los programas



## Ejercicio 1: *TAD ABB*
Se debe implementar el TAD abb (árbol binario de búsqueda) siguiendo la especificación que se encuentra en *[abb.h](./ej1/abb.h)*. Este tipo abstracto de datos está diseñado para guardar enteros en una estructura de árbol binario siguiendo la definición vista en el teórico. El TAD no permite tener elementos repetidos, por lo cual es parecido a un conjunto en ese aspecto.

En el archivo **[abb.c](./ej1/abb.c)** está dada la estructura de representación `struct s_abb` que tiene la siguiente definición:
```c
struct _s_abb {
    abb_elem elem; // Elemento del nodo
    struct s_abb *left; // Rama izquierda
    struct s_abb *right; // Rama derecha
};
```
Se encuentra definida de manera incompleta la función:
```c
static bool invrep(abb tree)
```
que debe verificar la invariante de representación del TAD. La invariante debe asegurar que la estructura de nodos es consistente con la definición de Árbol Binario de Búsqueda. Para poder verificar la propiedad fundamental de los ABB de manera “sencilla”, será necesario programar esta función de manera **recursiva**. La interfaz del TAD cuenta con las siguientes funciones que se deben implementar:

| **Función**                         | **Descripción**                                                                 |
|-------------------------------------|---------------------------------------------------------------------------------|
|abb abb_empty(void)                  | Crea un árbol binario de búsqueda vacío                                         |
|abb abb_add(abb tree, abb_elem e)    | Agrega un nuevo elemento al árbol                                               |
|bool abb_is_empty(abb tree)          | Indica si el árbol está vacío                                                   |
|bool abb_exists(abb tree, abb_elem e)| Indica si el elemento e está dentro de tree                                     |
|unsigned int abb_length(abb tree)    | Devuelve la cantidad de elementos del árbol                                     |
|abb abb_remove(abb tree, abb_elem e) | Elimina el elemento e del arbol tree                                            |
|abb_elem abb_root(abb tree)          | Devuelve el elemento que está actualmente en la raíz del árbol                  |
|abb_elem abb_max(abb tree)           | Devuelve el máximo elemento del árbol                                           |
|abb_elem abb_min(abb tree)           | Devuelve el mínimo elemento del árbol                                           |
|void abb_dump(abb tree, abb_ord ord) | Muestra el contenido del arbol por la pantalla usando el orden indicado por ord |
|abb abb_destroy(abb tree)            | Destruye la instancia tree liberando toda la memoria utilizada.                 |

Notar que en **[abb.h](./ej1/abb.h)** se especifican las pre y postcondiciones de las funciones del TAD, y en **[abb.c](./ej1/abb.c)** se verifican estas condiciones con `assert()` para asegurar que la implementación que se realice cumpla con estas propiedades.

Una buena idea, dada la naturaleza recursiva de los árboles, es pensar sus operaciones de forma recursiva. Se pueden dar definiciones iterativas o recursivas según se crea conveniente, pero seguramente **el código se va a simplificar bastante usando recursión**. Se incluye una implementación de `abb_dump()` como ejemplo que, aunque luego hay que completar, se puede ver cómo se recorre el árbol completo aprovechando la recursión. Las operaciones de *add, exists, max, min y destroy* salen realmente fácil aprovechando esta técnica de programación.

La operación más delicada que se debe implementar es
```c
abb abb_remove(abb tree, abb_elem e)
```
ya que no es trivial cómo eliminar un nodo del árbol sin romper la definición de ABB.

Para probar la implementación se incluye el archivo **[main.c](./ej1/main.c)** que construye un árbol binario de búsqueda a partir de un archivo y lo muestra por pantalla, junto con la raíz del árbol, el mínimo y el máximo. Para compilar se puede usar el **Makefile** incluído haciendo:
```bash
$ make
```
luego, para ejecutar el programa con el archivo **[abb_example.in](./ej1/input/abb_example.in)** de entrada:
```bash
$ ./readtree input/abb_example.in
```

**a)** Completar las implementaciones de las operaciones descriptas anteriormente a excepción de `abb_dump()` la cual tiene una implementación que funciona aunque está incompleta.

**b)** Modificar el archivo **[main.c](./ej1/main.c)** para que luego de cargar el árbol desde el archivo de entrada, se puedan probar las distintas funcionalidades del TAD. Se debe implementar con un ciclo entonces una interfaz que permita al usuario realizar una de las siguientes operaciones en cada iteración:
1. Mostrar el árbol por pantalla<br>
2. Agregar un elemento<br>
3. Eliminar un elemento<br>
4. Chequear existencia de elemento<br>
5. Mostrar la longitud del árbol<br>
6. Mostrar raiz, máximo y mínimo del árbol<br>
7. Salir del programa

Para elegir qué acción realizar se debe solicitar un número de entrada. Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el elemento a agregar, eliminar o chequear respectivamente. Al salir debe liberarse toda la memoria utilizada.

```
❗Asegurarse de que la implementación esté libre de memory leaks 
usando la herramienta valgrind con la opción --leak-check=full
```

**c)** En este punto el programa muestra el contenido del árbol con los elementos en orden creciente. ¿Se entiende por qué? ¿Cómo es el árbol que se obtiene si los elementos se agregan en ese orden?<br>
Completar la función y dividir su definición según el valor del parámetro `ord`. Para el caso **ABB_IN_ORDER** usar la definición original, para el caso **ABB_PRE_ORDER** hacer que se muestren los elementos en un orden que permita reconstruir el árbol original (debe seguir siendo recursiva la definición). El caso **ABB_POST_ORDER** completarlo con un criterio que parezca conveniente. Finalmente cambiar **[main.c](./ej1/main.c)** para que se use a `abb_dump()` con el modo **ABB_PRE_ORDER**.

**d) OPCIONAL:** Agregar una opción al programa para definir en qué modo se usa `abb_dump()`, cada modo se refiere a una de las constantes **ABB_PRE_ORDER**, **ABB_IN_ORDER** o **ABB_POST_ORDER**.



## Ejercicio 2: *TAD String*
Se va a implementar en el próximo ejercicio un TAD Diccionario, pero para ello será necesario tener un
manejo de cadenas más práctico del que provee C. Para ello se definirá el TAD String.

**a)** Completar la implementación del TAD String, la interfaz del TAD tiene las siguientes funciones:

| **Función**                              | **Descripción**                                                      |
|------------------------------------------|----------------------------------------------------------------------|
|string string_create(const char *word)    | Crea un nuevo string a partir de la cadena en word                   |
|unsigned int string_length(string str)    | Devuelve la longitud del string                                      |
|bool string_less(string str1, string str2)| Indica si str1 es menor que str2 usando el orden alfabético habitual |
|bool string_eq(string str1, string str2)  | Indica si la cadena str1 tiene el mismo contenido que la cadena str2 |
|string string_clone(string str)           | Genera una copia del string str                                      |
|const char* string_ref(string str)        | Devuelve un puntero al contenido de la cadena str                    |
|void string_dump(string str, FILE *file)  | Escribe el contenido de str en el archivo file                       |
|string string_destroy(string str)         | Destruye str liberando la memoria utilizada                          |

**b)** Crear un archivo **[main.c](./ej2/main.c)** que utilice las funciones `string_less()` y `string_eq()`.



## Ejercicio 3: *TAD Diccionario*
En este ejercicio se debe implementar el TAD Diccionario. Como su nombre sugiere, el TAD almacenará palabras y definiciones (cada palabra tiene exactamente una definición). Las funcionalidades incluyen la búsqueda de palabras, agregar una nueva palabra junto con su definición, reemplazar la definición de una palabra ya existente, etc. La implementación estará basada en la especificación del teórico:
```
type Node of (K, V) = tuple
                        left: pointer to (Node of (K,V))
                        key: K
                        value: V
                        right: pointer to (Node of (K,V))
                      end tuple

type Dict of (K, V) = pointer to (Node of (K,V))
```
es decir, se implementa como un árbol binario de búsqueda cuyos nodos contienen una clave y un valor. Las claves serán las palabras y los valores son las definiciones de las mismas. El tipo para las claves será `key_t` y para los valores `value_t`, ambos definidos en el archivo **[key_value.h](./ej3/key_value.h)**. De esta manera, variando la definición de las claves y valores podemos hacer diccionarios que contengan distintos tipos. Para este ejercicio en particular se necesitará guardar strings en el diccionario, por lo tanto `key_t` y `value_t` se definen ambos como sinónimos del TAD String implementado en el ejercicio 2 de donde debe copiarse el archivo **[string.c](./ej2/string.c)**.

Las operaciones del TAD Diccionario se listan a continuación:

| **Función**                                | **Descripción**                                                      |
|--------------------------------------------|----------------------------------------------------------------------|
|dict_t dict_empty(void)                     | Crea un diccionario vacío                                            |
|dict_t dict_add(dict_t dict, key_t word, value_t def)|Agrega una nueva palabra word junto con su definición def. En caso que word ya esté en el diccionario, se actualiza su definición con def|
|value_t dict_search(dict_t dict, key_t word)| Devuelve la definición de word contenida en el diccionario. Si no se encuentra devuelve NULL|
|bool dict_exists(dict_t dict, key_t word)   | Indica si la palabra word está en el diccionario dict                |
|unsigned int dict_length(dict_t dict)       | Devuelve la cantidad de palabras que tiene actualmente el diccionario dict|
|dict_t dict_remove(dict_t dict, key_t word) | Elimina la palabra word del diccionario. Si la palabra no se encuentra devuelve el diccionario sin cambios.|
|dict_t dict_remove_all(dict_t dict)         | Elimina todas las palabras del diccionario dict                      |
|void dict_dump(dict_t dict, FILE *file)     | Escribe el contenido del diccionario dict en el archivo file         |
|dict_t dict_destroy(dict_t dict)            | Destruye la instancia dict                                           |

Para implementar la mayoría de las operaciones pueden adaptar el código hecho en el **[ejercicio 1](./ej1/)**.

```
💡Se recomienda dedicar un tiempo para estudiar todos los archivos
involucrados y así entender el desarrollo en general.
Recordar que en los archivos de headers (los .h) se encuentran las
descripciones y guías para la correcta implementación.
```
```
❗Asegurarse de que la implementación esté libre de memory leaks 
usando la herramienta valgrind con la opción --leak-check=full
```

**a)** Implementar el TAD Diccionario. Completar la definición de la invariante de representación y *chequear las pre y post condiciones de* **[dict.h](./ej3/dict.h)** al estilo de lo que se vio en **[abb.c](./ej1/abb.c)** en el ejercicio 1. Asegurarse de mantener el encapsulamiento del TAD y la abstracción de los tipos `key_t` y `value_t`.

**b)** Completar la interfaz de usuario con las llamadas a las funciones que correspondan según la operación elegida por el usuario.

**c)** Copiar el **[Makefile](./ej1/Makefile)** del ejercicio 1 y modificarlo para poder compilar este ejercicio y generar el ejecutable `dictionary`, es decir poder probar el ejercicio haciendo:
```bash
$ make
```
y luego
```bash
$ ./dictionary
```