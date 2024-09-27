#include <stdio.h>
#include <ctype.h>
int main() {
	char a;
	scanf("%c", &a);
	//(a)
	if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122))) {
		printf("Letter\n");
	}
	else if ((a >= 48) && (a <= 57)){
		printf("Digit\n");
	}
	else {
		printf("Other\n");
	}
	//(b)
	if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z'))) {
		printf("Letter\n");
	}
	else if ((a >= '0') && (a <= '9')) {
		printf("Digit\n");
	}
	else {
		printf("Other\n");
	}
	//(c)
	if (isalpha(a)>0) {
		printf("Letter\n");
	}
	else if (isdigit(a)>0) {
		printf("Digit\n");
	}
	else {
		printf("Other\n");
	}
}