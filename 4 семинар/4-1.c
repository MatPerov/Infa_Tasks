#include <stdio.h>
unsigned long long fact(int n)
{
    unsigned long long result = 1;  /* ��� ������ int ����� �������� �������� �������� �� -2 �� 2 ����������,
    � �� �� ����� ��������� 13 ��� ������ 6 ����������, ������� ��������� �������� �����������.*/
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int k;
    scanf("%i", &k);
    printf("%lli\n", fact(k));
}