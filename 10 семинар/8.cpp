#include <iostream>
#include <string>

void addBrackets(std::string& str) {
	str = '[' + str + ']';
}
int main()
{
	std::string a = "Cat";
	addBrackets(a);
	std::cout << a << std::endl;  // ������ ���������� [Cat]

	addBrackets(a);
	std::cout << a << std::endl;  // ������ ���������� [[Cat]]
}