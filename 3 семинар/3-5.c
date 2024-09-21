#include <stdio.h>
#include <math.h>
void print_binary(int num) {
	if (num / 2 > 1) {
		print_binary(num / 2);
		printf("%i", num % 2);
	}
	else {
		if (num % 2 != 0)
			printf("%i%i", num % 2, num / 2);
		else if (num != 0)
			printf("%i%i", num / 2, num % 2);
		if (num == 0)
			printf("0");
	}
}
int main() {
	int num;
	scanf("%i", &num);
	print_binary(num);
}