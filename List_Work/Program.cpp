// 31.10.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"


using namespace std;

int main()
{
	ListNode *headlist = NULL;
	ListNode *ptl;
	headlist = new ListNode;
	ptl = headlist;

	for (int i = 0; i < 4; i++)
	{
		ptl->next = new ListNode;
		ptl = ptl->next;
	}
	ptl->next = NULL;


	ListFillAuto(headlist);
	
	PrintList(headlist);

	cout<<endl<<FindVal(5, headlist)<<endl<<endl;

	InsertNext(13, FindVal(5, headlist));

	PrintList(headlist);

	cout << FinedByNum(2, headlist)->v;


	cin.get();
	cin.get();

	return 0;
}