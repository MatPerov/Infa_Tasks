#include <iostream>
#include <string>
using namespace std;

int func(string str) {
	int i = 1;
	int sum = 0;
	string temp = "";
	while (str[i] != ']') {
		while (str[i] != ',' && str[i] != ']') {
			temp += str[i];
			i += 1;
		}
		if (str[i] != ']')
			i += 2;
		sum += std::stoi(temp);
		temp = "";
	}
	return sum;
}
int main() {
	string str;
	getline(std::cin, str);
	try {
		cout << func(str);
	} 
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
    }
	return 0;
}