// 31.10.17.cpp : Defines the entry point for the console application.

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

	//ListNode *insert = NULL;			 // Создание подсписка для вставки
	//insert = new ListNode;
	//ListNode *ptli;
	//ptli = insert;
	//for (int i = 0; i < 2; i++)
	//{
	//	ptli->next = new ListNode;
	//	ptli = ptli->next;
	//}
	//ptli->next = NULL;
				 
	//ListFillAuto(insert);
	//PrintList(insert);

	ListNode* list1 = NewNode(2);

	
	ListNode * Node = FinedByNum(2, headlist);
	cout << Node << endl<<endl;
	cout<<InsertPrev(Node, headlist, list1)<<endl;
	PrintList(headlist);
	DeleteNode(Node,headlist);
	PrintList(headlist);



//	cout << endl << FindVal(5, headlist) << endl << endl;
//
//	InsertNext(13, FindVal(5, headlist));
//
//	PrintList(headlist);


//
//	cout << FinedPrev(Node, headlist) << endl;
//
//	DeleteNode(FinedPrev(Node, headlist), headlist);
//	PrintList(headlist);
//
//	ListNode *RevList = NULL;
//	RevList = ReverseList(headlist);
//	PrintList(RevList);
//	ClearList(headlist);
//
//	DeleteList(headlist);
//	PrintList(headlist);

	cin.get();
	cin.get();

	return 0;
}