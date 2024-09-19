#include <stdio.h>
int main()
{
    int a[1000];
    int n;
    int num;
    scanf("%i", &n);
    num = n;
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    for (int i = 0; i < 2*n; i+=2) {
        int ch = a[i];
        for (int j = num; j > i; j--) {
            a[j] = a[j - 1];
        }
        num += 1;
        a[i + 1] = ch;
    }
    for (int i = 0; i < num; ++i)
        printf("%i ", a[i]);
    printf("\n");
}