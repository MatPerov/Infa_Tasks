#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%i", &n);
    int max = n;
    int num = 1;
    printf("%i ", n);
    while (n != 1) {
        if (n % 2 != 0) {
            n = 3 * n + 1;
            num += 1;
            printf("%i ", n);
            if (max < n)
                max = n;
        }
        if (n % 2 == 0) {
            n = n / 2;
            num += 1;
            printf("%i ", n);
            if (max < n)
                max = n;
        }
    }
    printf("\n");
    printf("Length = %i, ", num);
    printf("Max = %i", max);
}
