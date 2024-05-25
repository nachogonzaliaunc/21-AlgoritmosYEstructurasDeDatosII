#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s) {
    // if s.elems = NULL -> size must be 0
    // if s.elems != NULL -> size must be higher than 0
    return ((s->elems == NULL && s->size == 0) || (s->elems != NULL && s->size > 0u));
}

stack stack_empty() {
    stack s = malloc(sizeof(struct _s_stack));
    s->elems = NULL;
    s->size = 0u;
    s->capacity = 0u;
    assert(invrep(s));
    return s;
}

stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));
    if(s->elems == NULL) {
        s->capacity = 1u;
        s->elems = calloc(s->capacity, sizeof(stack_elem));
    }
    else {
        s->capacity *= 2;
        s->elems = realloc(s->elems, s->capacity * sizeof(stack_elem));
    }

    s->elems[s->size] = e;
    s->size++;

    assert(invrep(s));
    return s;
}

stack stack_pop(stack s) {
    assert(invrep(s) && s->size != 0);
    s->size--;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s) { return s->size; }

stack_elem stack_top(stack s) {
    assert(invrep(s) && s->size != 0);
    return s->elems[s->size-1u];
}

bool stack_is_empty(stack s) { return (s->size == 0u); }

stack_elem *stack_to_array(stack s) {
    assert(invrep(s) && s->size != 0);
    unsigned int size = s->size;
    stack_elem *array = NULL;

    if(s->elems != NULL) {
        array = calloc(size, sizeof(stack_elem));
        for(int i = size - 1; i >= 0; i--) {
            array[i] = s->elems[i];
        }
    }
    assert(invrep(s));
    return array;
}

stack stack_destroy(stack s) {
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return s;
}