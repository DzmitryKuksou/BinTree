#include<iostream>
using namespace std;
#include"tree.h"
TreeNode::TreeNode()
{
	root = NULL;
}
TreeNode::TreeNode(int t)
{
	root = NULL;
	char *k = new char[N], *l = new char[N];
	for (int i = 0; i < t; i++)
	{
		cout << "enter the english word:"<<endl;
		cin.getline(k, N);
		cout << "enter the russian word:" << endl;
		cin.getline(l, N);
		system("cls");
		PushWord(root, k, l);
	}
}
TreeNode::TreeNode(const TreeNode& a)
{
	if (a.root != NULL)
	{
		PushWord(root, a.root->eng, a.root->russ);
		CopyTree(root, a.root);
	}
}
void TreeNode::PushWord(Node*& root, char* EngWord, char* RussWord)
{
	if (root == NULL)
	{
		root = new Node;
		root->right = NULL;
		root->left = NULL;
		root->eng = new char[N];
		root->russ = new char[N];
		strcpy(root->eng, EngWord);
		strcpy(root->russ, RussWord);
		return;
	}
	else
	{
		
		if (SortByAlpabet(root->eng, EngWord))PushWord(root->right, EngWord, RussWord);
		else PushWord(root->left, EngWord, RussWord);
	}
}
void TreeNode::DisplayTree()const
{
	DisplayTree(root);
}
void TreeNode::DisplayTree(Node* root)const
{
	if (root == NULL)return;
	else
	{
		if (root->left != NULL)DisplayTree(root->left);
		cout << root->eng << " : " << root->russ << endl;
		if (root->right != NULL)DisplayTree(root->right);
	}

}
void TreeNode::CopyTree(Node*& rootnew, const Node*rootold)
{
	if (rootold->left != NULL)
	{
		PushWord(rootnew, (rootold->left)->eng, (rootold->left)->russ); CopyTree(rootnew, rootold->left);
	}
	if (rootold->right != NULL)
	{
		PushWord(rootnew, (rootold->right)->eng, (rootold->right)->russ); CopyTree(rootnew, rootold->right);
	}
}
Node* TreeNode::SearchByWord(Node* root, char* word)const
{
	if (!strcmp(root->eng, word)) return root;
	if (root->left != NULL)SearchByWord(root->left, word);
	if (root->right != NULL)SearchByWord(root->right, word);
	else return 0;
}
TreeNode::~TreeNode()
{
	DeleteTree(root);
}
void TreeNode::DeleteTree(Node* root)
{
	if (root == NULL)
	{
		delete root;
	}
	else
	{
		if (root->left != NULL) DeleteTree(root->left);
		if (root->right != NULL) DeleteTree(root->right);
		delete root;
	}
}
void TreeNode::DisplayNode(Node* a)const
{
	if (a == NULL)return;
	cout << a->eng << "--" << a->russ << endl;
}
bool TreeNode::SortByAlpabet(char* a, char* b)const
{
	int i = 0;
	while (true)
	{
		if (a[i] < b[i])
		{
			return 1;
		}
		if (a[i] > b[i])
		{
			return 0;
		}
		i++;
		if (a[i] == 0)return 1;
		if (b[i] == 0)return 0;
	}
}