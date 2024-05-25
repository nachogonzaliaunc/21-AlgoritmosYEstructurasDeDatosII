#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack *next;
};

stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    // add top to the beginning of the stack
    stack p = malloc(sizeof(struct _s_stack));
    if(p == NULL) exit(EXIT_FAILURE);
    p->elem = e;
    p->next = s;

    return p;
}

stack stack_pop(stack s) {
    assert(s != NULL);
    stack p = s;
    s = s->next;
    free(p);
    p = NULL;

    return s;
}

unsigned int stack_size(stack s) {
    unsigned int size = 0;
    while(s != NULL) {
        size++;
        s = s->next;
    }
    return size;
}

stack_elem stack_top(stack s) {
    assert(s != NULL);
    return s->elem;
}

bool stack_is_empty(stack s) { return (s == NULL); }

stack_elem *stack_to_array(stack s) {
    stack_elem *arr = NULL;

    if(s != NULL) {
        unsigned int size = stack_size(s);
        arr = (stack_elem *)calloc(size, sizeof(stack_elem));
        
        for(int i = size-1; i >= 0; i--) {
            arr[i] = s->elem;
            s = s->next;
        }
    }
    return arr;
}

stack stack_destroy(stack s) {
    stack p = NULL;
    while(s != NULL) {
        p = s;
        s = s->next;
        free(p);
    }
    s = NULL;
    return s;
}