#ifndef UTILS_H
#define UTILS_H

/**
 * Creates a new array cloning n_bytes from the source.
 *
 * @param source pointer to the source data to copy.
 * @param n_bytes number of bytes to copy.
 * @return pointer to the array result by the copy operation.
 */
char *clone(char *source, size_t n_bytes);

/**
 * Copy n_bytes from the source into the destination, returning the pointer to destination.
 *
 * @param source pointer to the source data to copy.
 * @param destination pointer to the destination data.
 * @return pointer to the destination data, result by the copying operation.
 */
char *copy(char *source, char *destination, size_t n_bytes);

/**
 * Calculate the length of the input sequence. If the input sequence is NULL, 0 will be returned.
 *
 * @param source input sequence of chars.
 * @return length of the input sequence.
 */
size_t length(char *source);

#endif
