#include <stdio.h>
#include <math.h>
float pi(int n)
{
    float result = 0;
    for (int i = 1; i <= n; i++) {
        result += pow(-1, i + 1) / (2 * i - 1);
    }
    return result * 4;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%.5f\n", pi(n));
}