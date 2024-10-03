#include <stdio.h>
void mult2(int* p, size_t n) {
	for (int i = 0; i < n; i++) {
		*(p + i) *= 2;
	}
}
int main() {
	int a[5] = { 10,20,30,40,50 };
	size_t n = 5;
	int* p = &a[0];
	mult2(p, n);
	for (int i = 0; i < n; i++)
		printf("%i ", a[i]);
}