#include "stdafx.h"
#include <iostream>
#include "Temp.h"
using namespace std;

int AA::num = 0;

void CheckTemp()
{
	AA objA1;
	objA1.PrintNum();

	AA objA2;
	AA::PrintNum();

	AA* ptA;
	ptA = new AA;
	ptA->PrintNum();
	delete ptA;
//	objA2.~AA();	   ������ ��������! ���������� ����� ��������� ������ � ������ �������.
	AA::PrintNum();
}