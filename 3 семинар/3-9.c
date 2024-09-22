#include <stdio.h>
#include <math.h>
void bob(int);
void alice(int num) {
	num = num * 3 + 1;
	printf("Alice: %i\n", num);
	bob(num);
}
void bob(int num) {
	while (num % 2 != 1) {
		num = num / 2;
		printf("Bob: %4i\n", num);
	}
	if (num != 1) {
		alice(num);
	}
}
int main() {
	int num;
	scanf("%i", &num);
	alice(num);
}