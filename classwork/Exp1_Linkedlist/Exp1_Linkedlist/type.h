/*********************************************
 * Data Structure Experiment 1-- Linked List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *              file : type.h                *
 *      This head file contains the user     *
 *      defined types and the macros that    *
 *      this program needs.                  *
 *********************************************/

#pragma once

#define NODE_SIZE sizeof(Node)	//size of one node
#define ID_LEN 9				//student's id max length
#define NAME_LEN 20				//student's name max length

//ELement type
//in this program, the node's data is student's information
typedef struct
{
	char num[ID_LEN];		//Student's ID
	char name[NAME_LEN];
	int score;
} ElemType, Student;

//Node's type
//The head node of a linked list is an empty node which is convenient
//for adding or deleting nodes.
typedef struct Node
{
	ElemType data;			//data field
	struct Node *next;		//pointer field(points to the next node)
							//It will be NULL, if there is no next node.
} Node, *LinkList;