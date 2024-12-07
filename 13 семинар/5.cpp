#include <iostream>
#include <cmath>

template<typename T>
void swapEndianness(T& a) {
	T b = a;
	int size = -1;
	int temp1 = a % 16;
	while (b != 0) {
		b /= 16;
		size += 1;
	}
	int temp = size;
	while (a != 0) {
		b += (a % 16) * pow(16, size);
		size -= 1;
		a /= 16;
	}
	a = b;
}
int main()
{
	std::cout << std::hex;

	int a = 0x1a2b3c4d;
	std::cout << a << std::endl;  // Äîëæåí íàïå÷àòàòü 1a2b3c4d
	swapEndianness(a);
	std::cout << a << std::endl;  // Äîëæåí íàïå÷àòàòü 4d3c2b1a
	swapEndianness(a);
	std::cout << a << std::endl;  // Äîëæåí íàïå÷àòàòü 1a2b3c4d

	short b = 0x1a2b;
	std::cout << b << std::endl;  // Äîëæåí íàïå÷àòàòü 1a2b
	swapEndianness(b);
	std::cout << b << std::endl;  // Äîëæåí íàïå÷àòàòü 2b1a
}
