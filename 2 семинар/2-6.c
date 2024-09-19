#include <stdio.h>
int main()
{
    int a[1000];
    int n;
    int ch[1000];//чётные.
    int nch[1000];//нечётные.
    int num_ch = 0, num_nch = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
        if (a[i] % 2 == 0) {
            ch[num_ch]=a[i];
            num_ch += 1;
        }
        else {
            nch[num_nch] = a[i];
            num_nch += 1;
        }
    }
    for (int i = 0; i < num_nch; ++i)
        a[i] = nch[i];
    for (int i = num_nch; i < n; ++i)
        a[i] = ch[i-num_nch];
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}