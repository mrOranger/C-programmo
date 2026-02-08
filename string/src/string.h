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
 * Returns a copy of the internal char sequence of the string.
 *
 * @param pointer to string to extract the internal char sequence.
 * @return pointer to copy of internal character sequence of string.
 */
char *get_character_sequence (string_t *string);

/**
 * Returns a copy of the length of a string.
 *
 * @param pointer to string to get the length.
 * @return copy of length of the string.
 */
uint8_t get_length (string_t *string);

/**
 * Checks if the string is valid or not.
 *
 * @param pointer to string to check the validity.
 * @return copy of the validity field of the string.
 */
uint8_t is_valid (string_t *string);

/**
 * Release the memory assigned to input_string, returning the pointer to the released string.
 *
 * @param input_string pointer to string to release.
 * @return pointer to input_string, no more valid to use.
 */
string_t *destroy(string_t *input_string);

#endif
