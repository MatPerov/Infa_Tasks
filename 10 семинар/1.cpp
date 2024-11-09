#include <iostream>
namespace mipt
{
	namespace fefm
	{
		struct Point
		{
			int x, y;
		};
	}

	namespace frtk
	{
		void print(fefm::Point p)
		{
			std::cout << p.x << " " << p.y << std::endl;
		}
	}
}
using namespace mipt;
/* использу€ using
using mipt::fefm::Point;
using mipt::frtk::print;
*/
int main() {
	/*
	Ѕез using namespace
	mipt::fefm::Point p = {10,20};
	mipt::frtk::print(p);
	»спользу€ using
	Point p = { 10,20 };
	print(p);
	*/
	fefm::Point p = { 10,20 };
	frtk::print(p);
	return 0;
}