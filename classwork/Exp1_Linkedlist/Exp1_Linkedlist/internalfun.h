/*********************************************
 * Data Structure Experiment 1-- Linked List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *         file : internalfun.h              *
 *     This head file contains all the       *
 *     prototype of functions that are       *
 *     related to the struct type Student.   *
 *     These functions can be different for  *
 *     different data type of linked list.   *
 *********************************************/

#pragma once

#include "type.h"
#include <stdbool.h>

//prototype of functions

//operation: to input a string safely
//pre-condition: it only for char array string, n is array's length
char* my_gets(char*ar, int n);

//operation: to print a node's data
void PrintNode(ElemType e);

//operation: acquire all the data for one node
void InputData(Node *e);

//operation: compare the data of two nodes, to decide who is greater
//pre-condition: a and b are two Node's data field
//post-condition: return true if a<=b
bool IsLess(ElemType a, ElemType b);

//operation: search a node base on student's name
//pre-condition: l points to a linked list with a head node(empty node)
//				 name is the student's name that user wants to seach
//post-condition: return the student's information(data's address) if the 
//				  student exists, NULL otherwise 
ElemType * SearchStudent_Name(LinkList l, char * name);

//operation: search a node base on student's ID
//pre-condition: l points to a linked list with a head node(empty node)
//				 name is the student's name that user wants to seach
//post-condition: return the student's information(data's address) if the 
//				  student exists, NULL otherwise 
ElemType * SearchStudent_ID(LinkList l, char * id);

//operation: search all the students who have the same name
//pre-condition: l points to a linked list with a head node(empty node)
//				 name is the student's name that user wants to search
//post-condition: print all the matched students' information
void SearchStudentAndPrint(LinkList l, char * name);

//operation: to compare whether two students' id are equal
//post-condition: return true if so, otherwise false
bool CompareStudentId(ElemType a, ElemType b);

//operation: print error message
void PrintErr();
