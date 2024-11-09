#include <iostream>
#include <string>
using namespace std;
string repeat(int n) {
	string str = "";
	string temp = to_string(n);
	for (int i = 0; i < n; i++) {
		str += temp;
	}
	return str;
}
int main()
{
	std::cout << repeat(5) << std::endl;  // Должно напечатать 55555
	std::cout << repeat(10) << std::endl;  // Должно напечатать 10101010101010101010
	std::cout << repeat(-1) << std::endl;  // Не должно ничего печатать
}