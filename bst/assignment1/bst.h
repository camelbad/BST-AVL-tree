#pragma once
#include "stringlist.h"


typedef struct bstNode {
	long data;//student ID
	List courses;//linked List of stored courses
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
	BSTNodePtr root;
} BST;




BST *creatNewBst();//Initialize a bst tree
BSTNodePtr min_node(BSTNodePtr self);//Find the smallest node in the tree
BSTNodePtr delete_bst_node(BSTNodePtr root, long id);//Delete the node of the tree
BSTNodePtr find_bst_node(BSTNodePtr self, long n);//Finding certain node of the tree
BSTNodePtr searchById(BST *recorder, long n);//Find a specific node based on ID
BSTNodePtr insert_bst_node(BSTNodePtr node, long id);//Insert node


allCourseStastic* displayInfo(BSTNodePtr recorderRoot, allCourseStastic *courselist);//Get course statistics
void destory(BSTNodePtr recorderRoot);//Destroying the tree


//void printRecorder(BSTNodePtr node);
