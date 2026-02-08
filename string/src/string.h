#ifndef STRING_H
#define STRING_H

#include <stdint.h>

typedef struct _string string_t;

/**
 * Creates a new empty string.
 *
 * @return pointer to the new string.
 */
string_t *create_empty();

/**
 * Creates a new string, given a sequence of chars.
 *
 * @param input_string pointer to the char sequence to assign.
 * @return pointer to the new string, whose value is a copy of input_string.
 */
string_t *create_from(uint8_t *input_string);

/**
 * Concat a sequence of chars to the input string, returning a pointer to the new string. If initialization of the new 
 * string fails, NULL is returned. If the input sequence to concat, or the input string to concat the sequence are NULL
 * then NULL is returned. 
 * 
 * @param input_string pointer to the string to concat.
 * @param sequence_to_concat sequence of char to concat to the input string.
 * @return pointer to the new string, resulting from the concatenation operation.
 */
string_t *concat_char(string_t *input_string, char *sequence_to_concat);

/**
 * Concat a string to the input string, returning a pointer to the new string. If initialization of the new 
 * string fails, NULL is returned. If one of the input string is NULL or no more valid, then NULL will be returned.
 * 
 * @param input_string pointer to the string to concat.
 * @param string_to_concat string to concat to the input string.
 * @return pointer to the new string, resulting from the concatenation operation.
 */
string_t *concat_string(string_t *input_string, string_t *string_to_concat);

/**
 * Release the memory assigned to input_string, returning the pointer to the released string.
 *
 * @param input_string pointer to string to release.
 * @return pointer to input_string, no more valid to use.
 */
string_t *destroy(string_t *input_string);

#endif
