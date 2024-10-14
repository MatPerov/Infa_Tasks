#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* get_geometric_progression(float a, float r, int n) {
	float* p = (float*)malloc(sizeof(a * pow(r, n)) * n);
	if (p == NULL)
		printf("Error. Can't allocate memory!\n");
	for (int i = 0; i < n; i++) {
		p[i] = a * pow(r, i);
	}
	return p;
}

int main() {
	float* p = get_geometric_progression(1, 3, 10);
	for (int i = 0; i < 10; i++) {
		printf("%.3f ", p[i]);
	}
}