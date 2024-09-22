#include <stdio.h>
#include <math.h>
void transpose(int A[][100], int n) {
	int TA[100][100];
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++)
			TA[j][i] = A[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			A[i][j] = TA[i][j];
	}
}
void print(int A[][100], int n) {
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%i ", A[i][j]);
	}
}
int main() {
	int n;
	scanf("%i", &n);
	int A[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%i", &A[i][j]);
	transpose(A, n);
	print(A, n);
}