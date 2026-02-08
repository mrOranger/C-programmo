#ifndef STRING_H
#define STRING_H

typedef struct _string string_t;

string_t* create_empty();
string_t* create(const char* char_sequence);
string_t* clone(const char* string)

string_t* destroy(const string_t* string);

#endif
