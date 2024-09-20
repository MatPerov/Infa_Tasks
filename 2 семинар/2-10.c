#include <stdio.h>

int main() {
	int n, m;
	int a[100][100];
	scanf("%i %i", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%i", &a[i][j]);
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int min_index = i;
			for (int k = i; k < n; k++) {
				if (a[k][j] < a[min_index][j]) {
					min_index = k;
				}
			}
			int temp = a[i][j];
			a[i][j] = a[min_index][j];
			a[min_index][j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
}