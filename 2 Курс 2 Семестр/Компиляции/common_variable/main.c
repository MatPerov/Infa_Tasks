#include <stdio.h>
#include "alice.h"
#include "bob.h"

extern int value;

int main()
{
    cat();
    dog();
    cat();
    cat();
    cat();
    dog();
    dog();

    printf("value = %i\n", value);
}