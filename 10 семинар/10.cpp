#include <iostream>
#include <string>
bool isDomainName(std::string str) {
	int i = 0;
	int n = 0;
	while (str[i] != '\0') {
		n += 1;
		i += 1;
	}
	std::string str1 = "";
	if (n < 4)
		return false;
	for (int i = 0; i < 4; i++) {
		str1 += str[i];
	}
	std::string str2 = "";
	for (int i = 4; i > 0; i--) {
		str2 += str[n-i];
	}
	if ((str1 == "www.") && (str2 == ".com"))
		return true;
	else
		return false;
}

int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;         // Напечатает 1
	std::cout << isDomainName("abc") << std::endl;                    // Напечатает 0
	std::cout << isDomainName("hello.com") << std::endl;              // Напечатает 0
}