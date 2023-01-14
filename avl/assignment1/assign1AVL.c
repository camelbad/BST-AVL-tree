#include "ASSIGN1AVL.H"
#include <stdio.h>
#include <stdlib.h> 



void addStudent(long id, AVL * recorder)//add student
{
	recorder->root = insert_avl_node(recorder->root, id);
}


void deleteStu(long id, AVL *recorder)//delete student
{
	AVLNodePtr targetNode = find_avl_node(recorder->root, id);
	recorder->root = delete_avl_node(recorder->root, targetNode);

}

void addCourseToStu(char *courseName, long id, AVL *recorder)//enroll course
{
	
	AVLNodePtr a=searchById(recorder,id);//locate student by id

	enroll_a_Course_Tostu(courseName, &a->courses);//enroll a course to a student
}



void delCourse(char *courseName, long id, AVL *recorder)//delete course
{
	AVLNodePtr a = searchById(recorder, id);//locate student
	deleteCourse(courseName, &a->courses);//delete course

}



outputCourseSta(allCourseStastic *result)//print the student number of certain courses
{
	courseNodePtr temp;
	temp = result->head;//get the head pointer of the static result
	while (temp != NULL)
	{
		printf("%s ", temp->courseName);//display course name
		printf("%d\n", temp->NumOfStu);//display student number
		temp = temp->next;//move pointer to next
	}
}

void displayStuListOfCourse(char *courseName, AVLNodePtr recorderRoot)//ger the student number of certain course
{

	if (recorderRoot == NULL)//quit if Null
	{
		return ;
	}
	displayStuListOfCourse(courseName, recorderRoot->left);//Recursively in order, traverse each node
	ListNodePtr coursePtr = recorderRoot->courses.head;//For each node, get the head of the course list
	while (coursePtr != NULL)
	{
		if (strcmp(coursePtr->data, courseName) == 0)//If this student registers this course
		{
			printf("%ld\n", recorderRoot->data);//Print student names
		}
		
		coursePtr = coursePtr->next;//move pointer to next
	}

	displayStuListOfCourse(courseName, recorderRoot->right);

}

void displayCoursesOfStu(long id, AVL *recorder)//Shows all courses registered for a particular student
{
	AVLNodePtr result= find_avl_node(recorder->root, id);//Target students, based on ID
	ListNodePtr course = result->courses.head;//Get the head address of the course link list
	while (course != NULL)
	{
		printf("%s\n",course->data);//Print Course
		course = course->next;//move pointer to next
	}
}








/**********************************************************************************************************************************************************************************************************************************************************************/

void main()
{
	int userselect=0;//User selection f
	long stuId;//student ID
	AVL *recorder= creatNewAVL();//initializing BST tree for recorder
	char *courseName;//course name
	printf("Student Registration Information System\n");
	printf("\n\n\n");
	printf("0. Quit\n");
	printf("1. Add a student\n");
	printf("2. Remove a student\n");
	printf("3. Enrol student in a course\n");
	printf("4. Un-enrol student from a course\n");
	printf("5. Print a summary of courses and the number of students enrolled in each course\n");
	printf("6. Print an ordered list of students enrolled in a course\n");
	printf("7. Print a list of courses that a given student is enrolled in\n");
	
	
	
	//get user input
	
	
	
	
	do
	
	{
		printf("Pleast input a number from 1~8\n");
		scanf("%d", &userselect);//Get which function the user chooses
		switch (userselect)
		{
		case 1:
			printf("Please input the student ID which you want to add\n");
			scanf("%ld", &stuId);//Get the student ID  want to add
			
				addStudent(stuId, recorder);
		
			break;
		case 2:
			printf("Please input the student ID which you want to delete\n");
			scanf("%ld", &stuId);//Get the student ID that needs to be deleted
			deleteStu(stuId, recorder);
			break;
		case 3:
			printf("Please input the student ID and the course you want to enrol for that studet\n");
			printf("Please input the student ID \n");
			scanf("%ld", &stuId);//Get the student ID 
			printf("Please input the course name\n");
			char* courseName = (char*)malloc(sizeof(char) * 100);
			scanf("%s", courseName);//get course name
			addCourseToStu(courseName, stuId, recorder);
			break;
		case 4:
			printf("Please input the student ID and the course you want to delete for that studet\n");
			printf("Please input the student ID \n");
			scanf("%ld", &stuId);//Get the student ID  want to add
			printf("Please input the course name\n");
			char* courseName2 = (char*)malloc(sizeof(char) * 100);
			scanf("%s", courseName2);//get course name
			delCourse(courseName2, stuId, recorder);
			break;
		case 5:
			printf("Print a summary of courses and the number of students enrolled in each course\n");
			allCourseStastic courselist= creatStasticList();//Initialize a new linked list to store course statistics
			outputCourseSta(displayInfo(recorder->root,&courselist));//Get course statistics result and display
			
			break;
		case 6:
			printf(" Print an ordered list of students enrolled in a course\n");
			printf(" please in put a course name\n");
			scanf("%s", courseName);//Get the course name
			displayStuListOfCourse(courseName, recorder->root);
			break;
		case 7:
			printf(" Print a list of courses that a given student is enrolled in\n");
			printf(" Please input a student ID\n");
			scanf("%ld", &stuId);//Get student ID
			printf("Enrolment for %ld\n",stuId);
			displayCoursesOfStu(stuId, recorder);
			break;
		case 0:
			printf(" Quit\n");
			destory(recorder->root);//Free space
			exit(0);
			break;


		default:
			printf(" Wrong input, please input int Number 1~8\n");
			break;
		}

	} while (userselect != 0);//When the user selects 0 then exit.
		
}