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
	AddNode(TestTree, 15);
	AddNode(TestTree, 0);


	cout << DepthTree(TestTree, 0) << endl;

	PrintNodes(TestTree);
	cout << endl;

	TurnRight(FindNode(TestTree, 5));
	PrintNodes(TestTree);

	//lRr(TestTree);
	//cout << endl;

	//rRl(TestTree);
	//cout << endl;
	//cout<<FindNode(TestTree, 9)<<endl;
	//cout << FindNode(TestTree, 5) << endl;
	//PrintTree(TestTree);

}

// ���������� ����
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

// ����� ����-������-����� (����� �������� �� ������ - �� �����������)
void lRr(const TreeNode* root)
{
	if (root == NULL) return;
	lRr(root->left);
	cout << root->d << ' ';
	lRr(root->right);
}

// ����� �����-������-���� (����� �������� - �� ��������)
void rRl(const TreeNode* root)
{
	if (root == NULL) return;
	rRl(root->right);
	cout << root->d << ' ';
	rRl(root->left);
}

// ������ ����
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

// ����� � ������
TreeNode* FindNode(TreeNode* root, float v)
{
	if (root == NULL || root->d == v) return root;
	if (v < root->d) return FindNode(root->left, v);
	if (v > root->d) return FindNode(root->right, v);
}

// ������ ������
void PrintTree(TreeNode* root)
{
	int depth = DepthTree(root, 0);

}

// ����������� ������� ������
int DepthTree(TreeNode* root, int depth)
{
	if (root == NULL) return depth - 1;
	int l, r;
	l = DepthTree(root->left, depth + 1);
	r = DepthTree(root->right, depth + 1);
	return l < r ? r : l;
}

// ������� ������ �������				 // �� ��������
void TurnRight(TreeNode* node)
{
	TreeNode* temp = node->left;
	node->left = temp->right;
	temp->right = node;	
}

// ������� ������ ������		  // �� ��������
void TurnLeft(TreeNode* node)
{
	TreeNode* temp = node->right;
	node->right = temp->left;
	temp->left = node;
}

// ������ ���� �����
void PrintNodes(const TreeNode* root)
{
	if (root == NULL) return;
	cout << root << " " << root->d << " " << root->left << " " << root->right << endl;
	PrintNodes(root->left);
	PrintNodes(root->right);
}