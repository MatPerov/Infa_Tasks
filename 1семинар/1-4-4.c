#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%i", &n);
    int max = INT_MIN;
    int num = 0;
    int num_eq = 1;
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%i", &a);
        if (a == max)
            num_eq += 1;
        if (a > max) {
            max = a;
            num += 1;
        }
    }
    if (num == n)
        printf("Increasing");
    if (num == 1 && num_eq != n)
        printf("Decreasing");
    if (num_eq == n)
        printf("Equal");
    if (num != 1 && num != n && num_eq != n)
        printf("None");
}
