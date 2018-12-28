#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "include/Splay.h"
using namespace std;

SplayTree::SplayTree(int n, node& root)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 1 + rand() % 100000;
	}

	for (int i = 0; i< n; i++)
		this->Insert(a[i], &root);
	delete[] a;
}

void SplayTree::generator(int n, node& root)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 1 + rand() % 10000;
	}
	for (int i = 0; i < n; i++)
		this->Insert(a[i], &root);
	delete[] a;
}

// RR(Y rotates to the right)
node* SplayTree::RR_Rotate(node* k2)
{
	node* k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	return k1;
}

// LL(Y rotates to the left)
node* SplayTree::LL_Rotate(node* k2)
{
	node* k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;
	return k1;
}

// An implementation of top-down splay tree
node* SplayTree::Splay(int key, node* root)
{
	if (!root)
		return NULL;
	node header;
	/* header.rchild points to L tree;
	header.lchild points to R Tree */
	header.lchild = header.rchild = NULL;
	node* LeftTreeMax = &header;
	node* RightTreeMin = &header;
	while (1)
	{
		if (key < root->key)
		{
			if (!root->lchild)
				break;
			if (key < root->lchild->key)
			{
				root = RR_Rotate(root);
				// only zig-zig mode need to rotate once,
				if (!root->lchild)
					break;
			}
			/* Link to R Tree */
			RightTreeMin->lchild = root;
			RightTreeMin = RightTreeMin->lchild;
			root = root->lchild;
			RightTreeMin->lchild = NULL;
		}
		else if (key > root->key)
		{
			if (!root->rchild)
				break;
			if (key > root->rchild->key)
			{
				root = LL_Rotate(root);
				// only zag-zag mode need to rotate once,
				if (!root->rchild)
					break;
			}
			/* Link to L Tree */
			LeftTreeMax->rchild = root;
			LeftTreeMax = LeftTreeMax->rchild;
			root = root->rchild;
			LeftTreeMax->rchild = NULL;
		}
		else
			break;
	}
	/* assemble L Tree, Middle Tree and R tree */
	LeftTreeMax->rchild = root->lchild;
	RightTreeMin->lchild = root->rchild;
	root->lchild = header.rchild;
	root->rchild = header.lchild;
	return root;
}

node* SplayTree::New_Node(int key)
{
	node* p_node = new node;
	if (!p_node)
	{
		fprintf(stderr, "Out of memory!\n");
		exit(1);
	}
	p_node->key = key;
	p_node->lchild = p_node->rchild = NULL;
	return p_node;
}

node* SplayTree::Insert(int key, node* root)
{
	static node* p_node = NULL;
	if (!p_node)
		p_node = New_Node(key);
	else
		p_node->key = key;
	if (!root)
	{
		root = p_node;
		p_node = NULL;
		return root;
	}
	root = Splay(key, root);
	/* This is BST that, all keys <= root->key is in root->lchild, all keys >
	root->key is in root->rchild. */
	if (key < root->key)
	{
		p_node->lchild = root->lchild;
		p_node->rchild = root;
		root->lchild = NULL;
		root = p_node;
	}
	else if (key > root->key)
	{
		p_node->rchild = root->rchild;
		p_node->lchild = root;
		root->rchild = NULL;
		root = p_node;
	}
	else
		return root;
	p_node = NULL;
	return root;
}

node* SplayTree::Delete(int key, node* root)
{
	node* temp;
	if (!root)
		return NULL;
	root = Splay(key, root);
	if (key != root->key)
		return root;
	else
	{
		if (!root->lchild)
		{
			temp = root;
			root = root->rchild;
		}
		else
		{
			temp = root;
			/*Note: Since key == root->key,
			so after Splay(key, root->lchild),
			the tree we get will have no right child tree.*/
			root = Splay(key, root->lchild);
			root->rchild = temp->rchild;
		}
		free(temp);
		return root;
	}
}

node* SplayTree::Search(int key, node* root)
{
	return Splay(key, root);
}

void SplayTree::InOrder(node* root)
{
	if (root)
	{
		InOrder(root->lchild);
		cout << "key: " << root->key;
		if (root->lchild)
			cout << " | left child: " << root->lchild->key;
		if (root->rchild)
			cout << " | right child: " << root->rchild->key;
		cout << "\n";
		InOrder(root->rchild);
	}
}
//
//int main()
//{
//	SplayTree st;
//	int n;
//	cout << "n" << endl;
//	cin >> n;
//	int *ptrvalue = new int[n];
//	for (int count = 0; count < n; count++)
//		ptrvalue[count] = 1 + rand() % 10000;
//	node *root;
//	root = NULL;
//	const int length = n;
//	int i;
//	for (i = 0; i < length; i++)
//		root = st.Insert(ptrvalue[i], root);
//	cout << "\nInOrder: \n";
//	st.InOrder(root);
//	int input, choice;
//	while (1)
//	{
//		cout << "\nSplay Tree Operations\n";
//		cout << "1. Insert " << endl;
//		cout << "2. Delete" << endl;
//		cout << "3. Search" << endl;
//		cout << "4. Exit" << endl;
//		cout << "Enter your choice: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Enter value to be inserted: ";
//			cin >> input;
//			root = st.Insert(input, root);
//			cout << "\nAfter Insert: " << input << endl;
//			st.InOrder(root);
//			break;
//		case 2:
//			cout << "Enter value to be deleted: ";
//			cin >> input;
//			root = st.Delete(input, root);
//			cout << "\nAfter Delete: " << input << endl;
//			st.InOrder(root);
//			break;
//		case 3:
//			cout << "Enter value to be searched: ";
//			cin >> input;
//			root = st.Search(input, root);
//			cout << "\nAfter Search " << input << endl;
//			st.InOrder(root);
//			break;
//
//		case 4:
//			exit(1);
//		default:
//			cout << "\nInvalid type! \n";
//		}
//	}
//	delete[] ptrvalue;
//	cout << "\n";
//	return 0;
//}