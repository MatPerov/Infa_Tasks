#include <iostream>
// ��� ����� �������� ������� cube
int cube(int& a) {
	a = a * a * a;
	return a;
}
int main()
{
	int a = 5;
	cube(a);
	std::cout << a << std::endl;  // ������ ���������� 125
}