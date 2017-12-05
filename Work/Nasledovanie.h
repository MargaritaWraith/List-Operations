#ifndef _NASLED
#define	_NASLED
using namespace std;

class A
{
	double x;
	void PrA() { cout << x << endl; }
protected:
	double y;
	void PrtA() { cout << x << ' ' << y << endl; }
public:
	double z;
	void PbA() { cout << x << ' ' << y << ' ' << z << endl; }
	A(): x(1), y(2), z(3) {};
	A(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};

};

class B : protected A
{
public:
	void Test();
	B(double _x, double _y, double _z) : A(_x,_y,_z) {};
};

class C : public B
{
public:
	void Test();
	C(double _x, double _y, double _z) : B(_x, _y, _z) {};
};

void CheckNasledovanie();


#endif
