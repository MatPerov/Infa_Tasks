#include <stdio.h>
#include <math.h>
int count_even(int arr[],int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0)
			num += 1;
	}
	return num;
}
int main() {
	int arr[1000];
	int size;
	scanf("%i", &size);
	for (int i = 0; i < size; i++) {
		scanf("%i", &arr[i]);
	}
	printf("%i", count_even(arr, size));
}