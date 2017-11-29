#ifndef _VIRT_FUNC
#define	_VIRT_FUNC
using namespace std;

class Point2
{
public:
	double x;
	double y;
	Point2() : x(0), y(0) { cout << this << " Point2.def.constr" << endl; };
	Point2(double x1, double y1) :x(x1), y(y1) { cout << this << " Point2.param.constr" << endl; };
	Point2(const Point2& pnt) : x(pnt.x), y(pnt.y) { cout << this << " Point2.copy.constr" << endl; };
	~Point2() {};
	Point2& operator = (const Point2& pnt);
	Point2 operator+(const Point2& pnt);
	virtual void Print();
private:

};

class Point3: public Point2
{
public:
	double z;
	Point3() :Point2(), z(0) { cout << this << " Point3.def.constr" << endl; };
	Point3(double x1, double y1, double z1) :Point2(x1, y1), z(z1) { cout << this << " Point3.param.constr" << endl; };
	Point3(const Point3& pnt) :Point2(pnt), z(pnt.z) { cout << this << " Point3.copy.constr" << endl; };
	~Point3();
	Point3& operator = (const Point3& pnt);
	Point3 operator + (const Point3& pnt);	void Print();

private:

};

void CheckPoint();

											 




#endif