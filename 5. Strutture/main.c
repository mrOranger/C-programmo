#include <stdio.h>
#include <stdint.h>

struct person {
    char* first_name;
    char* last_name;
    uint8_t age;
};

typedef struct person Person;

Person init_person (char* first_name, char* last_name, uint8_t age)
{
    Person person;

    person.first_name = first_name;
    person.last_name = last_name;
    person.age = age;

    return person;
}

void print_person (Person person)
{
    printf("First Name: %s\n", person.first_name);
    printf("Last Name:  %s\n", person.last_name);
    printf("Age:        %u\n", person.age);
}

int main (const int argc, const char** argv)
{
    Person person = init_person("Mario", "Rossi", (uint8_t)29);

    printf ("sizeof(struct person)  = %lu byte\n", sizeof(struct person));
    printf ("sizeof(Person)         = %lu byte\n", sizeof(Person));
    printf ("sizeof(uint8_t)        = %lu byte\n", sizeof(uint8_t));
    printf ("sizeof(char*)          = %lu byte\n", sizeof(char*));

    print_person(person);

    return 0;
}
