#include <iostream>
#include <cmath>

template<typename T, int a>
class Modular {
public:
	T mod;
	Modular(int num) {
		mod = num % a;
	}
	Modular(const Modular& num) {
		mod = num.mod;
	}
void operator=(Modular num2) {
	this->mod = num2.mod;
	}
Modular operator+(Modular num2) {
	Modular result = { (this->mod + num2.mod)%a};
	return result;
}
Modular operator-(Modular num2) {
	Modular result = { (this->mod - num2.mod)%a };
	return result;
}
Modular operator*(Modular num2) {
	Modular result = { (this->mod * num2.mod) % a };
	return result;
}
Modular operator+(int num2) {
	Modular result = { (this->mod + num2) % a };
	return result;
}
Modular operator-(int num2) {
	Modular result = { (this->mod - num2) % a };
	return result;
}
Modular operator*(int num2) {
	Modular result = { (this->mod * num2) % a };
	return result;
}
void operator-() {
	Modular result = { this->mod=-this->mod };
}
std::ostream& operator<<(std::ostream& out)
{
	return out << this->mod;
}
};
int main()
{
	Modular<int, 7> a(10);
	std::cout << a << std::endl; // Íàïå÷àòàåò 3
	a = (a + 8) * 4;
	std::cout << a << std::endl; // Íàïå÷àòàåò 2

	Modular<int, 7> b(a);
	b = b + 2;
	a = a - b;
	std::cout << a << std::endl; // Íàïå÷àòàåò 5

	Modular<short, 3> ñ(a);
	std::cout << c << std::endl; // Íàïå÷àòàåò 2
}
