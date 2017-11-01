#ifndef _MYLIBFUN
#define	_MYLIBFUN

struct ListNode
{
	int v;
	ListNode *next;
};

void ListFill(ListNode *headlist);
void ListAdd(ListNode *headlist);
void ListDel(ListNode *headlist);
void PrintList(ListNode *headlist);
ListNode* FindVal(int v, ListNode *headlist);
void InsertNext(int v, ListNode *ptl);
int FinedByNum(int n);
int FinedPrev();

#endif