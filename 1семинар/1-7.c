#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, sum = 0;
    scanf("%i %i", &n,&m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += pow(-1, i + j) * i * j;
        }
    }
    printf("%i", sum);
}
