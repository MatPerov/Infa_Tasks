#include <stdio.h>
#include <stdlib.h>


void print(int* a, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}
void sort(int* a, size_t n, int (*cmp)(int a, int b))
{
    for (size_t j = 0; j < n; ++j)
    {
        size_t index = j;
        for (size_t i = j + 1; i < n; ++i)
        {
            if (cmp(a[i], a[index])==1)
                index = i;
        }

        int temp = a[j];
        a[j] = a[index];
        a[index] = temp;
    }
}
int less(int a, int b) {
    if (a < b)
        return 1;
    else
        return -1;
}
int greater(int a, int b) {
    if (a < b)
        return -1;
    else
        return 1;
}
int last_digit_less(int a, int b) {
    if (a % 10 < b % 10)
        return 1;
    else
        return -1;
}

int main()
{
    int a[] = { 32, 63, 29, 54, 81 };

    sort(a, 5, less);
    print(a, 5); 

    sort(a, 5, greater);
    print(a, 5);

    sort(a, 5, last_digit_less);
    print(a, 5);
}