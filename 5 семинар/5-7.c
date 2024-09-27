#include <stdio.h>
#include <ctype.h>
void safe_strcpy(char a[], size_t size, const char b[]) {
	for (int i = 0; i < size-1; i++) {
		a[i] = b[i];
		printf("%s\n", a);
	}
	int len = 0, i = 0;
	while (b[i] != 0) {
		len += 1;
		i += 1;
	}
	if (len > size)
		a[size - 1] = '\0';

}
int main() {
	char a[10] = "Mouse";
	char b[50] = "LargeElephant";
	safe_strcpy(a, 10, b);
	printf("%s", a);
}