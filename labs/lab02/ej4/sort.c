#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    for (unsigned int j = i; j >= 1; j--) {
        if (goes_before(a[j],a[j-1])) swap(a, j, j-1);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


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
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
