#include <stdio.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t pair;
    pair.values[0] = x;
    pair.values[1] = y;

    return pair;
}

int pair_first(pair_t p) { return p.values[0]; }

int pair_second(pair_t p) { return p.values[1]; }

pair_t pair_swapped(pair_t p) {
    pair_t q;
    q.values[0] = p.values[1];
    q.values[1] = p.values[0];

    return q;
}

pair_t pair_destroy(pair_t p) { return p; }