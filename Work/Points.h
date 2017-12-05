#ifndef _POINTS
#define	_POINTS
using namespace std;

class BasePoint
{
public:
	virtual void Print()=0;
	virtual char* ToString()=0;
	friend ostream& operator << (ostream& os, BasePoint& pnt);

};

class Point2 : public BasePoint
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
	Point2 operator-(const Point2& pnt);
	virtual void Print();
	virtual double VectorPnt();
	virtual double VectorLenghtTo(const Point2& pnt);
	char* ToString();

private:

};

class Point3 : public Point2
{
public:
	double z;
	Point3() :Point2(), z(0) { cout << this << " Point3.def.constr" << endl; };
	Point3(double x1, double y1, double z1) :Point2(x1, y1), z(z1) { cout << this << " Point3.param.constr" << endl; };
	Point3(const Point3& pnt) :Point2(pnt), z(pnt.z) { cout << this << " Point3.copy.constr" << endl; };
	~Point3();
	Point3& operator = (const Point3& pnt);
	Point3 operator + (const Point3& pnt);
	Point3 operator - (const Point3& pnt);
	void Print();
	double VectorPnt();
	double VectorLenghtTo(const Point3& pnt);
	char* ToString();

private:

};

void CheckPoint();






#endif