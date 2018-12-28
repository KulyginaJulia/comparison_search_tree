#pragma once
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cmath>
#include <sstream>

struct nodeptr_ // —труктура дл€ представлени€ узлов дерева
{
	int element;
	nodeptr_ *left;
	nodeptr_ *right;
	int height;
};

typedef struct nodeptr_ *nodeptr;

class bstree {
private:
    const char* a_str;
public:
	//bstree() { a_str = new char(); }
	//bstree(int n, nodeptr &root);
	void generator(int n, nodeptr &root);
	const char* get_a() { return this->a_str; }
	void set_a(int p);
	void insert(int, nodeptr &);
	bool del(int, nodeptr &);
	int deletemin(nodeptr &);
	bool find(int, nodeptr &);
	void inorder(nodeptr);
	int bsheight(nodeptr);
	nodeptr srl(nodeptr &);
	nodeptr drl(nodeptr &);
	nodeptr srr(nodeptr &);
	nodeptr drr(nodeptr &);
};