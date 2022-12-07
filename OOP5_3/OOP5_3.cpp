#include <iostream>


using namespace std;

class Point
{

public:
	Point()
	{
		cout << "Point()" << endl;
	}
	Point(Point* p)
	{
		cout << "Point(Point* p)" << endl;
	}
	Point(const Point& p)
	{
		cout << "Point(Point& p)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
};
class ColoredPoint : public Point
{
public:
	ColoredPoint()
	{
		cout << "ColoredPoint()" << endl;
		
	}
	ColoredPoint(ColoredPoint *p)
	{
		cout << "ColoredPoint(ColoredPoint *p)" << endl;
		
	}
	ColoredPoint(ColoredPoint& p)
	{
		cout << "ColoredPoint(ColoredPoint& p)" << endl;
	
	}
	~ColoredPoint()
	{
		cout << "~ColoredPoint()" << endl;
	}
};

void func1(Point p)
{
	cout << "func1 (Point p)" << endl;
}
void func2(Point* p)
{
	cout << "func2 (Point *p)" << endl;
}
void func3(Point& p)
{
	cout << "func3 (Point &p)" << endl;
}



int main()
{
	cout << "Point p" << endl;
	Point p;
	func1(p);
	func2(&p);
	func3(p);
	cout << endl << "Point p1(&p)" << endl;
	Point p1(&p);
	func1(p1);
	func2(&p1);
	func3(p1);
	cout << endl << "Point p2(p)" << endl;
	Point p2(p);
	func1(p2);
	func2(&p2);
	func3(p2);
	cout << endl << "ColoredPoint clp" << endl;
	ColoredPoint clp;
	func1(clp);
	func2(&clp);
	func3(clp);
	cout << endl << "ColoredPoint clp1(&clp)" << endl;
	ColoredPoint clp1(&clp);
	func1(clp1);
	func2(&clp1);
	func3(clp1);
	cout << endl << "ColoredPoint clp2(clp)" << endl;
	ColoredPoint clp2(clp);
	func1(clp2);
	func2(&clp2);
	func3(clp2);
	cout << endl;
    return 0;
}

