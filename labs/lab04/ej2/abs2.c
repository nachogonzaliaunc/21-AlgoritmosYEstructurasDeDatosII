#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    *y = (x >= 0) ? x : -x;
}

int main(void) {
    int a = 0, res = 0;

    a = -10;
    // here, res = 0
    absolute(a, &res);
    // here, res = 10
    printf("%d\n", res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
 * el parámetro int *y de absolute es de tipo in, pues no se modifica 
 * dentro de la funcion absolute, sólo se modifica el valor al que apunta.
 * para sus funciones, C tiene disponibles sólo parametros in
*/