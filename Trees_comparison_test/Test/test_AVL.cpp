#include "pch.h"
#include <string>
#include "../include/AVL.h"
using namespace std;

TEST(TEST_AVL, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TEST_AVL, Test_height) {
	nodeptr root = NULL;
	int n = 5;
	bstree bst;
	bst.insert(1, root);
	bst.insert(3, root);
	bst.insert(8, root);
	bst.insert(5, root);
	bst.insert(4, root);

	EXPECT_EQ(bst.bsheight(root), 2);
}

TEST(TEST_AVL, Test_find) {
	nodeptr root = NULL;
	int n = 5;
	bstree bst;
	bst.insert(1, root);
	bst.insert(3, root);
	bst.insert(8, root);
	bst.insert(5, root);
	bst.insert(4, root);
	
	EXPECT_EQ(bst.find(1, root), true);
}

TEST(TEST_AVL, Test_del) {
	nodeptr root = NULL;
	int n = 5;
	bstree bst;
	bst.insert(1, root);
	bst.insert(3, root);
	bst.insert(8, root);
	bst.insert(5, root);
	bst.insert(4, root);

	EXPECT_EQ(bst.del(3, root), true);
}

TEST(TEST_AVL, Test_del_not_exist) {
	nodeptr root = NULL;
	int n = 5;
	bstree bst;
	bst.insert(1, root);
	bst.insert(3, root);
	bst.insert(8, root);
	bst.insert(5, root);
	bst.insert(4, root);

	EXPECT_EQ(bst.del(2, root), false);
}

//TEST(TEST_AVL, Test_insert) {
//	nodeptr root = NULL;
//	int n = 5;
//	bstree bst;
//	bst.insert(1, root);
//	bst.inorder(root);
//	string expect = "1";
//	auto result = bst.get_a();
//	EXPECT_EQ(expect, "dfghjk");
//	//EXPECT_EQ(bst.find(1, root), true);
//}