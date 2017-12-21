#ifndef _BRT
#define	_BRT
// Binary Recearch Tree
  
struct TreeNode
{
	float d; // ������
	TreeNode* left;
	TreeNode* right;
};

 struct Tree
{
	TreeNode* root;
};

// ���������� ����
void AddNode(TreeNode*& root, float v);

// ����� ����-������-����� (����� �������� �� ������ - �� �����������)
void lRr(const TreeNode* root);

// ����� �����-������-���� (����� �������� - �� ��������)
void rRl(const TreeNode* root);

// ������ ����
void PrintNode(const TreeNode* root);

// ����� � ������
TreeNode* FindNode(TreeNode* root, float v);

//// ������ ������
//void PrintTree(TreeNode* root);

void CheckStructBRT();

#endif
