#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty() {
    stack s = malloc(sizeof(struct _s_stack));
    s->elems = NULL;
    s->size = 0u;
    s->capacity = 0u;
    return s;
}

stack stack_push(stack s, stack_elem e) {
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

    return s;
}

stack stack_pop(stack s) {
    assert(s->size != 0);
    s->size--;
    return s;
}

unsigned int stack_size(stack s) {
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(s->size != 0);
    return s->elems[s->size-1u];
}

bool stack_is_empty(stack s) {
    return (s->size == 0u);
}

stack_elem *stack_to_array(stack s) {
    assert(s->size != 0);
    unsigned int size = s->size;
    stack_elem *array = NULL;

    if(s->elems != NULL) {
        array = calloc(size, sizeof(stack_elem));
        for(unsigned int i = 0; i < size; i++) {
            array[i] = stack_top(s);
            s = stack_pop(s);
        }
    }

    return array;
}

stack stack_destroy(stack s) {
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return s;
}