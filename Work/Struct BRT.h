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

// Печать всех узлов
void PrintNodes(const TreeNode* root);

// Поиск в дереве
TreeNode* FindNode(TreeNode* root, float v);

// Печать дерева
//void PrintTree(TreeNode* root);

// Определение глубины дерева
int DepthTree(TreeNode* root, int depth);

// Поворот дерева направо
void TurnRight(TreeNode*& root, TreeNode* node);

// Поворот дерева налево
void TurnLeft(TreeNode*& root, TreeNode* node);

// Поиск родительского элемента
TreeNode* FindParent(TreeNode* root, const TreeNode* node);
  

void CheckStructBRT();

#endif
