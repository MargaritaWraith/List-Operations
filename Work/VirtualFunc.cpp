#include "stdafx.h"
#include <iostream>
#include "VirtualFunc.h"

using namespace std;


//Point2::Point2()
//{
//	cout << this << " Point2.def.constr" << endl;
//	x = 0;
//	y = 0;
//}
//
//Point2::Point2(double x, double y)
//{
//	cout << this << " Point2.param.constr" << endl;
//	this->x = x;
//	this->y = y;
//}
//
//Point2::Point2(const Point2& pnt)
//{
//	cout << this << " Point2.copy.constr" << endl;
//	x = pnt.x;
//	y = pnt.y;
//}
//Point2::~Point2()
//{
//	cout << this << " Point2.destructor" << endl;
//}

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

void Point2::Print()
{
	cout << "x=" << x ;
	cout << " y=" << y << endl;
}

//Point3::Point3() :Point2()
//{
//	cout << this << " Point3.def.constr" << endl;
//	z = 0;
//}
//
//Point3::Point3(double x, double y, double z) :Point2(x, y)
//{
//	cout << this << " Point3.param.constr" << endl;
//	this->z = z;
//}
//
//Point3::Point3(const Point3& pnt)
//{
//	cout << this << " Point3.copy.constr" << endl;
//	z = pnt.z;
//}

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

void PrintPoint(Point2& pnt)
{
	pnt.Print();
}

void Point3::Print()
{
	cout << "x = " << x ;
	cout << " y = " << y ;
	cout << " z = " << z << endl;
}

void CheckPoint()
{
	Point2 p1;
	p1.Print();

	Point2 p2(1, 2);
    p2.Print();
	
	p1 = p2;
	p1.Print();
	
	Point2 p3;
	p3 = p1 + p2;
	PrintPoint(p3);

	Point3 pp1(10, 20, 30);
	Point3 pp2(pp1);
	PrintPoint(pp2);

	Point3 pp3 = pp1 + pp2;
	pp3.Print();	
	
	

}