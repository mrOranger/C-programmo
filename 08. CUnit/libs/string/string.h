#ifndef STRING_H
#define STRING_H

#include <stdint.h>

typedef struct _string String;

String* create_empty();
String* create_from_string(char* input_string);

size_t size(String* input_string);
char* value(String* input_string);
uint8_t valid(String* input_string);

uint8_t equals(String* first_string, String* second_string);
uint8_t includes(String* input_string, String* search_string);
uint8_t ends_with(String* input_string, String* search_string);
uint8_t starts_with(String* input_string, String* search_string);

String* at(String* input_string, size_t index);
String* lower(String* input_string);
String* upper(String* input_string);
String* concat(String* input_string, String* concat_string);
String* repeat(String* input_string, uint8_t count);

int32_t index_of(String* input_string, String* search_string);

void destroy(String* string);

#endif
