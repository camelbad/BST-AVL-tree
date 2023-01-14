#pragma once
#include <stdio.h>
#include "AVL.h"
#include "stringlist.h"




int max(int a, int b);
int hight(AVLNodePtr avltreeRoot);
AVL*  creatNewAVL();//Initialize the bst tree
int avltree_height(AVL tree);
AVLNodePtr min_node(AVLNodePtr self); //Finding the smallest node
//LL
AVLNodePtr left_left_rotation(AVLNodePtr k2root);
//RR
AVLNodePtr right_right_rotation(AVLNodePtr k1root);
//LR
AVLNodePtr left_right_rotation(AVLNodePtr k3root);
// * RL
AVLNodePtr right_left_rotation(AVLNodePtr k1root);
AVLNodePtr avltree_create_node(int key, AVLNodePtr *left, AVLNodePtr* right);
AVLNodePtr avltree_maximum(AVLNodePtr treeroot);
AVLNodePtr delete_avl_node(AVLNodePtr treeroot, AVLNodePtr targetNode);//Delete node
AVLNodePtr find_avl_node(AVLNodePtr self, long n);//Find node
AVLNodePtr searchById(AVL *recorder, long n);
AVLNodePtr insert_avl_node(AVLNodePtr rootnode, long id);//Insert node
allCourseStastic* displayInfo(AVLNodePtr recorderRoot, allCourseStastic *courselist);//Get course statistics
void destory(AVLNodePtr recorderRoot);//delete tree











