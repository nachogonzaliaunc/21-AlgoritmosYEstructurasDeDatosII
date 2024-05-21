#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 50

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered = NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    char *input = fgets(user_input, MAX_LENGTH, stdin);

    if(input == NULL) {
        printf("Error reading chars.\n");
        exit(EXIT_FAILURE);
    }

    user_input[string_length(user_input) - 1] = '\0';

    filtered = string_filter(user_input, ignore_chars[0]); // initialize filtered
    for (unsigned int i = 0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *tmp = string_filter(filtered, ignore_chars[i]); // here ask for memory, filtered points to the heap
        free(filtered);
        filtered = tmp;
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");

    free(filtered);
    
    return EXIT_SUCCESS;
}

