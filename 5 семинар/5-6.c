#include <stdio.h>
#include <ctype.h>
int main() {
	char str1[200];
	int n, num;
	int x = 0, y = 0;
	scanf("%i", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str1);
		scanf("%i", &num);
		if (strcmp(str1,"North") == 0) {
			y += num;
		}
		if (strcmp(str1, "South") == 0) {
			y -= num;
		}
		if (strcmp(str1, "East") == 0) {
			x += num;
		}
		if (strcmp(str1, "West") == 0) {
			x -= num;
		}
	}
	printf("%i %i", x, y);
}