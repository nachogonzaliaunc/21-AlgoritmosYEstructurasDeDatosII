#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack *next;
    unsigned int size;      // add this tuple
};

stack stack_empty() {
    stack s = NULL; 
    return s;
}

stack stack_push(stack s, stack_elem e) {
    // add top to the beginning of the stack
    stack p = NULL;
    p = malloc(sizeof(struct _s_stack));

    p->elem = e;
    p->size = (s == NULL) ? 1 : s->size + 1;
    p->next = s;

    return p;
}

stack stack_pop(stack s) {
    assert(s != NULL);
    stack p = s;
    s = s->next;
    s->size--;
    free(p);
    p = NULL;

    return s;
}

unsigned int stack_size(stack s) { return (s == NULL) ? 0 : s->size; }

stack_elem stack_top(stack s) {
    assert(s != NULL);
    return s->elem;
}

bool stack_is_empty(stack s) { return (s == NULL); }

stack_elem *stack_to_array(stack s) {
    assert(s != NULL);
    stack_elem *arr = NULL;
    unsigned int size = s->size;

    if(s != NULL) {
        arr = (stack_elem *)calloc(s->size, sizeof(stack_elem));
        
        for(int i = size - 1; i >= 0; i--) {
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
        p->next = NULL;
        free(p);
    }
    return s;
}