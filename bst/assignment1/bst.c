#include "bst.h"

BST*  creatNewBst( )//Initialize the bst tree
{
	BST *recorder= (BST*)malloc(sizeof (BST));//Allocation space
	
	recorder->root= NULL;//Root node is set to empty
	
	return recorder;
}



BSTNodePtr min_node(BSTNodePtr self) //Finding the smallest node
{
	BSTNodePtr current = self;
	while (current->left != NULL)//When the last node is not reached
	{
		current = current->left;//left
	}
	return current;
}


BSTNodePtr delete_bst_node(BSTNodePtr root, long id)//Delete node
{
	if (root != NULL) {
		if (id == root->data) { // found item 
			if (root->left != NULL && root->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(root->right);
				root->data = successor->data;
				root->right = delete_bst_node(root->right, root->data);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = root;
				if (root->left) {
					root = root->left;
				}
				else {
					root = root->right;
				}
				destroy_list(to_free->courses.head);
				free(to_free);
			}
		}
		else if (id < root->data) {
			root->left = delete_bst_node(root->left, id);
		}
		else {
			root->right = delete_bst_node(root->right, id);
		}
	}
	return root;
}

BSTNodePtr find_bst_node(BSTNodePtr self, long n)//Find node
{
	if (self == NULL || (n == self->data)) {//Restrictions
		return self;
	}
	else if (n < self->data) {//Recursively traverses the entire tree
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

BSTNodePtr searchById(BST *recorder, long n) {
	return find_bst_node(recorder->root, n);
}

BSTNodePtr insert_bst_node(BSTNodePtr node, long id)//Insert node
{
	if (node == NULL) { /* found where to put it*/
		node = malloc(sizeof *node);
		node->data = id;
		node->courses= new_courselist();
		node->left = node->right = NULL;
	}
	else if (id < node->data) {//Recursively traverses the entire tree
		node->left = insert_bst_node(node->left, id);
	}
	else if (id >node->data) {
		node->right = insert_bst_node(node->right, id);
	}
	return node;
}






	allCourseStastic* displayInfo(BSTNodePtr recorderRoot, allCourseStastic *courselist)//Get course statistics
	{

		if (recorderRoot == NULL)
		{
			return courselist;
		}
		displayInfo(recorderRoot->left, courselist);//in order recursive traversal
		ListNodePtr coursePtr = recorderRoot->courses.head;//For each node, get the head pointer for this node's course list
		while (coursePtr != NULL)
		{

			char* courseName = coursePtr->data;//Get the first course name
			courseNodePtr coursePtrTemp = findCourse(courseName, courselist);//Determine whether this course already exists in the course statistics list

			if (coursePtrTemp == NULL)
			{
				insertCourseSta(courseName, courselist);//If this course is not in the course statistics list, insert this course into the course statistics list

			}
			else
			{
				addCourseCounter(coursePtrTemp);//If it already exists, the course counter adds one

			}
			coursePtr = coursePtr->next;//move pointer to next
		}

		displayInfo(recorderRoot->right, courselist);
		return courselist;
	}


	void destory(BSTNodePtr recorderRoot)//delete tree
	{
		if (recorderRoot == NULL)
			return;
		if (recorderRoot->left!= NULL)
			destory(recorderRoot->left);
		if (recorderRoot->right!= NULL)
			destory(recorderRoot->right);
		if (recorderRoot->courses.head!=NULL)
		{
			destroy_list(&recorderRoot->courses);
		}
		free(recorderRoot);
	}






	/*void printRecorder(BSTNodePtr node) {
	if (node == NULL)
	{
	return;
	}
	printRecorder(node->left);
	printf("%ld\n", node->data);
	ListNodePtr temp = node->courses.head;
	while (temp != NULL)
	{
	printf("%s\n", temp->data);
	temp = temp->next;
	}



	printRecorder(node->right);
	}*/
