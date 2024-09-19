#include <stdio.h>

int main(){
	int a;
	scanf("%i",&a);
	if ((a % 2 == 0) && ((a >= 0 && a<=20)||(a<200 && a>100))){
		printf("Yes");
	}
	else {
		printf("No");
	}
}
