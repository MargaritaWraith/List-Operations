#include "stdafx.h"
#include <iostream>
#include "Class_List.h"

void CheckSingleDirList() 
{
	SingleDirList<double>* pList = new SingleDirList<double>();
	pList->AddLast(3.1415926);
	pList->AddLast(1);
	pList->AddLast(2);
	pList->AddLast(2);
	pList->AddLast(4);
	pList->PrintList();
}

template <class T>
SingleDirList<T>::SingleDirList(const SingleDirList<T>& List)
{
	if (List.pHeader == NULL)	 return;
	else
	{
		pHeader = new DNode<T>();

	}


	
}

template <class T>
DNode<T>* SingleDirList<T>::AddLast(T item)
{
	DNode<T>* pNode = new DNode<T>(item);

	if (pHeader == NULL) pHeader = pNode;
	else
	{
		BaseNode* pCurrent = pHeader;
		while (pCurrent->pNext != NULL)
		{
			pCurrent = pCurrent->pNext;
		}
		pCurrent->pNext = pNode;
	}
	return pNode;
}

template <class T>
DNode<T>* SingleDirList<T>::AddFirst(T item)
{
	//DNode<T>* pNode = new DNode<T>(item);
	DNode<T>* pNode = new DNode<T>();
	pNode->data = item;

	if (pHeader == NULL) pHeader = pNode;
	else
	{
		pNode->pNext = pHeader;
		pHeader = pNode;
	}
	return pNode;
}

template <class T>
void SingleDirList<T>::PrintList()
{
	
	DNode<T>* pCurrent = pHeader;
	while (pCurrent != NULL)
	{
		cout << "data=" << pCurrent->data << "\t address=" << pCurrent << "\t next_address=" << pCurrent->pNext<<endl;
		//pCurrent = (DNode<T>*)pCurrent->pNext;
		pCurrent = static_cast<DNode<T>*>(pCurrent->pNext);
	}
}