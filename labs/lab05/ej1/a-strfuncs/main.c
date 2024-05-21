#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"


int main(void) {
    char *some_str="h.o.l.a m.u.n.d.o.!";
    char *some_symmetric="abcba";
    char *some_asymmetric="ab";
    char *filtered=NULL;

    filtered = string_filter(some_str, '.');
    printf("original: '%s' (%ld)\n"
           "filtrada: '%s' (%ld)\n\n"
           "La cadena '%s' resulta %s simétrica\n"
           "La cadena '%s' resulta %s simétrica\n",
           some_str, string_length(some_str),
           filtered, string_length(filtered),
           some_symmetric,  string_is_symmetric(some_symmetric) ? "ser": "NO ser",
           some_asymmetric, string_is_symmetric(some_asymmetric) ? "ser": "NO ser");

    free(filtered);
    filtered=NULL;

    return EXIT_SUCCESS;
}

