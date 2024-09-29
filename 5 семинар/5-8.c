#include <stdio.h>
#include <ctype.h>

void repeater(const char word[], int num) {
	for (int i = 0; i < num; i++)
		printf("%s ", word);
}
int main() {
	int num;
	char str[200];
	scanf("%s", str);
	scanf("%i", &num);
	repeater(str, num);
}