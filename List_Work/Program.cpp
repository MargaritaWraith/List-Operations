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


	ListFill(headlist);
	ListAdd(headlist);
	ListDel(headlist);

	PrintList(headlist);

	cout<<FindVal(5, headlist);


	cin.get();
	cin.get();

	return 0;
}