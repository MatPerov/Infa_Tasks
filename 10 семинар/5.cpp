#include <iostream>
struct Book
{
	std::string title;
	int pages;
	float price;
};
bool isExpensive(const Book& r) {
	if (r.price > 1000)
		return true;
	else
		return false;
}
int main()
{
	Book book1 = { "book1",256,1458.1 };
	Book book2 = { "book2",228,800.1 };
	if (isExpensive(book1))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	if (isExpensive(book2))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
}