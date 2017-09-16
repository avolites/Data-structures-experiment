#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

//definition of public function

bool GetElem(LinkList l, int i, ElemType * e)
{
	//get a node's data in a linked list
	Node *p = l->next;		//the first node
	int j = 1;
	while (p&&j < i)		//serch backwardly, until p is NULL
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)		//i is illegal(<1 or >length)
		return false;
	*e = p->data;			//fetch the data
	return true;
}

bool ListInsert(LinkList l, int i, ElemType e)
{
	//insert a node that contains data into a linked list
	Node *p = l;			//points the node prior to the inserted node
	int j = 0;
	while (p&&j < i - 1)	//serch the i-1 node
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)	//i is illegal(<1 or >length+1)
		return false;
	Node *s = (Node *)malloc(NODE_SIZE);	//generate a new node
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete(LinkList l, int i, ElemType * e)
{
	//delete a node in a linked list
	Node *p = l;				//p is the prior node of node i
	Node *q;					//q is the node that will be deleted
	int j = 0;
	while (p->next&&j < i - 1)	//search the node i, and p points its prior
	{
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1)	//i is illegal
		return false;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}

void CreateList_Inverse(LinkList * l, int n)
{
	//create a linked list in a inverse order
	Node *p;							//temporary node
	*l = (LinkList)malloc(NODE_SIZE);	//create a head node
	(*l)->next = NULL;
	for (int i = n; i > 0; --i)
	{
		p = (Node *)malloc(NODE_SIZE);	//generate a new node
		Input(&p);						//input the data
		p->next = (*l)->next;			//insert the node to fist
		(*l)->next = p;
	}
}

void CreateList_Sequence(LinkList * l, int n)
{
	//create a linked list in a inverse order
	Node *p;							//temporary node
	Node *last;							//last node
	*l = (LinkList)malloc(NODE_SIZE);	//create a head node
	(*l)->next = NULL;
	last = *l;
	for (int i = n; i > 0; --i)
	{
		p = (Node *)malloc(NODE_SIZE);	//generate a new node
		Input(&p);						//input the data
		p->next = NULL;			//insert the node to last
		last->next = p;
		last = p;
	}
}

//definition of private function

void MergeList(LinkList * la, LinkList * lb, LinkList * lc)
{
	//merge two lists into one
	Node *pa = (*la)->next;
	Node *pb = (*lb)->next;
	Node *pc = (*lc) = (*la);	//lc's head node is la's node
	while (pa&&pb)
	{
		if (pa->data.a <= pb->data.a)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(*lb);
}

bool ListIsEmpty(LinkList l)
{
	//decide whether the list is empty
	if (l->next)
		return false;
	return true;
}

int ListLength(LinkList l)
{
	//count the number of elements in the list
	int count = 0;
	Node *s = l->next;
	while (s)
	{
		s = s->next;
		count++;
	}
	return count;
}

void DestroyList(LinkList l)
{
	//destroy a linked list
	Node *s = l;
	while (s)
	{
		s = s->next;
		free(l);
		l = s;
	}
}

void ClearList(LinkList l)
{
	//wipe all the elements in a linked list
	Node *s = l->next, *p;
	while (s)
	{
		p = s->next;
		free(s);
		s = p;
	}
	l->next = NULL;
}

void PrintList(LinkList l)
{
	//print all the elements in the list
	Node *s = l->next;
	while (s)
	{
		printf("%d ",s->data.a);
		s = s->next;
	}
}

static void Input(Node ** n)
{
	//to let the user input the data of the node
	scanf("%d", &(*n)->data.a);
}
