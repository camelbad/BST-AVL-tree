#pragma once
#include "stringlist.h"


typedef struct AVLNode {
	long data;//student ID
	List courses;//linked List of stored courses
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
} *AVLNodePtr;

typedef struct AVL{
	AVLNodePtr root;
} AVL;




AVL *creatNewAVL();//Initialize a bst tree
AVLNodePtr min_node(AVLNodePtr self);//Find the smallest node in the tree
AVLNodePtr delete_bst_node(AVLNodePtr root, long id);//Delete the node of the tree
AVLNodePtr find_bst_node(AVLNodePtr self, long n);//Finding certain node of the tree
AVLNodePtr searchById(AVL *recorder, long n);//Find a specific node based on ID
AVLNodePtr insert_bst_node(AVLNodePtr node, long id);//Insert node


allCourseStastic* displayInfo(AVLNodePtr recorderRoot, allCourseStastic *courselist);//Get course statistics
void destory(AVLNodePtr recorderRoot);//Destroying the tree


//void printRecorder(BSTNodePtr node);
