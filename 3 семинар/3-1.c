#include <stdio.h>
#include <math.h>
int cube(int num) {
	return pow(num, 3);
}
int main() {
	printf("%i", cube(5));
}