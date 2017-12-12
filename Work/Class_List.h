#ifndef _LIST
#define	_LIST
using namespace std;
void CheckSingleDirList();

class BaseNode
{
public:
	BaseNode() { pNext = NULL; };
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
	DNode<T>(T _data) { data = _data; };
	DNode<T>(const DNode<T>& Node);
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

	DNode<T>* AddFirst(T data);
	DNode<T>* AddLast(T data);
//	DNode* GetHeader() { return pHeader; }
	void PrintList();


};

		   


#endif
