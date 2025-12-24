#ifndef STRING_H
#define STRING_H

#include <stdint.h>

typedef struct _string String;

/**
 * Creates a new empty string, returing the pointer at the area where is string has been initialized. If no more memory
 * is available, then NULL will be returned.
 *
 * @return Generic pointer to the area rf the new empty string. 
 */
void* create_empty();

/**
 * Creates a new instance of string, whose internal value is a copy of the input sequence of chars. If an invalid
 * pointer has been used in place of input_string, then NULL is returned. Moreover, if no more memory is available, to
 * create the new string, NULL will be returned.
 *
 * @param input_string Generic pointer to the sequence of char used to create the new string.
 *
 * @return Generic pointer to the area of the new string. 
 */
void* create_from_string(void* input_string);

/**
 * Returns the size of input_string. If NULL or an invalid string is used in place of input_string, 0 will be returned.
 *
 * @param input_string Generic pointer to the string that will be used to compute the size. 
 * 
 * @return Actual size of the input_string.
 */
size_t size(void* input_string);

/**
 * Returns a pointer to the copy of the sequence of chars of the input string. If NULL or an invalid string is passed 
 * in place of input_string NULL will be returned.
 * 
 * @param input_string Pointer to String that we would like to extract the internal sequence of chars.
 *
 * @return Pointer to a copy of the internal sequence of input_string.
 */
void* value(void* input_string);

/**
 * Returns a flag used to check if the input string is still valid or not. 0 will be returned if the input string is not
 * valid no more, or is NULL. Otherwise, 1 will be returned if the string is still valid.
 *
 * @param input_string Pointer to String, that will be used to check the validity.
 *
 * @return Unsigned short integer, where 0 means false and 1 means true.
 */
uint8_t valid(void* input_string);

/**
 * Checks if two strings are equals or not. An unsigned short integer is return indicating that the strings are equals
 * or not. Thus, 0 will indicate that the two strings are not equals, otherwise 1 will be returned. Comparison between 
 * NULL or no more valid string, will always return 0.
 *
 * @param first_string Pointer to String used to check if contains second_string.
 * @param second_string Pointer to String that should be included in first_string.
 *
 * @return Unsigned short int, where 0 means that the strings are not equals, otherwise 1 will be returned.
 */
uint8_t equals(void* first_string, void* second_string);

/**
 * Checks if one string is included in another. An unsigned short integer value is returned indicating the result of the
 * comparision. Comparision between NULL or invalid strings returns always 0.
 *
 * @param input_string Pointer to the string that should contain search_string.
 * @param search_string Pointer to the string that should be included in input_string.
 *
 * @return Unsinged short int, where 0 indicates that search_string is included in input_string, 1 otherwise.
 */
uint8_t includes(void* input_string, void* search_string);

/**
 * Checks if a string is the final sequence of another string. An unsigned short integer is used to indicate that the
 * string to looking for the s included or not in the ending sequence of another. Comparision between NULL or invalid 
 * string always return 0.
 *
 * @param input_string Pointer to the base string where looking for a certain sequence.
 * @param search_string Pointer to the string that should be included in the input_string.
 *
 * @return Unsinged short int, where 1 indicates that search_string is the final sequence of in input_string, 0 otherwise.
 */
uint8_t ends_with(void* input_string, void* search_string);

/**
 * Checks if a string is the initial sequence of another string. An unsigned short integer is used to indicate that the
 * string to looking for the starting sequence is included or not. Comparision between NULL or invalid string always
 * return 0.
 *
 * @param input_string Pointer to the input_string where looking for the initial sequence.
 * @param search_string Pointer to the search_string to check if it is contained inside the input_string.
 *
 * @return Unsinged short int, where 1 indicates that search_string is the starting sequence of in input_string, 0 otherwise.
 */
uint8_t starts_with(void* input_string, void* search_string);

/**
 * Creates a new string, composed by the single char of the input_string indicated by the input index. If the index is
 * not in the validity range represented by 0 and the length of the input_string, NULL will be returned. If input_string 
 * is NULL or is not a valid string, NULL will be returned. Moreover, if no more memory il available to create the new
 * istance, NULL will be returned.
 *
 * @param input_string Pointer to the input string where the char will be extracted.
 * @param index Index of input_string where the character should be extracted.
 *
 * @return New string containing a single char, otherwise NULL.
 */
void* at(void* input_string, size_t index);

/**
 * Returns a new string, that is composed by the lowercase chars of the input_string. If the input string is NULL or is
 * no valid no more, NULL will be returned. Moreover, if no more memory is available to create the new instance, NULL
 * will be returned.
 *
 * @param input_string Pointer to the input string that will be used to compute the lowercase couter-part.
 * 
 * @return New string, whose internal value is the lowecase counter-part of the input_string.
 */
void* lower(void* input_string);

/**
 * Returns a new string, that is composed by the uppercase chars of the input_string. If the input string is NULL or is
 * no valid no more, NULL will be returned. Moreover, if no more memory is available to create the new instance, NULL
 * will be returned.
 *
 * @param input_string Pointer to the string that will be used to compute the uppercase counter-part.
 * 
 * @return New string, whose internal value is the uppercase counter-part of the input_string.
 */
void* upper(void* input_string);

/**
 * Returns a new string, that is composed by the concatenation of the input_string and the concat_string. If one of the
 * input string is NULL or is no more valid, NULL will be returned. Moreover, if no memory is available to create the
 * new instance, NULL will be returned.
 *
 * @param input_string Pointer to the input string that will be used as the base part of the new string.
 * @param concat_string Pointer to the string that will be used to concatenante to the input_string.
 *
 * @return New string, represented by the concatenation of input_string with concat_string.
 */
void* concat(void* input_string, void* concat_string);

/**
 * Creates a new string, that is represented by the repetition of input_string. If input_string is NULL or is no valid
 * no more, then NULL will be returned. Moreover, if no memory is available, then NULL will be returned. If the number
 * of count is 0 or an invalid number, then an empty string is returned.
 *
 * @param input_string Pointer to the input strint that will be used as base for the repetitions. 
 * @param count Number of repetitions.
 *
 * @return New string, that is the repetition of input_string.
 */
void* repeat(void* input_string, uint8_t count);

/**
 * Creates a new string, that is represented by the replacing operation of the replace_pattern contained in the
 * input_string with string_to_replace. Resizing operation will be done if necessary. If input_string is NULL or an
 * invalid string then NULL will be returned. If the replace pattern is NULL or an invalid string, then NULL will be
 * returned. Moreover, if string_to_replace is NULL or an invalid string, then NULL will be returned.
 *
 * @param input_string Pointer to the base string where the search will be applied.
 * @param replace_patter Pointer to the string representing the piece of string contained in input_string to replace.
 * @param string_to_replace Pointer to the string that will be replaced inside input_string.
 *
 * @return Pointer to the new string that is the result of the replacing operation.
 */
void* replace(void* input_string, void* replace_patter, void* string_to_replace);

/**
 * Index of the sequence represented by search_string that is contained in input_string. If one between input_string or
 * search_string is NULL or no more valid, then NULL will be returned. Moreover, if seach_string is not included inside
 * input_string then -1 will be returned.
 *
 * @param input_string Pointer to the base string where the search will be applied.
 * @param search_string Pointer to the string that will be used as searching key.
 *
 * @return First index where seach_string starts inside input_string.
 */
int32_t index_of(void* input_string, void* search_string);


/**
 * Release the memory of input_string, marking it as no valid no more.
 *
 * @param input_string Pointer to the string to release. 
 */
void destroy(void* input_string);

/**
 * Copy n bytes from source string, from start_index to end_index. If the source is NULL, then NULL will be returned.
 * Moreover, if start_index or end_index are no valid values, then NULL will be returned.
 * 
 * @param source Pointer to the source string to copy.
 * @param n_bytes Number of bytes to copy.
 * @param start_index Start index to copy.
 * @param end_index End index where copy the bytes.
 * 
 * @return Pointer to the new string, whose length is end_index - start_index.
 */
void* string_ncopy (void* source, size_t n_bytes, size_t start_index);

/**
 * Copy n_bytes from the source string in a new string, and returns the pointer to the new string. If source is NULL,
 * or n_bytes is 0, then NULL will be returned.
 *
 * @param source Pointer to the source string.
 * @param n_bytes number of bytes to copy from the source string.
 *
 * @return Pointer to the new string made by the copy of the source string.
 */
void* string_copy(void* source, size_t n_bytes);

/**
 * Computes the length of the source string. If the source is NULL, then 0 will be returned.
 * 
 * @param source String source to compute the length.
 * 
 * @return length of the source string.
 */
size_t string_length(void* source);

#endif
