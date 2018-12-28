#pragma once
struct node
{
	int key;
	node* lchild;
	node* rchild;
};

class SplayTree
{
public:
	SplayTree() {}
	SplayTree(int n, node& root);
	void generator(int n, node& root);
	node* RR_Rotate(node* k2);
	node* LL_Rotate(node* k2);
	node* Splay(int key, node* root);
	node* New_Node(int key);
	node* Insert(int key, node* root);
	node* Delete(int key, node* root);
	node* Search(int key, node* root);
	void InOrder(node* root);
};