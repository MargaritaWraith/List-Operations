#ifndef _MYLIBFUN
#define	_MYLIBFUN

struct ListNode
{
	int v;
	ListNode *next;
};

// ��������� ������
void ListFill(ListNode *headlist);

// �������������� ������
void ListFillAuto(ListNode *headlist);

// �������� ������� � ����� ������
void ListAdd(ListNode *headlist);

// ������� ��������� �������
void ListDel(ListNode *headlist);

// ����������� ������
void PrintList(ListNode *headlist);

// ����� ����� �������� �� ��� ��������
ListNode* FindVal(int v, ListNode *headlist);

// �������� ������� ����� �������� �� ������ ��������
void InsertNext(int v, ListNode *ptl);

// ����� ������� �� ��� �������
ListNode* FinedByNum(int n, ListNode *headlist);

// ����� ���������� �������
ListNode* FinedPrev(ListNode *ptl1, ListNode *headlist);

// ������� ������� �������
void DeleteNode(ListNode *ptl1, ListNode *headlist);

// �������� ������
void ClearList(ListNode *headlist);

#endif