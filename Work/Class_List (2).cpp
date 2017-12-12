#include "stdafx.h"
#include <iostream>
#include "Class_List.h"


SingleDirList::SingleDirList(BaseNode* _pHeader)
{
	SingleDirList* newList = new SingleDirList;
	
	BaseNode* pCurrent = _pHeader;
	BaseNode* newNext = NULL;
	newList->pHeader->pNext = newNext;
	newList->

	while (pCurrent != NULL)
	{
		DNode* pNode = static_cast<DNode*>(pCurrent);
	
		newNext = pCurrent->pNext;
		//data = pNode->data;
		
		pCurrent = pCurrent->pNext;
	}
}

//template <class T>
void SingleDirList::AddLast(double item)
{
	DNode* pNode = new DNode;

	if (pHeader == NULL)
	{
		pHeader = pNode;
		pNode->data = item;
	}											 
	else
	{
		BaseNode* pCurrent = pHeader;
		while (pCurrent->pNext != NULL)
		{
			pCurrent = pCurrent->pNext;
		}
		pCurrent->pNext = pNode;
		pNode->data = item;
	}




	/*if(pHeader == NULL)
	{
		pHeader = pNode;
	}
	else
	{
		DNode* pCurrent = pHeader;
		while (pCurent->GetNextNode() != NULL)
		{
			pCurrent = pCurrent->GetNextNode();
		}
		pCurrent->SetNextNode(pNode);
	}*/
}