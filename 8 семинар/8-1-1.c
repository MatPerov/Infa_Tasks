#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = malloc(8);

    *p = 123;
    printf("%i\n", *p);

    free(p);
}