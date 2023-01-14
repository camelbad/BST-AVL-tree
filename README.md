# BST-AVL-tree
the University has had recent experience in running courses online.  This presents an opportunity to expand online courses to become MOOC (Massive Open Online Course) with many thousands of students enrolled in each unit.  This has the potential to create performance issues for the student record system.

Your task is to develop and evaluate a prototype system to test different data structure options for the student database.

The student database must support the following operations:

Add student

Remove student

Enrol student in a unit

Unenrol student from a unit

Print an ordered summary of units and the number of students enrolled in each unit

Print an ordered list of students enrolled in a specific unit

Print an ordered list of units that a specific student is enrolled in

 
requirements：

uses a binary search tree to store students  with each bst node containing the student id as the sorting key, and an alphabetically ordered linked list of units that the student is enrolled in.  

uses a AVL tree to store students
////////////////////////////////////////////////////////////////////

Program I/O

All interactions with the program will be via the console. Operations 1-7 will be selected by typing 1-7 at the command prompt. Quitting the application will be selected by typing 0. For example, the following input sequence would add a student with id "123456", and then enrol that student in the unit “cc235”, and then quit the application:

1

123456

3

123456

cc235

0


Note that this sequence shows the input only, not the program response (if any). You are free to add prompts to make the application more user friendly.  

Program output in response to operations 5-7, should be as minimal as possible. You may print a header if you wish, but this should be followed by one record per line with spaces separating data.  For example, in response to operation 5, the output might be:

Unit enrolments:

abc123 32 

logistics 13

chemistry 10236


Note: for operation 5, you should not print any units that have zero enrolments.

I/O Restrictions

You may assume that input will always be in the correct format and contain no logical errors.

Commands will always be in the range 0-7

Unit names will always be strings less than 100 characters long and may contain any alpha-numeric characters (no spaces)

Student ids will always be positive integers in the range 0-999999

The user will never attempt to enrol a non-existent student in a unit

The user will never attempt to print data for a non-existent student or unit

The user will never attempt to remove non-existent students

The user will never attempt to unenrol a student from a unit that they are not enrolled in

Memory Management

Unit names should be stored in appropriately size dynamically allocated memory.  Names will always be less than 100 characters long.  For example, the course name “abc123” would be stored in a char string of length 7.

Removing  a unit should free all associated dynamically allocated memory, including memory for the students that are currently enrolled. The quit function should also free all dynamically allocated memory.

