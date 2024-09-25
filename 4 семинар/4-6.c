#include <stdio.h>
#include <math.h>
double gamma(double x)
{
    double step = pow(10, -2);
    double t = step;
    double result = 0;
    double space = 0;
    while (space < pow(10, -10)) {
        result += space;
        t += step;
        space = 0.5 * (pow(t, x - 1) * exp(-t) + pow(t - step, x - 1) * exp(-(t - step))) * step;
    }
    while (space > pow(10, -10)) {
        result += space;
        t += step;
        space = 0.5 * (pow(t, x - 1) * exp(-t) + pow(t - step, x - 1) * exp(-(t - step))) * step;
    }
    return result;
}

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%lf", gamma(x));
}