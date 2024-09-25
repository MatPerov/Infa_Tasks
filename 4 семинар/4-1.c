#include <stdio.h>
unsigned long long fact(int n)
{
    unsigned long long result = 1;  /* тип данных int имеет диапазон занчений примерно от -2 до 2 миллиардов,
    в то же время факториал 13 уже больше 6 миллиардов, поэтому программа работает неправильно.*/
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int k;
    scanf("%i", &k);
    printf("%lli\n", fact(k));
}