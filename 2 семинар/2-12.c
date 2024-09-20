#include <stdio.h>

int main() {
	int n;
	int a[100000];
	scanf("%i", &n);
	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int min_sum_index = i;
		int min_sum = 1000000;
		for (int j = i; j < n; j++) {
			int sum = 0;
			int num1 = a[j];
			while (num1 != 0) {
				sum += num1 % 10;
				num1 = num1 / 10;
			}
			if (sum < min_sum) {
				min_sum_index = j;
				min_sum = sum;
			}

		}
		int temp = a[i];
		a[i] = a[min_sum_index];
		a[min_sum_index] = temp;
	}
	for (int i = 0; i < n; i++) {
		printf("%i ", a[i]);
	}
}