/*********************************************
 * Data Structure Experiment 1-- Linear List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *           file : internalfun.h            *
 *     This head file contains all the       *
 *     prototype of functions that are       *
 *     related to the struct type Student.   *
 *     These functions can be different for  *
 *     different data type of linked list.   *
 *********************************************/

#pragma once

#include "type.h"
#include <stdbool.h>
#include <stdio.h>

 //operation:copy one node to another
 //pre-condition:e1 points to a node, e1 points to another node
 //post-condition:copy e2 to e1
void CopyNode(struct Node *e1, struct Node *e2);

//operation:decide if the two elements are equal
//pre-condition:e1 and e2 are two nodes of the list
//post-condition:return TRUE if they are equal, otherwise FALSE
bool IfNodesEqual(const struct Node *e1, const struct Node *e2);

//operation:decide if the first element is bigger than the latter one
//pre-condition:e1 and e2 point two nodes respectively in the list
//post-condition:return TRUE if former one is bigger than latter one
//				 return FALSE otherwise
bool IfBigger(const struct Node *e1, const struct Node *e2);

//operation:decide if the fist element is smaller than the latter one
//pre-condition:e1 and e2 point two nodes resepctively in the list
//poot-condition:return TRUE if the former one is bigger than the latter one
//				 return FALSE otherwise
bool IfSmaller(const struct Node *e1, const struct Node *e2);

//operation: to input a string safely
//pre-condition: it only for char array string, n is array's length
char* my_gets(char*ar, int n);

//operation:display the node
//pre-condition:e points to a node
//post-condition:display e
void Display(struct Node *e);

//operation: print the table head
void PrintTableHead();

//operation: print all the students' data who have the same name
//pre-condition: l is the linear list
void SearchbyName(SqList l, char *name);

//operation: search a student by ID
//pre-condition: l is the linear list
//post-conditoin: return true if the ID exists, false otherwise
bool SearchbyID(SqList l, char *id);

//operation: input a student's information
void InputStudent(Node *e);