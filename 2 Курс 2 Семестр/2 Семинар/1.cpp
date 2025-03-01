#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
/*
    ��������������� ��������� Vector2f, ������� ��������� �������������� ������ � ��������� ������������.
    ����� �������� ������� ��� ������� ������ � ���� ����������.
    �������� �������� �����, ��� � ����� sf::Vector2f �� ���������� SFML.
    (�� ���������� ����� ���������� ������ ���� ������ sf::Vector2f �� �����)
*/

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = { left.x + right.x, left.y + right.y };
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = { left.x * right, left.y * right };
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = { left * right.x, left * right.y };
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}




/*
    ������ Circle, Rectangle � Triangle, ����������� ����, ������������� � ����������� ��������������.
*/

class Shape
{
protected:
    Vector2f mPosition;
public:

    Vector2f getPosition()
    {
        return mPosition;
    }

    void setPosition(Vector2f newPosition)
    {
        mPosition = newPosition;
    }

    void move(Vector2f change) {
        mPosition = mPosition + change;
    }
};

class Circle : public Shape
{
private:
    float mRadius;
    Vector2f mPosition;
public:

    Circle(float radius) : mRadius(radius), mPosition({ 0, 0 })
    {
    }

    float calculatePerimeter()
    {
        return 2 * 3.1416 * mRadius;
    }
};



class Rectangle : public Shape
{
private:

    Vector2f mPosition;
    float mWidth;
    float mHeight;

public:

    Rectangle(float width, float height) : mWidth(width), mHeight(height), mPosition({ 0, 0 })
    {
    }

    float calculatePerimeter()
    {
        return 2 * (mWidth + mHeight);
    }
};




class Triangle : public Shape
{
private:

    Vector2f mPosition;

    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:

    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) :
        mPosition({ 0, 0 }), mPointA(pointA), mPointB(pointB), mPointC(pointC)
    {
    }

    float calculatePerimeter()
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};


int main()
{
    Circle a(10);
    cout << a.calculatePerimeter() << endl;

    Rectangle b(100, 200);
    cout << b.calculatePerimeter() << endl;

    Triangle c({ 5, 2 }, { -7, 5 }, { 4, 4 });
    cout << c.calculatePerimeter() << endl;

    a.move({ 10,10 });
    cout << a.getPosition() << endl;
    b.move({ 15,15 });
    cout << b.getPosition() << endl;
    c.move({ 5,5 });
    cout << c.getPosition() << endl;
}