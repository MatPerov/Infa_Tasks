#include <iostream>
#include <vector>

template<typename T>
std::pair<T, T> minmax(const std::vector<T>& v) {
	int n = v.size();
	T max = v[0];
	T min = v[0];
	for (int i = 0; i < n; i++) {
		if (v[i] < min)
			min = v[i];
		if (v[i] > max)
			max = v[i];
	}
	std::pair<T, T> result = std::make_pair(min, max);
	return result;
}
int main()
{
	std::vector<int> a{ 60, 10, 40, 80, 30 };
	auto am = minmax(a);
	std::cout << am.first << " " << am.second << std::endl;  // 10 80

	std::vector<std::string> b{ "Cat", "Dog", "Mouse", "Camel", "Wolf" };
	auto bm = minmax(b);
	std::cout << bm.first << " " << bm.second << std::endl;  // Camel Wolf

	std::vector<std::pair<int, int>> c{ {10, 90}, {30, 10}, {20, 40}, {10, 50} };
	auto cm = minmax(c);
	std::cout << cm.first.first << " " << cm.first.second << std::endl;    // 10 50
	std::cout << cm.second.first << " " << cm.second.second << std::endl;  // 30 10
}