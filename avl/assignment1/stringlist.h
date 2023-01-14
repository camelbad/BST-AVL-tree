#pragma once
#include <stdio.h>

//The structure of courses that makes up the bst node
typedef struct listNode {
	char *data;//course name
	struct listNode *next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;

//**************************************************************
//Structure for storing the resuld of course statistics
typedef struct courseRec {
	char *courseName;//name of course
	long NumOfStu;//the student number of enrollment
	struct  courseRec *next;
} *courseNodePtr;

typedef struct allCourseStastic {
	courseNodePtr head;
} allCourseStastic;


//***************************************************************


List new_courselist();//Initialize the course list
void enroll_a_Course_Tostu(char *courseName, List *courseList);//enroll course
void deleteCourse(char *courseName, List *courseList);//unenroll course
showCoursesOfStu(List *courseList);//Print the entire course list for a specific student
courseNodePtr findCourse(char* course, allCourseStastic *courselist);//Determine whether the course already exists

allCourseStastic creatStasticList();//Initialize Course Statistics Linked List
insertCourseSta(char *courseName, allCourseStastic *courseList);//Course Statistics Linked List Insertion
addCourseCounter(courseNodePtr Course);//Increase course enrollment counter

void destroy_list(List *self);//free space

