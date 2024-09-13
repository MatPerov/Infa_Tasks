#include <stdio.h>

int main(){
	int n;
	scanf("%i", &n);
	for (int i = 1; i <= n; i++) {
		printf("%3i", i);
		printf(" -> ");
		printf("%3i", i * i);
		printf(" -> ");
		printf("%3i", i * i * i);
		printf("\n");
	}
}