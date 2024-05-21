#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"

struct _s_stack {

    stack_elem elem;
    stack next;
};

stack stack_empty(){
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    // add top to the beginning of the stack
    stack p = malloc(sizeof(struct _s_stack));
    
    p->elem = e;
    p->next = s;

    return p;
}

stack stack_pop(stack s){
    assert(s != NULL);

    struct _s_stack *p = NULL;
    p = s;
    s = s->next;
    free(p);

    return s;
}

unsigned int stack_size(stack s){
    unsigned int size = 0;
    while(s != NULL) {
        size++;
        s = s->next;
    }
    return size;
}

stack_elem stack_top(stack s){
    assert(s != NULL);
    return s->elem;
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    stack p = s;
    stack_elem *arr = NULL;
    arr = calloc(stack_size(s) , sizeof(stack_elem));
    unsigned int length = stack_size(s);
    for (int i = length - 1; i >= 0 ; i--) {
        arr[i] = p->elem;
        p = p->next;
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