#include <stdio.h>

#include "libs/patient/patient.h"

int main (const int argc, const char** argv)
{
    Patient patient = init_patient("ABCDCD10H72A991K", "Mario", "Rossi", 38);
    print_patient(patient);

    return 0;
}
