#include <stdio.h>
#include <ctype.h>
void encrypt(char* str, int k) {
	int i = 0, len = 0;
	while (str[i] != 0) {
		len += 1;
		i += 1;
	}
	for (int i = 0; i < len; i++) {
		if (isupper(str[i]) == 1) {
			if (str[i] + k <= 90)
				str[i] = str[i] + k;
			else
				str[i] = 64 + (str[i] + k) - 90;
		}
		if (islower(str[i]) == 2) {
			if (str[i] + k <= 122)
				str[i] = str[i] + k;
			else
				str[i] = 96 + (str[i] + k) - 122;
		}
	}
}
int main() {
	char str[200];
	int k;
	scanf("%i", &k);
	scanf("%[^\n]", str);
	encrypt(str, k);
	printf("%s", str);
}