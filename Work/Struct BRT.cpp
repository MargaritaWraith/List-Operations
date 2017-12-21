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
	AddNode(TestTree, 13);
	AddNode(TestTree, 9);

	//PrintNode(TestTree);
	//lRr(TestTree);
	//cout << endl;

	//rRl(TestTree);
	//cout << endl;
	//cout<<FindNode(TestTree, 9)<<endl;
	//cout << FindNode(TestTree, 5) << endl;
	PrintTree(TestTree);

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
void PrintNode(const TreeNode* root)
{
	if (root == NULL)
	{
		cout << NULL << endl;
		return;
	}
	cout << root << "\t" << root->d << "\t" << endl;
	cout << "left=" << root->left << "\t" << "right=" << root->right << endl;
}

// Поиск в дереве
TreeNode* FindNode(TreeNode* root, float v)
{
	if (root == NULL || root->d == v) return root;
	if (v < root->d) return FindNode(root->left, v);
	if (v > root->d) return FindNode(root->right, v);
}

//// Печать дерева
//void PrintTree(TreeNode* root)
//{
//	if (root == NULL) return;
//	cout << root->d << endl;
//	cout << root->left->d << "\t" << root->right->d << endl;
//	PrintTree(root);
//
//}
