#include <stdio.h>
#include <math.h>
int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
	double D = b * b - 4 * a * c;
	if (fabs(D) < 1e-10) {
		*px1 = (-1) * b / (2 * a);
		return 1;
	}
	else if (D > 1e-10) {
		*px1 = ((-1) * b + sqrt(D)) / (2 * a);
		*px2 = ((-1) * b - sqrt(D)) / (2 * a);
		return 2;
	}
	else if (D < -1e-10) {
		return 0;
	}
}
int main() {
	double a,b,c,x1,x2;
	double* px1 = &x1;
	double* px2 = &x2;
	scanf("%lf %lf %lf", &a, &b, &c);
	solve_quadratic(a, b, c, px1, px2);
	printf("%i %lf %lf", solve_quadratic(a,b,c,px1,px2), x1, x2);
}