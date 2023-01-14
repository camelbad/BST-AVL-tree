#pragma once
#include <stdio.h>
#include "bst.h"
#include "stringlist.h"


void addStudent(long id, BST * recorder);
void deleteStu(long id, BST *recorder);
void addCourseToStu(char *courseName, long id, BST *recorder);
void delCourse(char *courseName, long id, BST *recorder);
outputCourseSta(allCourseStastic *result);
void displayStuListOfCourse(char *courseName, BSTNodePtr recorderRoot);
void displayCoursesOfStu(long id, BST *recorder);



