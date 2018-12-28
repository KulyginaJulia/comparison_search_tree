#include "pch.h"
#include <string>
#include "../include/Splay.h"
using namespace std;

TEST(TEST_SPLAY, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TEST_SPLAY, Test_find) {
	node* root = NULL;
	int n = 5;
	SplayTree st;
	st.Insert(1, root);
	st.Insert(3, root);
	st.Insert(8, root);
	st.Insert(5, root);
	st.Insert(4, root);

	EXPECT_NO_THROW(st.Search(1, root));
}

TEST(TEST_SPLAY, Test_del) {
	node *root = NULL;
	int n = 5;
	SplayTree st;
	st.Insert(1, root);
	st.Insert(3, root);
	st.Insert(8, root);
	st.Insert(5, root);
	st.Insert(4, root);

	EXPECT_NO_THROW(st.Delete(2, root));
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