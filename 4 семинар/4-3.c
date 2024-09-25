#include <stdio.h>
float yearfrac(int year, float day)
{
    float result;
    if (year % 4 == 0) {
        result = day / 366;
    }
    else
        result = day / 365;
    return result;
}

int main()
{
    int year;
    float day;
    scanf("%i %f", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
}