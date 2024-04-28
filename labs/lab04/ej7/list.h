#ifndef _LIST_H
#define _LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* list as a pointer to structs to guarantee encapsulation */
typedef struct node_of_T *list;
typedef int list_elem;

/* Constructors */
list empty();
/* create an empty list */

list addl(list_elem e, list l);
/* adds element e to the beginning of list l */

/* Destroy */
list destroy(list l);
/* free memory if necessary */

/* Operations */
bool is_empty(list l);
/* returns true if l is empty */

list_elem head(list l);
/* returns the first element of the list l */
/*
 * PRE: not is_empty(l)
 */

list tail(list l);
/* delete the first element of the list l */
/*
 * PRE: not is_empty(l)
*/

list addr(list l, list_elem e);
/* adds element e to the end of list l */

int length(list l);
/* returns the number of elements in the list l */

list concat(list l1, list l2);
/* add all the elements of l0 to the end of l in the same order */

list_elem index(list l, int n);
/* returns the nth element of the list l */
/*
 * PRE: length(l) > n
*/

list take(list l, int n);
/* Leave only the first n elements in l, removing the rest */

list drop(list l, int n);
/* remove the first n elements from l */

list copy_list(list l);
/* Copy all elements from l to the new list */

#endif
