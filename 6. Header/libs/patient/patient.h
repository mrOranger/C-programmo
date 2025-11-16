#ifndef PATIENT_H
#define PATIENT_H

#include <stdint.h>

struct patient {
    char*   tax_code;
    char*   first_name;
    char*   last_name;
    uint8_t age;
};

typedef struct patient Patient;

Patient init_patient (char* tax_code, char* first_name, char* last_name, uint8_t age);

void set_tax_code(Patient patient, char* tax_code);
void set_first_name(Patient patient, char* first_name);
void set_last_name(Patient patient, char* last_name);
void set_age(Patient patient, uint8_t age);

char* get_tax_code (Patient patient);
char* get_first_name (Patient patient);
char* get_last_name (Patient patient);
uint8_t get_age (Patient patient);

void print_patient (Patient patient);

#endif
