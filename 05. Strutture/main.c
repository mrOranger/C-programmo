#include <stdio.h>
#include <stdint.h>

enum age_type {
    NUMERIC,
    STRING,
};

typedef enum age_type AgeType;

union age {
    uint8_t age_number;
    char*   age_string;
};

typedef union age Age;

struct person {
    char*   first_name;
    char*   last_name;
    AgeType age_type;
    Age     age;
};

typedef struct person Person;

union elem {
    uint8_t number;
    unsigned char characters[4];
};

typedef enum Boolean {
    TRUE = 't',
    FALSE = 'c'
};


Person init_person_as_number (char* first_name, char* last_name, uint8_t age)
{
    Person person;

    person.first_name       = first_name;
    person.last_name        = last_name;
    person.age_type         = NUMERIC;
    person.age.age_number = age;

    return person;
}

Person init_person_as_string (char* first_name, char* last_name, char* age)
{
    Person person;

    person.first_name       = first_name;
    person.last_name        = last_name;
    person.age_type         = STRING;
    person.age.age_string   = age;

    return person;
}

void print_person (Person person)
{
    printf("First Name = %s\n", person.first_name);
    printf("Last Name = %s\n", person.last_name);

    if (person.age_type == NUMERIC) {
        printf("Age (uint8_t) = %u\n", person.age.age_number);
        return;
    }

    printf("Age (char*) = %s\n", person.age.age_string);
}

int main (const int argc, const char** argv)
{
    Person a_person = init_person_as_number("Mario", "Rossi", (uint8_t)29);
    printf ("sizeof(a_person) = %lu byte\n", sizeof(a_person));
    print_person(a_person);

    Person another_person = init_person_as_string("Luigi", "Verdi", "29");
    printf ("sizeof(another_person) = %lu byte\n", sizeof(another_person));
    print_person(another_person);

    union elem elements;
    elements.number = 10;
    printf("elements.number = %u\n", elements.number);
    printf(
        "elements.characters = [ %d, %d, %d, %d ]\n", 
        elements.characters[0], 
        elements.characters[1],
        elements.characters[2], 
        elements.characters[3]
    );

    return 0;
}
