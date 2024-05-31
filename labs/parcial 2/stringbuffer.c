#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "stringbuffer.h"

struct s_stringbuffer {
    struct s_node *first;
    struct s_node *last;
    unsigned int size;
};

struct s_node {
    char c;
    struct s_node *nextchar;
};

typedef struct s_node * node_t;

// Representation invariant
static bool invrep(stringbuffer sb) {
    if((sb->first == NULL && sb->last == NULL) && sb->size != 0) return false;
    else if((sb->first != NULL || sb->last != NULL) && sb->size == 0) return false;
    else return true;
}


// Creates a single node in dynamic memory with a given char
static node_t create_node(char c) {
    node_t newnode = NULL;    

    newnode = malloc(sizeof(struct s_node));
    newnode->c = c;
    newnode->nextchar = NULL;

    assert(newnode != NULL);
    return newnode;
}


// Destroy a single node
static node_t destroy_node(node_t node) {
    node->nextchar = NULL;
    free(node);
    node = NULL;

    assert(node==NULL);
    return node;
}


// Public functions of the Abstract Data Type
stringbuffer stringbuffer_empty(void) {
    struct s_stringbuffer *sb = malloc(sizeof(struct s_stringbuffer));
    sb->first = NULL;
    sb->last = NULL;
    sb->size = 0;

    assert(invrep(sb));
    return sb;
}


stringbuffer stringbuffer_create(const char *word) {
    node_t newnode = NULL;
    node_t first = NULL;
    node_t last = NULL;

    stringbuffer new_sb = stringbuffer_empty();
    new_sb->size = strlen(word);

    newnode = create_node(word[0]);
    first = newnode;
    new_sb->first = first;
    new_sb->last = first;

    for(unsigned int i = 1; i < strlen(word); i++) {
        last = create_node(word[i]);
        new_sb->last->nextchar = last;
        new_sb->last = last;
    }

    assert(invrep(new_sb) && !stringbuffer_is_empty(new_sb));
    return new_sb;
}


bool stringbuffer_is_empty(stringbuffer sb){
    assert(invrep(sb));
    return (sb->size == 0 && sb->first != NULL);
}


stringbuffer stringbuffer_append(stringbuffer sb, const char c) {
    assert(invrep(sb));
    struct s_node *new_node = create_node(c);

    if(sb->first == NULL) {
        sb->first = new_node;
        sb->last = new_node;
    }
    else {
        sb->last->nextchar = new_node;
        sb->last = new_node;
    }
    sb->size++;
    assert(invrep(sb) && !stringbuffer_is_empty(sb));

    return sb;
}


char stringbuffer_char_at(stringbuffer sb, unsigned int index) {
    assert(invrep(sb) && !stringbuffer_is_empty(sb) && index<stringbuffer_length(sb));
    unsigned pos = 0;
    node_t node = sb->first;
    while(pos < index) {
        node = node->nextchar;
        pos++;
    }
    assert(invrep(sb));
    return node->c;
}


stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index) {
    assert(invrep(sb));
    node_t node = sb->first, prev = NULL;
    unsigned pos = 0;

    if(index >= sb->size) return sb;
    else if(index == 0) {
        sb->first = sb->first->nextchar;
        destroy_node(node);
    }
    else {
        prev = sb->first;
        pos = index;
        for(unsigned int i = 0; i < pos; i++) { node = node->nextchar; }

        for(unsigned int i = 0; i < pos-1; i++) { prev = prev->nextchar; }
        prev->nextchar = node->nextchar;
        destroy_node(node);
    }

    assert(invrep(sb));
    return sb;
}


stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index) {
    assert(invrep(sb) && index < stringbuffer_length(sb));
    if(index >= sb->size) return sb;
    else {
        struct s_node *p = sb->first;
        for(unsigned int i = 0; i < index; i++) { p = p->nextchar; };
        p->c = c;
    }
    assert(invrep(sb));
    return sb;
}


unsigned int stringbuffer_length(stringbuffer sb) {
    assert(invrep(sb));
    return sb->size;
}


char* stringbuffer_to_string(stringbuffer sb) {
    assert(invrep(sb));
    char *arr = calloc(sb->size, sizeof(struct s_node));
    struct s_node *p = sb->first;
    for(unsigned int i = 0; i < sb->size; i++) {
        arr[i] = p->c;
        p = p->nextchar;
    }
    assert(invrep(sb));
    return arr;
}


void stringbuffer_dump(stringbuffer sb) {
    assert(invrep(sb));
    node_t node = sb->first;
    while (node != NULL) {
        printf("%c", node->c);
        node = node->nextchar;
    }
    printf("\n");
}


stringbuffer stringbuffer_destroy(stringbuffer sb) {
    assert(invrep(sb));
    struct s_node *p = NULL;
    while(sb->first != sb->last && sb->first->nextchar != NULL) {
        p = sb->first;
        sb->first = sb->first->nextchar;
        destroy_node(p);
    }
    free(sb->first);
    free(sb);
    sb = NULL;
    assert(sb == NULL);
    return sb;
}
