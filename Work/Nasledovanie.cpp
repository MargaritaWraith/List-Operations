#include "stdafx.h"
#include <iostream>
#include "Nasledovanie.h"

void B::Test()
{
	PrtA();
	PbA();
//	x = 6;
	y = 7;
	z = 8;
}
void C::Test()
{
	PrtA();
	PbA();
	//x = 6;
	y = 7;
	z = 8;
}


void CheckNasledovanie()
{
	A a;
//	a.x = 12;
//	a.y = 13;
	a.z = 14;
	B b(17, 18, 19);
	b.Test();
	C c(31,32,33);
	c.Test();
//	b.x = 18;
//	b.y = 19;
//	b.z = 20;
}

