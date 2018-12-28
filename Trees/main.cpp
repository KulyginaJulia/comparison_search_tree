#include "../Trees_comparison/include/AVL.h"
#include "../Trees_comparison/include/Splay.h"
#include <map>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <algorithm>
#include <vector>

using namespace std;

void generator(map<int, char>* tree, int N) {
	for (int i = 0; i < N; i++) {
		int tmp = 1 + rand() % 10000;
		pair<int, char> p = make_pair(tmp, 'r');
		tree->insert(p);
	}

}

void generator(vector<int> tree, int N) {
	for (int i = 0; i < N; i++) {
		int tmp = 1 + rand() % 10000;
		tree.push_back(tmp);
	}
	sort(tree.begin(), tree.end());
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Russian");
	int Size = atoi(argv[1]);
	nodeptr root_avl = NULL;
	node *root_splay = NULL;
	double start, end;
	bstree avl_tree;
	SplayTree splay_tree;
	map<int, char> RedBlackTree;
	pair<int, char> p;
	vector<int> binary;
	switch (atoi(argv[2])) {
	case 0:
		avl_tree.generator(Size, root_avl);
		start = omp_get_wtime();
		switch (atoi(argv[3])) {
		case 0:
			avl_tree.insert(atoi(argv[4]), root_avl);
			break;
		case 1:
			avl_tree.find(atoi(argv[4]), root_avl);
			break;
		case 2:
			avl_tree.del(atoi(argv[4]), root_avl);
			break;
		default:
			break;
		}
		end = omp_get_wtime();
		break;
	case 1:
		splay_tree.generator(Size, *root_splay);
		start = omp_get_wtime();
		switch (atoi(argv[3])) {
		case 0:
			splay_tree.Insert(atoi(argv[4]), root_splay);
			break;
		case 1:
			splay_tree.Search(atoi(argv[4]), root_splay);
			break;
		case 2:
			splay_tree.Delete(atoi(argv[4]), root_splay);
			break;
		default:
			break;
		}
		end = omp_get_wtime();
		break;
	case 2:
		generator(&RedBlackTree, Size);
		start = omp_get_wtime();
		switch (atoi(argv[3])) {
		case 0:
			p = make_pair(atoi(argv[4]), 'r');
			(&RedBlackTree)->insert(p); 
			break;
		case 1:
			(&RedBlackTree)->find(atoi(argv[4]));
			break;
		case 2:
			(&RedBlackTree)->erase(atoi(argv[4]));
			break;
		default:
			break;
		}
		end = omp_get_wtime();
		break;
	case 3:
		generator(binary, Size);
		start = omp_get_wtime();
		find(binary.begin(), binary.end(), atoi(argv[4]));
		end = omp_get_wtime();
		break;
	}


	double delta = end - start;
	cout << "Time : " << delta << endl;
}