#include <stdio.h>
#include <math.h>
int trib(int n,int trib_arr[]) {
	if (n >= 3) {
		for (int i = 3; i <= n; i++)
			trib_arr[i] = trib_arr[i - 3] + trib_arr[i - 2] + trib_arr[i - 1];
		return trib_arr[n];
	}
	else if (n == 2)
		return trib_arr[2];
	else if (n == 1)
		return trib_arr[1];
	else if (n == 0)
		return trib_arr[0];
}
int main() {
	int num;
	scanf("%i", &num);
	int trib_arr[1000];
	trib_arr[0] = 0;
	trib_arr[1] = 0;
	trib_arr[2] = 1;
	printf("%i", trib(num, trib_arr));
}