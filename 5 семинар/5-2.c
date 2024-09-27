#include <stdio.h>
#include <ctype.h>
int main() {
	char str1[200],str2[200];
	scanf("%s", str1);
	scanf("%s", str2);
	int i = 0;
	int len1 = 0, len2 = 0;
	while (str1[i] != 0) {
		len1 += 1;
		i += 1;
	}
	i = 0;
	while (str2[i] != 0) {
		len2 += 1;
		i += 1;
	}
	if (len1 < len2) {
		for (int i = 0; i < len1; i++) {
			printf("%c%c", str1[i], str2[i]);
		}
		for (int i = len1; i < len2; i++) {
			printf("%c", str2[i]);
		}
	}
	if (len2 < len1) {
		for (int i = 0; i < len2; i++) {
			printf("%c%c", str1[i], str2[i]);
		}
		for (int i = len2; i < len1; i++) {
			printf("%c", str1[i]);
		}
	}
	if (len1 == len2) {
		for (int i = 0; i < len1; i++) {
			printf("%c%c", str1[i], str2[i]);
		}
	}
}