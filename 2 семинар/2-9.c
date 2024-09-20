#include <stdio.h>

int main(){
	int n,m;
	int a[1000];
	scanf("%i %i", &n, &m);
	
	for (int i = 0; i < n*m; i++) {
			scanf("%i", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i + j * m];
		}
		printf("%i ", sum);
	}
	}