#ifndef STRING_H
#define STRING_H

#include <stdint.h>

typedef struct _string String;

String* create();
String* create_string(char* string);
size_t  size(String* string);
char*   value(String* string);
uint8_t valid(String* string);
String* at(String* string, size_t index);
String* upper(String* string);
String* lower(String* string);
String* concat(String* string, String* concat_string);
uint8_t includes(String* string, String* search_string);
uint8_t ends_with(String* string, String* search_string);
uint8_t starts_with(String* string, String* search_string);
int32_t index_of(String* string, String* search_string);
String* repeat(String* string, uint8_t count);
void    destroy(String* string);

#endif