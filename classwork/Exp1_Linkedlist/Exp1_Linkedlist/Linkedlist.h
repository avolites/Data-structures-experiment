/*********************************************
 * Data Structure Experiment 1-- Linked List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *         file : Linkedlist.h               *
 *    This head file contains the basic      *
 *    operation function prototype of a      *
 *    linked  list.   Theses  are  the       *
 *    universal operations on linked list.   *
 *********************************************/

#pragma once

#include "internalfun.h"

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
static void Input(Node *n);

//operation: check whether the data inputed by user is correct
//			 if so, the node could be created.
//pre-condition: l is the linked list that is creating, e is the data
//				 that will be checked
//post-condition: return true if it is correct
static bool Check(LinkList l, ElemType e);

//operation: print error message
static void PrintErrorMsg();