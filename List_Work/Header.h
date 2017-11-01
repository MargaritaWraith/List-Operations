#ifndef _MYLIBFUN
#define	_MYLIBFUN

struct ListNode
{
	int v;
	ListNode *next;
};

// Заполнить список
void ListFill(ListNode *headlist);

// Автозаполнение списка
void ListFillAuto(ListNode *headlist);

// Добавить элемент в конец списка
void ListAdd(ListNode *headlist);

// Удалить последний элемент
void ListDel(ListNode *headlist);

// Распечатать список
void PrintList(ListNode *headlist);

// Найти адрес элемента по его значению
ListNode* FindVal(int v, ListNode *headlist);

// Вставить элемент после текущего по адресу текущего
void InsertNext(int v, ListNode *ptl);

// Найти элемент по его индексу
ListNode* FinedByNum(int n, ListNode *headlist);

// Найти предыдущий элемент
ListNode* FinedPrev(ListNode *ptl1, ListNode *headlist);

// Удалить текущий элемент
void DeleteNode(ListNode *ptl1, ListNode *headlist);

// Очистить список
void ClearList(ListNode *headlist);

#endif