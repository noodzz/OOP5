
#include <iostream>

using namespace std;

class Point
{
protected:
	float x, y;
public:
	Point()
	{
		cout << "Point()" << endl;
		x = 0;
		y = 0;
	}
	Point(float _x, float _y)
	{
		cout << "Point(float _x, float _y)" << endl;
		x = _x;
		y = _y;
	}
	Point(const Point& p)
	{
		cout << "Point(const Point& p)" << endl;
		x = p.x;
		y = p.y;
	}
	virtual ~Point()
	{
		cout << "~Point()" << endl;
	}
	void setPoint(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	void getPoint()
	{
		cout << "x = " << x << " y = " << y << endl;
	}

};


Point func1()
{
	cout << "func1" << endl;
	Point* p = new Point();
	return *p;
}
Point* func2()
{
	cout << "func2" << endl;
	Point* p = new Point();
	return p;
}
Point& func3()
{
	cout << "func3" << endl;
	Point* p = new Point();
	return *p;
}
int main()
{
	Point p = func1();
	cout << endl;
	Point *p1 = func2();
	cout << endl;
	Point &p2 = func3();
	cout << endl; 
    return 0;
}

