#include <iostream>
#include "point.hpp"
using std::cout;
using std::endl;
class Circle
{
private:
	Point center;
	float radius;

public:
	Circle(const Point& c, float r) {
		center = c;
		radius = r;
	}
	Circle() {
		center = { 0,0 };
		radius = 1.0f;
	}
	Circle(const Circle& circle) {
		center = circle.center;
		radius = circle.radius;
	}
	float getRadius() const { return radius; }
	Point getCenter() const { return center; }
	void setRadius(float r) {
		if (r<0)
			this->radius = 0;
		else
			this->radius = r;
	}
	Point setCenter(Point newCenter) {
		this->center.x = newCenter.x;
		this->center.y = newCenter.y;
	}

	float area() const {
		return 3.14 * radius * radius;
	}

	float distance(const Point& p) const {
		return p.distance(center) - radius;
	}

	bool isColliding(const Circle& c) const {
		if (c.center.distance(center) <= c.radius + radius)
			return true;
		else
			return false;
	}

	void move(const Point& p) {
		center.x += p.x;
		center.y += p.y;
	}
};

int main()
{
	Point p = { 7, -1 };
	Point q = { -4, 2 };
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;
	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl;
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
}