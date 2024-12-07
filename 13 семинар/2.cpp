#include <iostream>

template<typename T>
T triple(const T& x)
{
	//return x+x+x; - 1 способ.
	return 3 * x;
}
std::string operator*(int n, std::string s) {
	std::string temp = "";
	for (int i = 0; i < n; i++) {
		temp += s;
	}
	return temp;
}
std::string triple(std::string str) {
	return str + str + str;
}
int main()
{
	int a = 10;
	std::cout << triple(a) << std::endl;  // Сработает, напечатает 30

	std::string b = "Cat";
	std::cout << triple(b) << std::endl;  // Ошибка, нельзя число 3 умножать на std::string
	// Нужно чтобы напечаталось CatCatCat
}