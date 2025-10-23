#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

int main (int argc, const char** argv) {

    printf("sizeof(char) = %lu byte\n", sizeof(char));
    printf("sizeof(short int) = %lu byte\n", sizeof(short int));
    printf("sizeof(int) = %lu byte\n", sizeof(int));
    printf("sizeof(long int) = %lu byte\n", sizeof(long int));
    printf("sizeof(long long int) = %lu byte\n", sizeof(long long int));
    printf("sizeof(float) = %lu byte\n", sizeof(float));
    printf("sizeof(double) = %lu byte\n", sizeof(double));
    printf("sizeof(long double) = %lu byte\n", sizeof(long double));

    printf("sizeof(int8_t) = %lu byte\n", sizeof(int8_t));
    printf("sizeof(uint8_t) = %lu byte\n", sizeof(uint8_t));
    printf("sizeof(int16_t) = %lu byte\n", sizeof(int16_t));
    printf("sizeof(uint16_t) = %lu byte\n", sizeof(uint16_t));
    printf("sizeof(int32_t) = %lu byte\n", sizeof(int32_t));
    printf("sizeof(unit32_t) = %lu byte\n", sizeof(uint32_t));
    printf("sizeof(int64_t) = %lu byte\n", sizeof(int64_t));
    printf("sizeof(unit64_t) = %lu byte\n", sizeof(uint64_t));

    printf("------------------------------------\n");
    printf("[signed char]: min = %d, max = %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("[unsigned char]: min = %d, max = %d\n", 0, UCHAR_MAX);
    printf("[signed short int]: min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);
    printf("[unsigned short int]: min = %d, max = %d\n", 0, USHRT_MAX);
    printf("[signed int]: min = %d, max = %d\n", INT_MIN, INT_MAX);
    printf("[unsigned int]: min = %d, max = %d\n", 0, UINT_MAX);
    printf("[signed long int]: min = %ld, max = %ld\n", LONG_MIN, LONG_MAX);
    printf("[unsigned long int]: min = %d, max = %lu\n", 0, ULONG_MAX);
    printf("[float]: min = %f, max = %f\n", FLT_MIN, FLT_MAX);
    printf("[double]: min = %f, max = %f\n", DBL_MIN, DBL_MAX);

    printf("------------------------------------\n");
    float a_number = 1.123;
    unsigned short int another_number = (unsigned short int)a_number;
    printf("a_number = %f has been converted in %u, loosing some information ...\n", a_number, another_number);

    return 0;
}
