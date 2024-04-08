#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fixstring aux;
    fstring_set(aux, a[i]);
    fstring_set(a[i], a[j]);
    fstring_set(a[j], aux);
}

bool goes_before(fixstring x, fixstring y) { return fstring_less_eq(x, y); }

bool goes_before_length(unsigned int x, unsigned int y) { return x <= y; }

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

bool array_is_sorted_length(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before_length(fstring_length(array[i-1]), fstring_length(array[i]))) {
        i++;
    }
    return (i >= length);
}