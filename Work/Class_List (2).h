#ifndef _LIST
#define	_LIST
using namespace std;

//template <class T>
class BaseNode
{
public:
	BaseNode() {};
virtual	~BaseNode() {};
	friend class SingleDirList;
protected:
	BaseNode* pNext;
};

//template <class T>
class DNode : public BaseNode
{
public:
	DNode() {};
	~DNode() {};


	//void Setdata(double data) { this->data = data; };
	//double Getdata() { return data; }
	//DNode<T>* GetNextNode() { return pNext; }
	//void SetNextNode(DNode<T>* pNext) { this->pNext = pNext; }

private:
	double data;
	friend class SingleDirList;
};


//template <class T>
class SingleDirList
{
private:
	BaseNode* pHeader;
public:
	SingleDirList() { pHeader = NULL; };
	SingleDirList(BaseNode* _pHeader);
	~SingleDirList() {};

	void AddLast(double item);
//	DNode* GetHeader() { return pHeader; }

};




//void CheckSingleDirList() {};

#endif
