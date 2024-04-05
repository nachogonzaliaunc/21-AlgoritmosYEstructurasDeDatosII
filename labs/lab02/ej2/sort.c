#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int lft, unsigned int rgt) {
    if (lft < rgt) {
        unsigned int piv = partition(a, lft, rgt);
        quick_sort_rec(a, lft, piv == 0 ? piv : piv-1);
        quick_sort_rec(a, piv == rgt ? rgt : piv+1, rgt);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
