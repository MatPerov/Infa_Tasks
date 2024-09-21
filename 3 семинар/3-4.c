#include <stdio.h>
#include <math.h>
void sum_of_digits(int num) {
	int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}
	printf("%i",sum);
}
int main() {
	int num;
	scanf("%i", &num);
	sum_of_digits(num);
}