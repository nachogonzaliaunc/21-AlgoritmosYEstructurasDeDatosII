#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int lft, unsigned int rgt) {
    unsigned int ppiv = lft;
    unsigned int i = lft+1;
    unsigned int j = rgt;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) i++;
        else if (goes_before(a[ppiv], a[j])) j--;
        else swap(a, i, j);
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int lft, unsigned int rgt) {
    if (lft < rgt) {
        unsigned int piv = partition(a, lft, rgt);
        quick_sort_rec(a, lft, piv == 0 ? piv : piv-1);
        quick_sort_rec(a, piv == rgt ? rgt : piv+1, rgt);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
