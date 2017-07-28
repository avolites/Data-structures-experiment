/*****************************************
 *     DataStructures--Linked list       *
 *         Experiment program            *
 *        Developed by Sam Liu           *
 *           Not original!!!             *
 * Only for study and education purpose. *
 * The author has no responsibility      *
 *   for the errors or omissions!        *
 *****************************************/
 
#ifndef _LINKED_LIST_HEAD_
#define _LINKED_LIST_HEAD_

#define NODE_SIZE sizeof(struct Node)
 
struct Element{
	int a;
};				//for convenience, it only has one element
struct Node{
 	struct Element data;
 	struct Node *next;
};

typedef struct Node Lilist;

//function prototypes

//operation:insert a node into the list
//pre-condition:l is a pointer to pointer to Lilist,e is the element you want
//				 to insert, i is the location you want to insert
//post-condition:return true if it succeeds, false otherwise. the new node
//				  will be in the location i.
bool InsertNode(Lilist **l,int i,struct Element e);

//operation:delete a node in the list
//pre-condition:l is a pointer to pointer to Lilist,i is the location of the 
//				 node you want to delete, e will carry the node that will be deleted
//post-condtiion:return true if it succeeds, false otherwise.
bool DeleteNode(Lilist **l,int i,struct Element *e);

//operation:clear a linked list
//pre-condition:l is a pointer to Lilist
//post-condtioin:l will become empty, all the nodes will be freed
void ClearList(Lilist *l);

//operation:output all the nodes in the linked list
//pre-condition:l is a pointer to Lilist
//post-condition:the linked list will be the same condition
void DisplayList(Lilist *l);

//operation:get one node's data in a linked list
//pre-condition:l is a pointer to Lilist,i is the node's location, e will 
//				carry the objective data
//post-condtiion:return true if it succeeds, false otherwise
bool GetData(Lilist *l,int i, struct Element *e);

//operation:create a linked list(first in first out)
//pre-condition: l is a pointer to pointer to Lilist,
//post-condition:return true if it succeeds, false otherwise
bool CreateList_FIFO(Lilist **l);

//operation:create a linked list(last in first out)
//pre-condition: l is a pointer to pointer to Lilist,
//post-condition:return true if it succeeds, false otherwise
bool CreateList_LIFO(Lilist **l);
#endif	//_LINKED_LIST_HEAD_
