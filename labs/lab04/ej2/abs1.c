#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    y = (x >= 0) ? x : -x;
    // here, y = 10
}

int main(void) {
    int a = 0, res = 0;

    a = -10;
    absolute(a, res);
    // here, res = 0
    printf("%d\n", res);

    return EXIT_SUCCESS;
}

/*
 * Si tomamos la definición del algorítmo con el lenguaje del teórico, 
 * el valor que se imprime por pantalla es 10.
 * En C, el valor que se muestra por pantalla es 0 (valor original de res),
 * pues los valores que le paso a absolute() son enteros, en éste caso
 * absolute(a, res) es absolute(-10, 0).
 * Luego, las variables x e y tienen un scope limitado dentro de absolute,
 * dentro del bloque de codigo de absolute y = 10, pero en main, res no se modifica
*/