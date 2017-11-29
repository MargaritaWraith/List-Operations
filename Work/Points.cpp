#include "stdafx.h"
#include <iostream>
#include "Points.h"
#include <math.h>

using namespace std;


Point2& Point2::operator= (const Point2& pnt)
{
	cout << this << " operator =" << endl;
	x = pnt.x;
	y = pnt.y;
	return *this;
}
Point2 Point2::operator+(const Point2& pnt)
{
	Point2 res;
	res.x = x + pnt.x;
	res.y = y + pnt.y;
	return res;
}
Point2 Point2::operator-(const Point2& pnt)
{
	Point2 res;
	res.x = x - pnt.x;
	res.y = y - pnt.y;
	return res;
}
void Point2::Print()
{
	cout << "x=" << x;
	cout << " y=" << y << endl << endl;
}
double Point2::VectorPnt()
{
	double res;
	res = sqrt(x*x + y*y);
	return res;
}
double Point2::VectorLenghtTo(const Point2& pnt)
{
	double res;
	Point2 p;
	p = *this - pnt;
	res = p.VectorPnt();
	return res;
}

/* ---------------------------------------------------------------------------- */

Point3::~Point3()
{
	cout << this << " Point3.destructor" << endl;
}
Point3& Point3::operator = (const Point3& pnt)
{
	x = pnt.x;
	y = pnt.y;
	z = pnt.z;
	return *this;
}
Point3 Point3::operator + (const Point3& pnt)
{
	Point3 res;
	res.x = x + pnt.x;
	res.y = y + pnt.y;
	res.z = z + pnt.z;
	return res;
}
Point3 Point3::operator - (const Point3& pnt)
{
	Point3 res;
	res.x = x - pnt.x;
	res.y = y - pnt.y;
	res.z = z - pnt.z;
	return res;
}
void Point3::Print()
{
	cout << "x = " << x;
	cout << " y = " << y;
	cout << " z = " << z << endl << endl;
}
double Point3::VectorPnt()
{
	double res;
	res = sqrt(x*x + y*y + z*z);
	return res;
}
double Point3::VectorLenghtTo(const Point3& pnt)
{
	double res;
	Point3 p;
	p = *this - pnt;
	res = p.VectorPnt();
	return res;
}



/* ---------------------------------------------------------------------------- */
void PrintPoint(Point2& pnt)
{
	pnt.Print();
}

/* ---------------------------------------------------------------------------- */


void CheckPoint()
{
	Point2 p1;
	p1.Print();

	Point2 p2(3, 4);
	p2.Print();
	double vp = p2.VectorPnt();

	p1 = p2;

	Point2 p3;
	p3 = p1 + p2 + p2;
	PrintPoint(p3);
	double vp2 = p3.VectorLenghtTo(p2);





	Point3 pp1(10, 20, 30);
	Point3 pp2(pp1);
	PrintPoint(pp2);

	Point3 pp3 = pp1 + pp2 + pp2;
	pp3.Print();
	double vpp = pp2.VectorPnt();
	double vpp2 = pp3.VectorLenghtTo(pp2);

	cout << vp << "   " << vp2 << endl;
	cout << vpp << "   " << vpp2 << endl;




}