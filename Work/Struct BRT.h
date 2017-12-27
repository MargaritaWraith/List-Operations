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

// ������ ���� �����
void PrintNodes(const TreeNode* root);

// ����� � ������
TreeNode* FindNode(TreeNode* root, float v);

// ������ ������
//void PrintTree(TreeNode* root);

// ����������� ������� ������
int DepthTree(TreeNode* root, int depth);

// ������� ������ �������
void TurnRight(TreeNode*& root, TreeNode* node);

// ������� ������ ������
void TurnLeft(TreeNode*& root, TreeNode* node);

// ����� ������������� ��������
TreeNode* FindParent(TreeNode* root, const TreeNode* node);
  

void CheckStructBRT();

#endif
