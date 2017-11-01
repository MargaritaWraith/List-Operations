#include "stdafx.h"
#include <iostream>
#include "Header.h"

using namespace std;

void ListFill(ListNode *headlist)			 // ��������� ������
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL)
	{
		cin >> ptl->v;
		ptl = ptl->next;
	}
}

void ListFillAuto(ListNode *headlist)			 // ��������� ������
{
	ListNode *ptl;
	ptl = headlist;
	int i = 0;
	while (ptl != NULL)
	{
		ptl->v = i + 7;
		ptl = ptl->next;
		i += 13;
	}
}

void ListAdd(ListNode *headlist)			  // �������� � ����� ������ ��� 1 �������
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->next != NULL)
		ptl = ptl->next;
	ptl->next = new ListNode;
	ptl = ptl->next;
	ptl->next = NULL;
	cin >> ptl->v;
	//	ptl->v = 14;
}

void ListDel(ListNode *headlist)				  // ������� ��������� ������� �� ������
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->next->next != NULL)
		ptl = ptl->next;
	delete (ptl->next->next);
	ptl->next = NULL;
}

void PrintList(ListNode *headlist)			   // ����������� ������ � �������� ���������
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->next != NULL)
	{
		cout << ptl << " Value " << ptl->v << "   Next adress is " << ptl->next << endl;
		ptl = ptl->next;
	}

	cout << ptl << " Value " << ptl->v << "   Next adress is " << ptl->next << endl;
}

ListNode* FindVal(int v, ListNode *headlist)	   // ����� ����� �������� � ������
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL&&ptl->v != v)
		ptl = ptl->next;
	return ptl;
}

void InsertNext(int v, ListNode *ptl)		          // �������� ��������� �������
{
	if (ptl == NULL) return;
	ListNode *ptl1 = ptl->next;
	ListNode *ins = new ListNode;
	ins->v = v;
	ins->next = ptl1;
	ptl->next = ins;

}

ListNode* FinedByNum(int n, ListNode *headlist)							   // ����� �� ������ ��������
{
	ListNode *ptl;
	ptl = headlist;
	if (ptl != NULL&&ptl->next != NULL)
		for (int i = 0; i < n; i++)										// ����� �������� ������������� �� ����!
			ptl = ptl->next;
	else ptl = NULL;
	return ptl;
}
//
//ListNode FinedPrev()									  // ����� ����������� ��������
//
//void DeleteNode()							   	       // ������� ������� �������
//
//
//void ClearList()								          // �������� ������
//
//
//void ReverseList(ListNode *headlist)					  // ����������� ������