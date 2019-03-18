#include "queue.h"
#include "internalfun.h"
#include <stdlib.h>
#include <stdio.h>

//define of functions

bool InitQueue(LinkQueue * q)
{
	//initialize a new queue
	q->front = q->rear = (NodePtr)malloc (NODE_SIZE);	//make a empty node
	if (!q->front)			//fail to apply room
		exit(0);
	q->front->next = NULL;
	return true;
}

bool DestroyQueue(LinkQueue * q)
{
	//destroy an existed queue
	while (q->front)
	{
		q->rear = q->front->next;
		free (q->front);
		q->front = q->rear;
	}
	return true;
}

bool ClearQueue(LinkQueue * q)
{
	//wipe all the nodes in a queue
	DestroyQueue (q);
	InitQueue (q);
	return true;
}

int QueueLength(const LinkQueue * q)
{
	//get the length of a queue
	NodePtr p = q->front;
	int count = 0;
	while (p->next)
	{
		p = p->next;
		++count;
	}
	return count;
}

bool QueueIsEmpty(const LinkQueue * q)
{
	//decide whether the queue is emtpy
	if (q->front == q->rear)
		return true;
	return false;
}

bool GetHead(LinkQueue * q, Element * e)
{
	//get the head node's data in a queue
	if (QueueIsEmpty (q))
		return false;
	*e = q->front->next->data;
	return true;
}

bool EnQueue(LinkQueue * q, const Element * e)
{
	//insert a node into a queue(rear)
	NodePtr p = (NodePtr)malloc (NODE_SIZE);
	if (!p)
		exit(0);
	p->data = *e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return true;
}

bool DeQueue(LinkQueue * q, Element * e)
{
	//remove the head node of a queue
	NodePtr p;
	if (QueueIsEmpty (q))
		return false;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)			//there is only one node
		q->rear = q->front;
	free(p);
	return true;
}

bool QueueTraverse(LinkQueue * q, void(*visit)(Element *))
{
	//apply a function to all nodes in a queue
	NodePtr p;
	if (QueueIsEmpty (q))
		return false;
	p = q->front->next;
	while (p)
	{
		visit (&p->data);
		p = p->next;
	}
	return true;
}
