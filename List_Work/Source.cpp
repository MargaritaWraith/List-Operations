#include "stdafx.h"
#include <iostream>
#include "Header.h"

using namespace std;

void ListFill(ListNode *headlist)			 // Заполнить список
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL)
	{
		cin >> ptl->v;
		ptl = ptl->next;
	}
}

void ListAdd(ListNode *headlist)			  // Добавить в конец списка ещё 1 элемент
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

void ListDel(ListNode *headlist)				  // Удалить последний элемент из списка
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->next->next != NULL)
		ptl = ptl->next;
	delete (ptl->next->next);
	ptl->next = NULL;
}

void PrintList(ListNode *headlist)			   // Распечатать список с адресами элементов
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

ListNode* FindVal(int v, ListNode *headlist)	   // Найти адрес элемента в списке
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL&&ptl->v != v)
		ptl = ptl->next;
	return ptl;
}

void InsertNext(int v, ListNode *ptl)		          // Вставить следующий элемент
{
	ListNode *ptl1 = ptl->next;
	ListNode *ins = new ListNode;
	ins->v = v;
	ins->next = ptl1;
	ptl->next = ins;
}

//ListNode FinedByNum(int n)							   // Поиск по номеру элемента
//{
//
//}
//
//ListNode FinedPrev()									  // Поиск предыдущего элемента
//
//void DeleteNode()							   	       // Удалить текущий элемент
//
//
//void ClearList()								          // Очистить список
//
//
//void ReverseList(ListNode *headlist)					  // Перевернуть список