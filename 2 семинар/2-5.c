#include <stdio.h>
#include <limits.h>
int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            while (a[i]<0) {
                num += 1;
                int place = i;
                for (int j = place; j < n; j++) {
                    a[j] = a[j + 1];
                }
            }
        }
    }
    for (int i = 0; i < n - num; ++i)
    printf("%i ", a[i]);

    printf("\n");
}
