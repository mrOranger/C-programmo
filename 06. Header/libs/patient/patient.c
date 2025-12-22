#include <stdio.h>

#include "patient.h"

Patient init_patient (char* tax_code, char* first_name, char* last_name, uint8_t age)
{
    Patient new_patient;

    new_patient.tax_code =      tax_code;
    new_patient.first_name =    first_name;
    new_patient.last_name =     last_name;
    new_patient.age =           age;

    return new_patient;
}

void set_first_name(Patient patient, char* first_name)
{
   patient.first_name = first_name; 
}

void set_last_name(Patient patient, char* last_name)
{
    patient.last_name = last_name;
}

void set_age(Patient patient, uint8_t age)
{
    patient.age = age;
}

void set_tax_code(Patient patient, char* tax_code)
{
    patient.tax_code = tax_code;
}

char* get_tax_code (Patient patient)
{
    return patient.tax_code;
}

char* get_first_name (Patient patient)
{
    return patient.first_name;
}

char* get_last_name (Patient patient)
{
    return patient.last_name;
}

uint8_t get_age (Patient patient)
{
    return patient.age;
}

void print_patient (Patient patient)
{
    printf("Tax Code:   %s\n", get_tax_code(patient));
    printf("First Name: %s\n", get_first_name(patient));
    printf("Last Name:  %s\n", get_last_name(patient));
    printf("Age:        %u\n", get_age(patient));
}
