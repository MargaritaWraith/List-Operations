#ifndef _LIST
#define	_LIST
using namespace std;

class BaseNode
{
public:

	BaseNode* next;
	BaseNode() {};
	~BaseNode() {};
private:
};

class DNode:public BaseNode
{
public:
	double data;
	DNode();
	DNode(double _data);
	DNode(const DNode& node);
	~DNode() {};
};

class List :public DNode
{
protected:
	DNode* header;
	List() {};
	~List() {};
	bool AddLastNode(DNode node);
};




 void CheckList();

#endif
