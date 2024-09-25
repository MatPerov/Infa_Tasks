#include <stdio.h>
#include <math.h>
int main()
{
    printf("char: %hhi\n", sizeof(char));
    printf("short: %hi\n", sizeof(short));
    printf("int: %i\n", sizeof(int));
    printf("long long: %i\n", sizeof(long long));
    printf("size_t: %zu\n", sizeof(size_t));
    printf("float: %i\n", sizeof(float));
    printf("double: %i\n", sizeof(double));
    printf("int[10]: %i\n", sizeof(int[10]));
    printf("char[10]: %hhi\n", sizeof(char[10]));
}