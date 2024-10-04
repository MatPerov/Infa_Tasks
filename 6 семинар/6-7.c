#include <stdio.h>
int exchange(int* pa, int b) {
    int num = *pa;
    *pa = 20;
    return num;
}

int main()
{
    int a = 10;
    printf("%i\n", exchange(&a, 20));  
    printf("%i\n", a);                 
}
