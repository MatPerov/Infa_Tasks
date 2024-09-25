#include <stdio.h>
#include <math.h>
float distance(int x1, int y1, int x2, int y2)
{
    float result;
    result = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return result;
}

int main()
{
    int x1,y1,r1,x2,y2,r2;
    scanf("%i %i %i", &x1, &y1, &r1);
    scanf("%i %i %i", &x2, &y2, &r2);
    float a = distance(x1, y1, x2, y2);
    if (fabs(a - r1 - r2) < pow(10, -5))
        printf("Touch");
    if (a > r1 + r2 + pow(10, -5))
        printf("Do not intersect");
    if (a < r1 + r2)
        printf("Intersect");
}