#ifndef _BRT
#define	_BRT
// Binary Recearch Tree
  
struct TreeNode
{
	float d; // данные
	TreeNode* left;
	TreeNode* right;
};

 struct Tree
{
	TreeNode* root;
};

// Добавление узла
void AddNode(TreeNode*& root, float v);

// Обход лево-корень-право (вывод значений по обходу - по возрастанию)
void lRr(const TreeNode* root);

// Обход право-корень-лево (вывод значений - по убыванию)
void rRl(const TreeNode* root);

// Печать узла
void PrintNode(const TreeNode* root);

// Поиск в дереве
TreeNode* FindNode(TreeNode* root, float v);

//// Печать дерева
//void PrintTree(TreeNode* root);

void CheckStructBRT();

#endif
