#include <iostream>
#include <memory>

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
	void reset()
	{
		cout << "Point()::reset()" << endl;
		x = 0;
		y = 0;
	}
	virtual void print()
	{
		cout << "This is Point" << endl;
	}
	void GetAndReset()
	{
		cout << "x = " << x << " " << "y = " << y << " ";
		reset();
	}
	void GetInfo()
	{
		print();
	}
};
class ColoredPoint : public Point
{
private:
	string color;
public:
	ColoredPoint() : Point()
	{
		cout << "ColoredPoint()" << endl;
		color = "default";
	}
	ColoredPoint(float _x, float _y, string _color) : Point(_x, _y)
	{
		cout << "ColoredPoint(float _x, float _y, string _color)" << endl;
		color = _color;
	}
	ColoredPoint(const ColoredPoint& p) : Point(p)
	{
		color = p.color;
	}
	~ColoredPoint() 
	{
		cout << "~ColoredPoint()" << endl;
	}
	void reset()
	{
		cout << "ColoredPoint::reset()" << endl;
		x = 0;
		y = 0;
		color = "default";
	}
	void print() override
	{
		cout << "This is ColoredPoint" << endl;
	}
};


int main()
{
	Point* p1 = new ColoredPoint();
	ColoredPoint* p2 = new ColoredPoint();
	cout << endl;
	//невиртуальный метод
	p1->reset(); 
	p2->reset();
	cout << endl;
	//виртуальный метод
	p1->print();
	p2->print();
	cout << endl;
	p2->GetAndReset(); 
	p2->GetInfo(); 
	cout << endl;

	delete p1;
	delete p2;

	cout << endl;
	//unique_ptr и shared_ptr
	auto p3 = make_unique<ColoredPoint>(5, 5, "black");
	p3->print();
	{	unique_ptr<Point> p4(new ColoredPoint(1, 2, "black"));
		p4->print();
	}

	auto p5 = make_shared<ColoredPoint>();
	//p5->GetInfo();
	{
		shared_ptr<Point> p6 = p5;
		p6->GetInfo();
	}
	p5->GetInfo();
	return 0;
} 

