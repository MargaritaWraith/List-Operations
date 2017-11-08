#include "stdafx.h"
#include <iostream>
#include "List.h"

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

// Создание узла списка
ListNode* NewNode(int v)
{
	ListNode * newnode = new ListNode;
	newnode->next = NULL;
	newnode->v = v;
	return newnode;
}

void ListFillAuto(ListNode *headlist)			 // Заполнить список
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
	if (headlist == NULL) return;
	while (ptl->next != NULL)
	{
		cout << ptl << " Value " << ptl->v << "   Next adress is " << ptl->next << endl;
		ptl = ptl->next;
	}

	cout << ptl << " Value " << ptl->v << "   Next adress is " << ptl->next << endl << endl;
}

ListNode* FindVal(int v, ListNode *headlist) 	    // Найти адрес элемента в списке
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->v != v)
		ptl = ptl->next;
	return ptl;
}

void InsertNext(int v, ListNode *ptl)		          // Вставить следующий элемент
{
	if (ptl == NULL) return;
	ListNode *ptl1 = ptl->next;
	ListNode *ins = new ListNode;
	ins->v = v;
	ins->next = ptl1;
	ptl->next = ins;

}


ListNode* FinedByNum(int n, ListNode *headlist)		  // Поиск по номеру элемента
{
	ListNode *ptl;
	ptl = headlist;
	if (ptl != NULL && ptl->next != NULL)
		for (int i = 0; i < n; i++)						// Номер элемента отсчитывается от нуля!
			ptl = ptl->next;
	else
		ptl = NULL;
	return ptl;
}


ListNode* FinedPrev(ListNode *ptl1, ListNode *headlist)				  // Поиск предыдущего элемента
{
	ListNode *ptl;
	ptl = headlist;
	while (ptl != NULL && ptl->next != ptl1)
		ptl = ptl->next;
	return ptl;
}

bool DeleteNode(ListNode *& ptl, ListNode *& headlist)		 	        // Удалить элемент списка
{
	if (ptl == NULL || headlist == NULL) return false;	  //передача пустых элементов

	if (ptl == headlist)					   //удаляем голову
	{
		headlist = headlist->next;
		delete ptl;
		ptl = NULL;
		return true;
	}

	if (FinedPrev(ptl, headlist) == NULL) return false;	   //удаляемый элемент не принадлежит текущему списку

	ListNode * ptlPrev = FinedPrev(ptl, headlist);			  //Общий случай
	ptlPrev->next = ptl->next;
	delete ptl;
	ptl = NULL;
	return true;

	/*ListNode *ptl;
	ptl = headlist;
	if (ptl == NULL || ptl1 == NULL || ptl == ptl1) return;
	while (ptl->next != ptl1)
		ptl = ptl->next;
	ptl->next = ptl1->next;
	delete ptl1;*/
}

void ClearList(ListNode *headlist)					        // Очистить список
{
	if (headlist == NULL) return;
	ClearList(headlist->next);
	cout << "del" << headlist << ":" << headlist->v << endl;
	delete headlist;
}

ListNode* ReverseList(ListNode *headlist)					  // Перевернуть список
{
	ListNode *ptl, *newhead = NULL, *newptl = NULL;
	ptl = headlist;
	if (ptl == NULL) return NULL;

	do
	{
		newptl = new ListNode;
		newptl->v = ptl->v;
		newptl->next = newhead;
		newhead = newptl;
		ptl = ptl->next;
	} while (ptl != NULL);
	return newhead;
}

void DeleteList(ListNode *&headlist)					// Удаление списка
{
	ListNode *ptl;
	while (headlist != NULL)
	{
		ptl = headlist;
		headlist = ptl->next;
		delete ptl;
	}
}

bool InsertPrev(ListNode *ptl, ListNode *&headlist, ListNode *ptli)		 // Вставка элементов после текущего
{
	ListNode *ptlt = FinedPrev(ptl, headlist);
	if (ptl == NULL || headlist == NULL)
		return false;
	if (ptlt == NULL)
	{
		if (ptl == headlist)
		{
			headlist = ptli;
			while (ptli->next != NULL)
				ptli = ptli->next;
			ptli->next = ptl;

			return true;
		}
		else return false;
	}
	ptlt->next = ptli;
	ptli = FinedPrev(NULL, ptli);
	ptli->next = ptl;
	return true;
}

void CheckList()
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
	cout << Node << endl << endl;
	cout << InsertPrev(Node, headlist, list1) << endl;
	PrintList(headlist);
	DeleteNode(Node, headlist);
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
}