#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p.values[0], p.values[1]);
}


int main(void) {
    pair_t p, q;
    // Nuevo par p
    p = pair_new(3, 4);
    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);
    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);
    // Se muestra q
    printf("q = ");
    show_pair(q);
    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

/*
    Por qué falla?
    Falla porque la estructura pair_t está especificada diferente,
    ahora en lugar de tener dos campos con nombres fst y snd de tipo entero
    tiene un único campo que es un arreglo de dos elementos llamado value.

    El diseño del TAD logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
    Logra encapsulamiento ya que logramos mas abstracción al trabajar
    con datos internos de la estructura que no son accecibles directamente
    desde fuera de su módulo
*/