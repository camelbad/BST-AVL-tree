#include "AVL.h"

int max(int a ,int b)
{
	int c;
	if (a > b)
		c = a;
	else
		c = b;
	return c; 
}

int hight(AVLNodePtr avltreeRoot)
{
	return avltreeRoot->height;
}


AVL*  creatNewAVL( )//Initialize the bst tree
{
	AVL *recorder= (AVL*)malloc(sizeof (AVL));//Allocation space

	
	recorder->root= NULL;//Root node is set to empty
	
	return recorder;
}

int avltree_height(AVL tree)
 {
	int height = 0;
	if (tree.root == NULL)
	{
		height = -1;
	}
	else
	{
		height = tree.root->height;
	}
	return height;
 }

AVLNodePtr min_node(AVLNodePtr self) //Finding the smallest node
{
	AVLNodePtr current = self;
	while (current->left != NULL)//When the last node is not reached
	{
		current = current->left;//left
	}
	return current;
}


//LL：


AVLNodePtr left_left_rotation(AVLNodePtr k2root)
 {
    AVL k1;

    k1.root = k2root->left;
    k2root->left = k1.root->right;
    k1.root->right = k2root;

    k2root->height = max(hight(k2root->left), hight(k2root->right)) + 1;
    k1.root->height = max(hight(k1.root->left), k2root->height) + 1;

     return k1.root;
 }

//RR
 AVLNodePtr right_right_rotation(AVLNodePtr k1root)
     {
	 AVL k2;

     k2.root = k1root->right;
     k1root->right = k2.root->left;
     k2.root->left = k1root;
	 k1root->height = max(hight(k1root->left), hight(k1root->right)) + 1;
	 k2.root->height = max(hight(k2.root->right), k1root->height) + 1;

	     return k2.root;
	 }

 //LR

	 AVLNodePtr left_right_rotation(AVLNodePtr k3root)
	  {
	    k3root->left = right_right_rotation(k3root->left);
	
        return left_left_rotation(k3root);
	  }
 
// * RL
	 AVLNodePtr right_left_rotation(AVLNodePtr k1root)
	 {
		 k1root->right = left_left_rotation(k1root->right);

		 return right_right_rotation(k1root);

	 }



	 //  
	 AVLNodePtr avltree_create_node(int key, AVLNodePtr *left, AVLNodePtr* right)
	 {
		 AVLNodePtr p;

		 if ((p = (AVLNodePtr *)malloc(sizeof(AVLNodePtr))) == NULL)
			 return NULL;
		 p->data = key;
		 p->courses = new_courselist();
		 p->height = 0;
		 p->left = left;
		 p->right = right;
		 return p;
	 }

	 AVLNodePtr avltree_maximum(AVLNodePtr treeroot)
		{
		    if (treeroot == NULL)
			        return NULL;
		
			    while (treeroot->right != NULL)
			       treeroot = treeroot->right;
	    return treeroot;
		}




AVLNodePtr delete_avl_node(AVLNodePtr treeroot, AVLNodePtr targetNode)//Delete node
{
	
	 if (treeroot == NULL || targetNode == NULL)
	 return NULL;
     if (targetNode->data < treeroot->data)        // The node need to be deleted is in "tree's left subtree"
	    {
	         treeroot->left = delete_avl_node(treeroot->left, targetNode);
	        // After the node is deleted, if the AVL tree loses its balance, adjust it accordingly.
	         if (hight(treeroot->right) - hight(treeroot->left) == 2)
	         {
		            AVLNodePtr r = treeroot->right;
		             if (hight(r->left) > hight(r->right))
		                 treeroot = right_left_rotation(treeroot);
		            else
			                 treeroot = right_right_rotation(treeroot);
			 }
	    }
	  else if (targetNode->data > treeroot->data)// The node to be deleted is in the "tree's right subtree"
		     {
		        treeroot->right = delete_avl_node(treeroot->right, targetNode);
		        // After the node is deleted, if the AVL tree loses its balance, adjust it accordingly.
		        if (hight(treeroot->left) - hight(treeroot->right) == 2)
			        {
			             AVLNodePtr l = treeroot->left;
		             if (hight(l->right) > hight(l->left))
			                 treeroot = left_right_rotation(treeroot);
			           else
			                treeroot = left_left_rotation(treeroot);
		            }
		    }
     else    // 
		     {
		        //The children of the tree are not empty
		        if ((treeroot->left) && (treeroot->right))
		        {
		            if (hight(treeroot->left) > hight(treeroot->right))
		            {
		                // If the tree's left subtree is higher than the right subtree;
				    AVLNodePtr max = avltree_maximum(treeroot->left);
	                treeroot->data = max->data;
		            treeroot->left = delete_avl_node(treeroot->left, max);
		             }
			      else
			         {
		                // If the tree's left subtree is not taller than the right subtree (that is, they are equal, or the right subtree is 1 higher than the left subtree)
			           AVLNodePtr min = avltree_maximum(treeroot->right);
	                   treeroot->data = min->data;
		               treeroot->right = delete_avl_node(treeroot->right, min);
		             }
		       }
		    else
		      {
		            AVLNodePtr tmp = treeroot;
		            treeroot = treeroot->left ? treeroot->left : treeroot->right;
		            free(tmp);
		        }
		     }
		
		   return treeroot;
		}


AVLNodePtr find_avl_node(AVLNodePtr self, long n)//Find node
{
	if (self == NULL || (n == self->data)) {//Restrictions
		return self;
	}
	else if (n < self->data) {//Recursively traverses the entire tree
		return find_avl_node(self->left, n);
	}
	else {
		return find_avl_node(self->right, n);
	}
}

AVLNodePtr searchById(AVL *recorder, long n) {
	return find_avl_node(recorder->root, n);
}

AVLNodePtr insert_avl_node(AVLNodePtr rootnode, long id)//Insert node
{

	
		     if (rootnode == NULL)
			     {
			       
				         rootnode = avltree_create_node(id, NULL, NULL);
			         if (rootnode == NULL)
				        {
				             printf("ERROR: create avltree node failed!\n");
				             return NULL;
				         }
			     }
		     else if (id < rootnode->data) // The key should be inserted into the "tree's left subtree"
			     {
			         rootnode->left = insert_avl_node(rootnode->left, id);
			         // After inserting the node, if the AVL tree loses its balance, adjust accordingly.
				         if (hight(rootnode->left) - hight(rootnode->right) == 2)
				         {
				             if (id < rootnode->left->data)
					                 rootnode = left_left_rotation(rootnode);
				             else
					                 rootnode = left_right_rotation(rootnode);
				         }
			     }
		     else if (id > rootnode->data) // The key should be inserted into the "tree's right subtree"
			     {
			        rootnode->right = insert_avl_node(rootnode->right, id);
			       // After inserting the node, if the AVL tree loses its balance, adjust accordingly.
				         if (hight(rootnode->right) - hight(rootnode->left) == 2)
				         {
				             if (id > rootnode->right->data)
					                 rootnode = right_right_rotation(rootnode);
				             else
					                 rootnode = right_left_rotation(rootnode);
				         }
			     }
		     else //key == tree->key)
			     {
			         printf("fail \n");
			     }
		
			     rootnode->height = max(hight(rootnode->left), hight(rootnode->right)) + 1;
		
			     return rootnode;
		
}






	allCourseStastic* displayInfo(AVLNodePtr recorderRoot, allCourseStastic *courselist)//Get course statistics
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


	void destory(AVLNodePtr recorderRoot)//delete tree
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
