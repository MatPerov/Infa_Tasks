#include <stdio.h>
unsigned long long A(int n, int k)
{
    unsigned long long result = 1;
    for (int i = n-k+1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int n,k;
    scanf("%i %i", &n, &k);
    printf("%lli\n", A(n,k));
}