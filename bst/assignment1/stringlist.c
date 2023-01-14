#include "STRINGLIST.H"
#include <string.h>
#include "bst.h"

List new_courselist()/*Initialize the course list*/
{
		List temp;
		temp.head = NULL;//set Head pointer to null
		return temp;
}



void enroll_a_Course_Tostu(char *courseName, List *courseList)//Registration Course, Insertion of List
{
	ListNodePtr new_course = malloc(sizeof *new_course);//Get new nodes and allocate space
	new_course->data =courseName ;//Assign the new the new course name to the node's data field 
	//Head insertion
	new_course->next = courseList->head;//Put new node before the original head node
	courseList->head = new_course;//Point the head node to the new node	
}

void deleteCourse(char *courseName, List* course)//unenroll course
{
	ListNodePtr current = course->head;//Current pointer
	ListNodePtr prev = NULL;//Previous position pointer

	while (current != NULL)
	{
		if (strcmp (current->data, courseName) ==0)//When the current node's course content matches the  course
		{
			if (prev == NULL) {          // front of list
				course->head = current->next;
				free(current);//free node
				current = course->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {//If the current node does not meet the requirements, move the pointer to next
			prev = current;
			current = current->next;
		}
	}

}

showCoursesOfStu(List *courseList)//display all courses for certain student
{
	ListNodePtr current = courseList->head;
	while (current->next!=NULL)
	{
		printf("%s \n", current->data);
		current = current->next;
	}
}

courseNodePtr findCourse(char* course, allCourseStastic *courselist)//Determine wether the course exists and return the course pointer if it exists

{
	courseNodePtr temp = courselist->head;
	while (temp != NULL && strcmp(temp->courseName, course) != 0)//If not
	{

		temp = temp->next;//move pointer to next
	}

	return temp;

}



allCourseStastic creatStasticList()//Initialize Course Statistics Linked List
{
	allCourseStastic temp;
	temp.head = NULL;
	return temp;
}

insertCourseSta(char *courseName, allCourseStastic *courseList)//Course Statistics Linked List Insertion
{
	courseNodePtr current = courseList->head;
	courseNodePtr prev = NULL;
	//creat new node
	courseNodePtr new_node = malloc(sizeof *new_node);
	new_node->courseName = courseName;
	new_node->NumOfStu = 1;//The initial value is 1
	new_node->next = NULL;
	//

	while (current != NULL && strcmp(current->courseName, courseName)<0)
	{
		prev = current;
		current = current->next;
	}

	if (current == courseList->head)
	{ // at front
		new_node->next = current;
		courseList->head = new_node;
	}
	else
	{                     // middle
		new_node->next = current;
		prev->next = new_node;
	}

}

addCourseCounter(courseNodePtr Course)//Course counter plus one
{
	Course->NumOfStu = Course->NumOfStu + 1;
}



void destroy_list(List *self)//Destroy the linked list
{
	ListNodePtr current = self->head;
	while (current != NULL)
	{
		ListNodePtr to_free = current;//Assign the value of the current pointer to the node will be release
		current = current->next;//move pointer to next
		free(to_free);//free space
	}
	self->head = NULL;
}


