#include <stdio.h>
#include <limits.h>
int main()
{
    int a, b;
    int max_n;
    scanf("%i %i", &a, &b);
    int max_num = INT_MIN;
    for (int i = a; i <= b; i++) {
        int n = i;
        int num = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                n = 3 * n + 1;
                num += 1;
            }
            if (n % 2 == 0) {
                n = n / 2;
                num += 1;
            }
        }
        if (num > max_num) {
            max_num = num;
            max_n = i;
        }
    }
    printf("%i %i", max_n, max_num);
}