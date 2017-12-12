#ifndef _LIST
#define	_LIST
using namespace std;
void CheckSingleDirList();

//template <class T>
class BaseNode
{
public:
	BaseNode() { pNext = NULL; };
	BaseNode(const BaseNode& Node) {};
	virtual	~BaseNode() {};
	template <class T> friend class SingleDirList;
protected:
	BaseNode* pNext;
};

template <class T>
class DNode : public BaseNode
{
public:
	DNode<T>() { }
	DNode<T>(T value) { data = value; };
	DNode<T>(const DNode<T>& Node) {};
	~DNode<T>() {};

	//void Setdata(double data) { this->data = data; };
	//double Getdata() { return data; }
	//DNode<T>* GetNextNode() { return pNext; }
	//void SetNextNode(DNode<T>* pNext) { this->pNext = pNext; }

private:
	T data;
	template <class T> friend class SingleDirList;
};


template <class T>
class SingleDirList
{
private:
	DNode<T>* pHeader = NULL;
public:
	SingleDirList<T>() {};
	SingleDirList<T>(const SingleDirList<T>& List);
	~SingleDirList<T>() {};

	DNode<T>* AddFirst(T item);
	DNode<T>* AddLast(T item);
//	DNode* GetHeader() { return pHeader; }
	void PrintList();


};

		   


#endif
