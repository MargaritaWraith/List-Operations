#ifndef _LIST
#define	_LIST
using namespace std;

template <class T>
class List_Node
{
public:
	List_Node<T>() {};
	~List_Node<T>() {};

	void SetValue(T value) { this->value = value; };
	T GetValue() { return value; }

	List_Node<T>* GetNextNode() { return pNext; }
	void SetNextNode(List_Node<T>* pNext) { this->pNext = pNext; }
private:
	List_Node<T>* pNext;
	T value;
};


template <class T>
class SingleDirList
{
public:
	SingleDirList<T>() {};
	~SingleDirList<T>() {};

	void AddLast(T item);
	List_Node* GetHeader() { return pHeader; }
private:
	List_Node<T>* pHeader;
};




//void CheckSingleDirList() {};

#endif
