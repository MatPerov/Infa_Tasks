#include <stdio.h>
int adder(int a) {
    static int sum = 0;
    sum += a;
    return sum;
}
int main()
{
    printf("%i\n", adder(10));  
    printf("%i\n", adder(15));  
    printf("%i\n", adder(70)); 
}