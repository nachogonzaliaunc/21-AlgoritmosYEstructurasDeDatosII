#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H

#include <stdbool.h>
#include <stdio.h>


typedef struct s_stringbuffer *stringbuffer;


stringbuffer stringbuffer_empty(void);
/*
 * DESC: Creates an instance of stringbuffer with no characters.
 * 
 *   sb = stringbuffer_empty();
 * POS: {sb --> stringbuffer && stringbuffer_is_empty(sb)}
 */


stringbuffer stringbuffer_create(const char *word);
/*
 * DESC: Creates an instance of stringbuffer that contains 
 * the same characters of the `word` given.
 * 
 * PRE: {word != NULL}
 *   sb = stringbuffer_create();
 * POS: {sb --> stringbuffer}
 */


bool stringbuffer_is_empty(stringbuffer sb);
/*
 * DESC: Indicates whether the sb is empty or not.
 *
 * PRE: {sb --> stringbuffer}
 *   is_empty = stringbuffer_is_empty(sb);
 * POS: {sb --> stringbuffer}
 *
 */


stringbuffer stringbuffer_append(stringbuffer sb, const char c);
/*
 * DESC: Appends the character `c` to the end of the string `sb`.
 *
 * PRE: {sb --> stringbuffer}
 *   sb = stringbuffer_append(sb, c);
 * POS: {sb --> stringbuffer && !stringbuffer_is_empty(sb)}
 *
 */


char stringbuffer_char_at(stringbuffer sb, unsigned int index);
/*
 * DESC: Returns the character at the specified position `index` 
 * in the string `sb`.
 *
 * PRE: {sb --> stringbuffer && !stringbuffer_is_empty(sb) &&  index < stringbuffer_length(sb)}
 *   c = stringbuffer_char_at(sb, index);
 * POS: {sb --> stringbuffer && c --> char}
 *
 */


stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index);
/*
 * DESC: Removes the character at the specified position `index` 
 * in the string `sb`.
 * If `index`is great or equal than length of string `sb`, it does not remove anything
 *
 * PRE: {sb --> stringbuffer}
 *   sb = stringbuffer_remove(sb, index);
 * POS: {sb --> stringbuffer}
 *
 */


stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index);
/*
 * DESC: Replaces the character `c` at the specified position `index` 
 * in the string `sb`.
 *  
 * PRE: {sb --> stringbuffer, &&  index < stringbuffer_length(sb) }
 *   sb = stringbuffer_insert(sb, c, index);
 * POS: {sb --> stringbuffer}
 *
 */


unsigned int stringbuffer_length(stringbuffer sb);
/*
 * DESC: Returns the length of the given string `sb`.
 *
 * PRE: {sb --> stringbuffer}
 *   length = stringbuffer_length(sb);
 * POS: {sb --> stringbuffer && stringbuffer_is_empty(sb) == (length == 0)}
 *
 */


char* stringbuffer_to_string(stringbuffer sb);
/*
 * DESC: Returns an array of characteres in dynamic memory that contains all characters 
 * currently contained in the stringbuffer `sb`. 
 * The array must eventually be freed by the caller.
 *
 * PRE: {sb --> stringbuffer}
 *   array = stringbuffer_substring(sb, start, end);
 * POS: {(stringbuffer_length(sb)==0) == (array==NULL)}
 *
 */


/* Dumps the string 'sb' into the output standard */
void stringbuffer_dump(stringbuffer sb);
/*
 * DESC: Dumps the stringbuffer `sb` in the standard output.
 *
 * PRE: {sb --> stringbuffer}
 *   stringbuffer_dump(sb);
 * POS: {sb --> stringbuffer}
 *
 */


stringbuffer stringbuffer_destroy(stringbuffer sb);
/*
 * DESC: Destroys an instance of stringbuilder freeing all memory used by it
 *
 * PRE: {sb --> stringbuffer}
 *   sb = stringbuffer_destroy(sb);
 * POS: {sb == NULL}
 *
 */


#endif
