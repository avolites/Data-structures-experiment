/*****************************************
 *   DataStructures--Doubly Linked List  *
 *         Experiment program            *
 *        Developed by Sam Liu           *
 * Only for study and education purpose. *
 * The author has no responsibility      *
 *   for the errors or omissions!        *
 *****************************************/

#pragma once

#include <stdbool.h>

#define NODE_SIZE sizeof(struct Node)

struct Element
{
	int a;					//for simple purpose, it only contains a element
};
struct Node
{
	struct Element data;
	struct Node *prior;
	struct Node *next;
};
struct List
{
	struct Node *head;
	struct Node *tail;
	int length;				//the amount of nodes
							//0 empty list, -1 after being destroyed
};

typedef struct List DuLList, *DuLinkList;

//function prototypes

//operation:initialize a doubly linked list
//pre-condition:l is a pointer to an empty list
//post-condition:return true if it succeeds, false otherwise
bool InitList(DuLinkList l);

//operation:wipe all the nodes in the list
//pre-condition:l is a pointer to a list
//post-conditionn:the room of list will be freed
void DestroyList(DuLinkList l);

//operation:decide whether the list is empty
//pre-condition:l is a pointer to a list
//post-condition:return true if it is emtpy, false otherwise
bool IsEmpty(DuLinkList l);

//operation:insert a node into the list as the first node
//pre-condition:l is a pointer to a list,e is the node's data
//post-condition:return true if it succeeds, false otherwise
bool InsFirst(DuLinkList l, struct Element e);

//operation:delete the first node in the list
//pre-condition:l is a pointer to a list
//post-condition:e will carry the deleted element
//				 return true if it succeeds, false other wise
bool DelFirst(DuLinkList l, struct Element *e);

//operation:append a node into the list
//pre-condition:l is a pointer to a list,e is the node's data
//post-condition:return true if it succeeds, false otherwise
bool Append(DuLinkList l, struct Element e);

//operation:delete any node in the list
//pre-condition:l is a pointer to a list,pos is the position
//				the elements are counted from 1
//post-condition:return true if it succeeds, false otherwise
//				 e will carry the element that has been deleted
//				 and NULL if it fails
bool Remove(DuLinkList l, int pos, struct Element *e);

//operation:insert a node into the list at any position
//pre-condition:l is a pointer to a list,pos is the position
//post-condition:return true if it succeeds,false otherwise
//				 the node will be inserted before the node pos denotes
bool InsBefore(DuLinkList l, int pos,struct Element e);

//operation:insert a node into the list at any position
//pre-condition:l is a pointer to a list,pos is the position
//post-condition:return true if it succeeds,false otherwise
//				 the node will be inserted after the node pos denotes
bool InsAfter(DuLinkList l, int pos, struct Element e);

//operation:replace the data of a node
//pre-condition:l is a pointer to a list,e is the new data,pos is the position
//post-condition:return true if it succeeds, false otherwise
bool SetCurElem(DuLinkList l, int pos, struct Element e);

//operation:get the data of one node in the list
//pre-conditoin:l is a pointer to a list,pos is the position
//post-condition:e will carry the data,return true if it succeed, false otherwise
bool GetCurElem(DuLinkList l, int pos,struct Element *e);

//operation:get the data of one node in the list
//pre-conditoin:l is a pointer to a list,pos is the position
//post-condition:e will carry the data,return true if it succeed, false otherwise
bool GetElem(DuLinkList l, struct Node *pos, struct Element *e);

//operation:apply a function to every node
//pre-condition:l is a pointer to a list,fun is the function's pointer
//post-condition:return true if it succeeds, false otherwise
bool ListTraverse(DuLinkList l, void(*fun)(struct Element));

//operation:print one node's data
void PrintElem(struct Element e);

//operatoin:compare two elements
//post-conditoin:return the the value of a-b
int compare(struct Element a, struct Element b);

//operation:create a new list, first in first out
//pre-condition:l is a random pointer to a list
//post-condition:return true if it succeeds, false otherwise
bool CreateDoublyLinkedList_FIFO(DuLinkList l);

//operation:create a new list, last in first out
//pre-condition:l is a random pointer to a list
//post-condition:return true if it succeeds, false otherwise
bool CreateDoublyLinkedList_LIFO(DuLinkList l);

//operation:merge two list into one
//pre-condition:la and lb are two non-descent order list,lc is an uninitialized list
//				compare is the conditoin function
//post-condition:la lb will be destroyed
//				 return true if it succeeds, false otherwise
bool MergeList(DuLinkList la, DuLinkList lb, DuLinkList lc, int(*compare)(struct Element, struct Element));
