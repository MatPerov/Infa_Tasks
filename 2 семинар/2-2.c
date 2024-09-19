#include <stdio.h>
int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    int num, place;
    scanf("%i %i", &num, &place);
    for (int i = n; i > place; i--) {
        a[i] = a[i - 1];
    }
    a[place + 1] = num;
    for (int i = 0; i < n+1; ++i)
        printf("%i ", a[i]);

    printf("\n");
}
