#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

#include "fixstring.h"

void quick_sort(fixstring a[], unsigned int length);
/*
    Sort the array 'a' using the Quicksort algorithm. The resulting sort
    will be ascending according to the goes_before funtion.
    This function ordered the array alphabetically.

    The array 'a' must have exactly 'length' elements.
*/

void quick_sort_length(fixstring a[], unsigned int length);
/*
    Sort the array 'a' using the Quicksort algorithm. The resulting sort
    will be ascending according to the goes_before funtion.
    This function ordered according to the strings length.

    The array 'a' must have exactly 'length' elements.
*/

#endif
