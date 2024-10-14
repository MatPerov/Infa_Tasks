#include <stdio.h>
#include <math.h>
int count_if(int a[], int n, int (*pr)(int a)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pr(a[i]) == 1)
            count += 1;
    }
    return count;
}
int is_negative(int a) {
    if (a < 0)
        return 1;
    else
        return -1;
}
int is_even(int a) {
    if (a % 2 == 0)
        return 1;
    else
        return -1;
}
int is_square(int a) {
    if ((int)(sqrt(a) * 10) % 10 == 0)
        return 1;
    else
        return -1;
}

int main()
{
    int a[] = { 89, 81, 28, 52, 44, 16, -64, 49, 52, -79 };

    printf("%zu\n", count_if(a, 10, is_negative));  
    printf("%zu\n", count_if(a, 10, is_even));      
    printf("%zu\n", count_if(a, 10, is_square));    
}
