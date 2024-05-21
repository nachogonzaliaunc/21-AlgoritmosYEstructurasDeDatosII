#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    unsigned int length = 0u;

    for(unsigned int i = 0u; str[i] != '\0'; i++) { length++; }
    
    return length;
}

char *string_filter(const char *str, char c) {
    char *res = NULL;
    res = malloc(string_length(str) * sizeof(char));
    unsigned int res_pos = 0u;

    for (unsigned int i = 0u; str[i] != '\0'; i++) {
        if(str[i] != c) {
            res[res_pos] = str[i];
            res_pos++;
        }
    }

    return res;
}

bool string_is_symmetric(const char *str) {
    bool res = true;

    for(int lft = 0u, rgt = string_length(str)-1; lft < rgt && rgt > 0; lft++, rgt--) {
        if(str[lft] != str[rgt]) res = false;
    }

    if(string_length(str) == 0) res = false;

    return res;
}