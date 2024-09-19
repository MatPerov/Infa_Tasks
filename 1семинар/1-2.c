#include <stdio.h>

int main(){
	int a,b,c;
	int k=0;
	scanf("%i",&a);
	scanf("%i", &b);
	scanf("%i", &c);
	if (abs(a - b) == 1 && abs(a - c) == 2) {
		printf("Consecutive ");
		k = 1;
	}
	if (a < b && b < c) {
		printf("Increasing ");
		k = 1;
	}
	if (c < b && b < a) {
		printf("Decreasing ");
		k = 1;
	}
	if (a == b && b == c) {
		printf("Equal ");
		k = 1;
	}
	if (k == 0)
		printf("None");
}
