#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    for (unsigned int j = i; j >= 1; j--) {
        if (goes_before(a[j],a[j-1])) swap(a, j, j-1);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a, i));
    }
}


/*
    goes_before function determines whether a pair of consecutive elements in an array are unsorted
    It doesn't make a difference between signs, so if I execute:
    goes_Before(0, -1) returns false, because it considers them sorted
*/