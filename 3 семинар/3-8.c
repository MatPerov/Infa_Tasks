#include <stdio.h>
#include <math.h>
void reverse(int arr[], int size) {
	for (int i = 0; i < size/2; i++) {
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}
int main() {
	int arr[1000];
	int size;
	scanf("%i", &size);
	for (int i = 0; i < size; i++) {
		scanf("%i", &arr[i]);
	}
	reverse(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%i ", arr[i]);
	}
}