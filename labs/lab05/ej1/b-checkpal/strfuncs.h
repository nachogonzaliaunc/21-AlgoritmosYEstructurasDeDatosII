#ifndef _STRFUNCS_H
#define _STRFUNCS_H

#include <stdbool.h>

size_t string_length(const char *str);
/*
 * calculate the string length pointed to by str
 */

char *string_filter(const char *str, char c);
/*
 * returns a new string in dynamic memory,
 * is obtained by taking the different characters from str
 * from the character c
 */

bool string_is_symmetric(const char *str);
/*
 * indicates whether the string pointed to by str is symmetric
 * such as the strings "aba", "abcba", "a", ""
*/


#endif  // _STRFUNCS_H