// Binary Recearch Tree

#include "stdafx.h"
#include <iostream>
#include "Struct BRT.h"
using namespace std;

void CheckStructBRT()
{
	TreeNode* TestTree = NULL;
	AddNode(TestTree, 5);
	AddNode(TestTree, 1);
	AddNode(TestTree, 3);
	AddNode(TestTree, 10);
	AddNode(TestTree, 9);
	AddNode(TestTree, 16);
	AddNode(TestTree, 0);
	AddNode(TestTree, 14);
	AddNode(TestTree, 12);
	AddNode(TestTree, 15);
	AddNode(TestTree, 11);
	AddNode(TestTree, 17);
	//AddNode(TestTree, 13);

	cout << DepthTree(TestTree, 0) << endl << endl;

	PrintNodes(TestTree);
	cout << endl;

	/*TurnRight(FindNode(TestTree, 5));
	PrintNodes(TestTree);
	cout << endl;*/

	lRr(TestTree);
	cout << endl;

	rRl(TestTree);
	cout << endl;

	TurnLeft(TestTree, FindNode(TestTree, 5));
	lRr(TestTree);
	cout << endl;
	PrintNodes(TestTree);
	cout << endl;
	/*cout << FindNode(TestTree, 9) << endl;
	cout << FindNode(TestTree, 5) << endl;*/
	//PrintTree(TestTree);

}

// Добавление узла
void AddNode(TreeNode*& root, float v)
{
	TreeNode* newNode = new TreeNode;
	if (root == NULL)
	{
		newNode->d = v;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		return;
	}
	if (v < root->d) AddNode(root->left, v);
	else AddNode(root->right, v);
}

// Обход лево-корень-право (вывод значений по обходу - по возрастанию)
void lRr(const TreeNode* root)
{
	if (root == NULL) return;
	lRr(root->left);
	cout << root->d << ' ';
	lRr(root->right);
}

// Обход право-корень-лево (вывод значений - по убыванию)
void rRl(const TreeNode* root)
{
	if (root == NULL) return;
	rRl(root->right);
	cout << root->d << ' ';
	rRl(root->left);
}

// Печать узла
void PrintNode(const TreeNode* node)
{
	if (node == NULL)
	{
		cout << NULL << endl;
		return;
	}
	cout << node << "\t" << node->d << "\t" << endl;
	cout << "left=" << node->left << "\t" << "right=" << node->right << endl;
}

// Поиск в дереве
TreeNode* FindNode(TreeNode* root, float v)
{
	if (root == NULL || root->d == v) return root;
	if (v < root->d) return FindNode(root->left, v);
	if (v > root->d) return FindNode(root->right, v);
}

// Печать дерева
//void PrintTree(TreeNode* root)
//{
//	int depth = DepthTree(root, 0);
//
//}

// Определение глубины дерева
int DepthTree(TreeNode* root, int depth)
{
	if (root == NULL) return depth - 1;
	int l, r;
	l = DepthTree(root->left, depth + 1);
	r = DepthTree(root->right, depth + 1);
	return l < r ? r : l;
}

// Поиск родительского элемента
TreeNode* FindParent(TreeNode* root, const TreeNode* node)
{
	if (root == NULL || root->left == node || root->right == node) return root;
	TreeNode* parent = FindParent(root->left, node);
	if (parent == NULL)
	{
		parent = FindParent(root->right, node);
	}
	return parent;
}

// Поворот дерева направо			
void TurnRight(TreeNode*& root, TreeNode* node)
{
	TreeNode* temp = node->left;

	if (root == node)
	{
		root = root->left;
	}
	else
	{
		TreeNode* parent = FindParent(root, node);
		if (parent->left == node) parent->left = temp;
		else parent->right = temp;
	}

	while (temp->right != NULL)
		temp = temp->right;
	temp->right = node;
	node->left = NULL;
}

// Поворот дерева налево		  
void TurnLeft(TreeNode*& root, TreeNode* node)
{
	TreeNode* temp = node->right;
	if (root == node)
	{
		root = root->right;
	}
	else
	{
		TreeNode* parent = FindParent(root, node);
		if (parent->right == node) parent->right = temp;
		else parent->left = temp;
	}
	while (temp->left != NULL)
		temp = temp->left;
	temp->left = node;
	node->right = NULL;
}

// Печать всех узлов
void PrintNodes(const TreeNode* root)
{
	if (root == NULL) return;
	cout << root << " " << root->d << " " << root->left << " " << root->right << endl;
	PrintNodes(root->left);
	PrintNodes(root->right);
}

