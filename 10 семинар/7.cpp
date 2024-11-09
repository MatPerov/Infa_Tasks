#include <iostream>
#include <cctype>
void countLetters(const std::string& str, int& numLetters, int& numDigits) {
	int i = 0;
	int n = 0;
	while (str[i] != '\0') {
		n += 1;
		i += 1;
	}
	for (int i = 0; i<n;i++) {
		if (isdigit(str[i]) > 0)
			numDigits += 1;
		if (isalpha(str[i]) > 0)
			numLetters += 1;
	}
}
int main() {
	std::string str = "Hello123";
	int numLetters = 0;
	int numDigits = 0;
	countLetters(str, numLetters, numDigits);
	std::cout << numLetters << ' ' << numDigits << std::endl;
}