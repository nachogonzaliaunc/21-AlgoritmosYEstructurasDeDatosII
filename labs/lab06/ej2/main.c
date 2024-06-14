#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main (void) {
    char *s1 = "Hola";
    char *s2 = "mundo!";

    string str1 = string_create(s1);
    string str2 = string_create(s2);

    printf("Palabra 1: ");
    string_dump(str1, stdout);

    printf("\nPalabra 2: ");
    string_dump(str2, stdout);

    printf("\n%s <= %s: %s\n", s1, s2, string_less(str1, str2) ? "True" : "False");
    printf("%s == %s: %s\n", s1, s2, string_eq(str1, str2) ? "True" : "False");

    str1 = string_destroy(str1);
    str2 = string_destroy(str2);

    return EXIT_SUCCESS;
}