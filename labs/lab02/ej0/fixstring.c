#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;
    // walk through the array (string) and count each position until \0
    for (unsigned int i = 0; i < FIXSTRING_MAX && s[i] != '\0'; i++) { length++; }

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool res = true;
    unsigned int length = fstring_length(s1);

    for (unsigned int i = 0; i < length && res; i++) {
        // If the words have different lengths or if their letters don't match, they are different
        if (s1[i] != s2[i] || length != fstring_length(s2)) res = false;
    }

    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool res = true;
    unsigned int length = fstring_length(s1);

    for (unsigned int i = 0; i < length && res; i++) {
        if (s1[i] < s2[i]) return res;          // If the first letter is smaller alphabetically, the word as a whole is smaller too
        else if (s1[i] == s2[i]) res = true;    // If the letters are the same, compare the next pair
        else res = false;                       // If the first letter is larger alphabetically, the word as a whole is also larger
    }

    return res;
}

