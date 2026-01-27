#include <iostream>

class Point
{
public:
    Point(int x = 0, int y = 0) : x(x), y(y)
    {

    }
    /*friend Point operator+(const Point& p1, const Point& p2)
    {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }*/

    /*Point operator+(const Point& other)
    {
        return Point(x + other.x, y + other.y);
    }*/

    friend Point operator+(const Point& left, const Point& right)
    {
        return Point(left.x + right.x, left.y + right.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        return os << "(" << p.x << "," << p.y << ")";
    }

public:
    int x = 0;
    int y = 0;

};

int main()
{
    Point p1(1,1);
    Point p2(5,5);

    Point p3 = p1 + p2;

    std::cout << p3;

    std::cin.get();
}