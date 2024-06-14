#ifndef _ABB_H
#define _ABB_H

#include <stdbool.h>

typedef struct _s_abb * abb;

typedef int abb_elem;

typedef enum {ABB_IN_ORDER, ABB_PRE_ORDER, ABB_POST_ORDER} abb_ordtype;

abb abb_empty(void);
/* DESC: Creates an empty tree
 *
 * PRE : {true}
 *     tree = abb_empty();
 * POS : {tree --> ABB && abb_is_empty(tree)}
 */

abb abb_add(abb tree, abb_elem e);
/* DESC: Adds element `e` to the tree. If `e` is already in `tree` the
 *       call has no efect.
 *
 * PRE : {tree --> ABB}
 *     tree = abb_add(tree, e);
 * POS : {tree --> ABB && !abb_is_empty(tree)}
 */

bool abb_is_empty(abb tree);
/* DESC: Returns true if `tree` has no elements inside.
 *
 * PRE : {tree --> ABB}
 *     is_empty = abb_is_empty(tree);
 */

bool abb_exists(abb tree, abb_elem e);
/* DESC: Returns true if the given element `e` exists in the tree.
 *
 * PRE : {tree --> ABB}
 *     exists = abb_exists(tree, e);
 * POS : {tree --> ABB && (abb_length(tree)!=0 || !exists)}
 */

unsigned int abb_length(abb tree);
/* DESC: Returns the number of elements in the tree
 *
 * PRE : {tree --> ABB}
 *     length = abb_length(tree);
 * POS : {tree --> ABB && (abb_is_empty(tree) || length > 0)}
 */

abb abb_remove(abb tree, abb_elem e);
/* DESC: Removes the given element. If `e` is not in the tree, it does nothing
 *       an returns the tree unchanged
 *
 * PRE : {tree --> ABB}
 *     tree = abb_remove(tree, e);
 * POS : {tree --> ABB && !abb_exists(tree, e)}
 */

abb_elem abb_root(abb tree);
/* DESC: Returns the element at the root of the tree
 *
 * PRE : {tree --> ABB && !abb_is_empty(tree)}
 *     root = abb_root(tree);
 * POS : {tree --> ABB && abb_exists(tree, root)}
 */

abb_elem abb_max(abb tree);
/* DESC: Returns the largest element of the tree
 *
 * PRE : {tree --> ABB && !abb_is_empty(tree)}
 *     max_e = abb_max(tree);
 * POS : {tree --> ABB && abb_exists(tree, max_e)}
 */

abb_elem abb_min(abb tree);
/* DESC: Returns the smallest element of the tree
 *
 * PRE : {tree --> ABB && !abb_is_empty(tree)}
 *     min_e = abb_min(tree);
 * POS : {tree --> ABB && abb_exists(tree, min_e)}
 */

void abb_dump(abb tree, abb_ordtype ord);
/* DESC: Shows the elements of `tree` on the screen. Elements are shown by
 * walking the tree using the Depth First Search (DFS) algorithm. The order
 * used to visit elements is given by `ord` as follows:
 *
 * ABB_IN_ORDER  : Use the in-order method for visiting elements
 * ABB_PRE_ORDER : Use the pre-order method for visiting elements
 * ABB_POST_ORDER: Use the pos-order method for visiting elements
 *
 * For more information about the DFS algorithm look at the "Depth-first search"
 * section of [https://en.wikipedia.org/wiki/Tree_traversal].
 *
 * PRE : {tree --> ABB}
 *     abb_dump(tree, ord);
 */

abb abb_destroy(abb tree);
/* DESC: Destroy the given tree, freeing all the allocated resources.
 *
 * PRE : {tree --> ABB}
 *     tree = abb_destroy(tree);
 * POS : {tree == NULL}
 */

#endif
