#include <stdio.h>
int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    int num1,num2;
    scanf("%i %i", &num1, &num2);
    for (int i = num1; i < n-(num2-num1); i++) {
        a[i] = a[i + (num2-num1)];
    }
    for (int i = 0; i < n-(num2-num1); ++i)
        printf("%i ", a[i]);

    printf("\n");
}