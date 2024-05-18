#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node_of_T {
    list_elem elem;
    struct node_of_T *next;
};


list empty() {
    list l = NULL;
    return l;
}

list addl(list_elem e, list l) {
    list p = malloc(sizeof(struct node_of_T));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

list destroy(list l) {
    list p = NULL;
    while (l != NULL) {
        p = l;
        l = l->next;
        p->next = NULL;
        free(p);
    }
    return l;
}

bool is_empty(list l) { return (l == NULL); }

list_elem head(list l) {
    assert((l != NULL) && "is empty list");
    return l->elem;
}

list tail(list l) {
    assert((l != NULL) && "is empty list");
    list p = l;
    l = l->next;
    p->next = NULL;
    free(p);
    return l;
}

list addr(list l, list_elem e) {
    list p = malloc(sizeof(struct node_of_T));
	p->elem = e;
	p->next = NULL;
	if(!is_empty(l)) {	
		list q = l;
		while(q->next != NULL) { q = q->next; }
		q->next = p;
	}
	else { l = p; }
	return(l);
}

int length(list l) {
    unsigned int n = 0;
    list p = l;
    while(p != NULL) {
        p = p->next;
        n++;
    }
    return n;
}

list concat(list l1, list l2) {
    list l = NULL;
    if(l1 == NULL && l2 == NULL) l = l1;
    else {
        l = l1;
        while(l->next != NULL) { l = l->next; }
        l->next = l2;
    }

    return l;
}

list_elem index(list l, int n) {
    assert(length(l) > n && "The position you are looking for doesn't exist.");
    list p = l;
    if(n > 1) {
        for(int i = 0; i < n; i++) { p = p->next; }
    }
    return p->elem;
}

list take(list l, int n) {
    list p = NULL, q = NULL;
    p = l;
    int i = 0;
    if(n == 0) {
        while(l != NULL) {
            p = l;
            l = l->next;
            p->next = NULL;
            free(p);
        }
    }
    else {
        /* find the first elem to delete */
        while(l != NULL && i < n) {
            p = p->next;
            i++;
        }
        /* delete de elements */
        while(p != NULL) {
            q = p;
            p = p->next;
            q->next = NULL;
            free(q);
        }
    }
    return l;
}


list drop(list l, int n) {
    list p = NULL;
    int i = 0;
    if(l != NULL && 0 < n) {
        while(l != NULL && i < n) {
            p = l;
            l = l->next;
            p->next = NULL;
            free(p);
            i++;
        }
    }
    return l;
}

list copy_list(list l) {
    list copy = empty();
    list p = l;
    while(p != NULL) {
		copy = addr(copy, p->elem);
		p = p->next;
	}
	return(copy);
}