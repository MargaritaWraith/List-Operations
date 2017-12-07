#include "stdafx.h"
#include <iostream>
#include "Class_List.h"

	   
template <class T>
void SingleDirList<T>::AddLast(T item) 
{
	List_Node* pNode = new List_Node();
	pNode->SetValue(item);

	if(pHeader == null)
	{
		pHeader = pNode;
	}
	else
	{
		List_Node<T>* pCurrent = pHeader;
		while (pCurent->GetNextNode() != null)
		{
			pCurrent = pCurrent->GetNextNode();
		}
		pCurrent->SetNextNode(pNode);
	}
}