/*****************************************
*     DataStructures--Linked List       *
*         Experiment program            *
*        Developed by Sam Liu           *
* Only for study and education purpose. *
*   The author has no responsibility    *
*     for the errors or omissions!      *
*****************************************/

#pragma once

#include <stdbool.h>

#define NODE_SIZE sizeof(Node)

//ELement type, for simple reason, it only contain one integer
typedef struct
{
	int a;
} ElemType;

//Node's type
//The head node of a linked list is an empty node which is convenient
//for adding or deleting nodes.
typedef struct Node
{
	ElemType data;			//data field
	struct Node *next;		//pointer field(points to the next node)
							//it will be NULL, if there is no next node
} Node, *LinkList;

//public function prototype

//operation:get a node's data in a linked list
//pre-condition: l points to a linked list with a head node(empty node)
//				 i is the location of the node(the first node is 1)
//post-condition: if it succeeds, return true and e will carry the data
//				  otherwise return false
bool GetElem(LinkList l, int i, ElemType *e);

//operation:insert a node that contains data into a linked list
//pre-condition: l points to a linked list with a head node(empty node)
//				 it will insert the node prior to location i
//				 e is the data of the new node
//post-condition: return true and the length of list will be increased by 1
//				  if it succeeds, return false otherwise
bool ListInsert(LinkList l, int i, ElemType e);

//operation: delete a node in a linked list
//pre-condition: l points to a linked list with a head node(empty node)
//				 i is the location of node that will be deleted
//post-condition: if it succeeds, return true and e will carry the 
//				  data of deleted node, otherwise return false
bool ListDelete(LinkList l, int i, ElemType *e);

//operatoin: create a linked list in a inverse order
//pre-conditoin: l points to a pointer to a linked list(to a plain word, node)
//				 n is the number of the the node that user wanna create
//post-conditoin: a linked list will be created
void CreateList_Inverse(LinkList *l, int n);

//operation: create a linked list in a sequence order
//pre-conditoin: l points to a pointer to a linked list(to a plain word, node)
//				 n is the number of the the node that user wanna create
//post-conditoin: a linked list will be created
void CreateList_Sequence(LinkList *l, int n);

//operation: merge two lists into one
//pre-conditoin: la,lb,lc are three pointers to pointer to linked list
//				 la lb and lc are in non-decrement sequence
//post-condition:lc is the result,la will equal to lc, lb no longer exists
void MergeList(LinkList *la, LinkList *lb, LinkList *lc);

//operation: decide whether the list is empty
//pre-condtion: l is a linked list
//post-condtion: return true if it is empty, false otherwise
bool ListIsEmpty(LinkList l);

//operation: count the number of elements in the list
//pre-condition:l is a linked list
//post-condition: return the number of elements
int ListLength(LinkList l);

//operation: destroy a linked list
//pre-condition: l is a linked list
//post-condtion: l will no longer exist
void DestroyList(LinkList l);

//operation: wipe all the elements in a linked list
//pre-condition: l is a linked list
//post-condition: all the elements will be wiped, the list still exists
void ClearList(LinkList l);

//operation: print all the elements in the list
//pre-conditoin: l is a linked list
//post-condtion: nothing will be changed
void PrintList(LinkList l);

//private function prototype

//operation: to let the user input the data of the node
static void Input(Node **n);
