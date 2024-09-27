#include <stdio.h>
#include <ctype.h>
void is_palindrom(char str[]) {
	int i = 0, len = 0;
	while (str[i] != 0) {
		len += 1;
		i += 1;
	}
	int num = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == str[len - i - 1]) {
			num += 1;
		}
	}
	if (num == len) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
int main() {
	char str[200];
	scanf("%s", str);
	is_palindrom(str);
}