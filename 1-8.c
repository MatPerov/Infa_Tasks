#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    scanf("%i %i %i", &a,&b,&c);
    if (a < c)
        a = c;
    else
        while (a % c != 0)
            a += 1;
    for (int i = a; i <= b; i += c)
        printf("%i ", i);
}