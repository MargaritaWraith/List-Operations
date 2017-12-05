#include "stdafx.h"
#include <iostream>
#include "Class_List.h"

	   
DNode::DNode()
{
	data = 0;
	next = NULL;
}

DNode::DNode(double _data)
{
	data = _data;
	next = NULL;
}

DNode::DNode(const DNode& node)
{
	data = node.data;
	next = node.next;
}

bool List::AddLastNode(DNode node)
{
	DNode* ptl = header;  
	while (ptl->next != NULL && ptl->next != NULL)
		ptl->next = ptl->next;
	ptl->next = node.next;
	ptl->data = node.data;
	return true;
}


void CheckList()
{

}