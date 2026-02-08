#ifndef CONCAT_H
#define CONCAT_H

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

#endif
