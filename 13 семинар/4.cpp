#include <iostream>
#include <vector>
#include <array>

template<typename T, typename S>
bool hasMoreElements(const T& v1, const S& v2) {
	if (v1.size() > v2.size())
		return true;
	else
		return false;
}
int main()
{
	std::vector<int> a{ 10, 20, 30, 40, 50 };
	std::string b = "Cat";
	std::string c = "Elephant";
	std::array<int, 3> d{ 10, 20, 30 };

	std::cout << hasMoreElements(a, b) << std::endl;  // Должно напечатать 1
	std::cout << hasMoreElements(a, c) << std::endl;  // Должно напечатать 0
	std::cout << hasMoreElements(a, d) << std::endl;  // Должно напечатать 1
}