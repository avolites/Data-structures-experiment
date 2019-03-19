#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

bool InitQueue(CirQueue * q)
{
	//initialize a new queue
	q->base = (Element *)malloc(MAXQSIZE*ELEMENT_SIZE);
	if (!q->base)				//fail to apply
		exit(0);
	q->front = q->rear = 0;
	return true;
}

bool DestroyQueue(CirQueue * q)
{
	//destroy an existed queue
	if (q->base)
	{
		free(q->base);
		return true;
	}
	return false;
}

bool ClearQueue(CirQueue * q)
{
	//wipe all the nodes in a queue
	if (q->base)
	{
		q->rear = q->front = 0;
		return true;
	}
	return false;
}

int QueueLength(const CirQueue * q)
{
	//operation:get the length of a queue
	return (q->rear - q->front + MAXQSIZE) % MAXQSIZE;
}

bool QueueIsEmpty(const CirQueue * q)
{
	//operation:decide whether the queue is emtpy
	if (q->rear == q->front)
		return true;
	return false;
}

bool QueueIsFull(const CirQueue * q)
{
	//operation:decide whether the queue is full
	if ((q->rear + 1) % MAXQSIZE == q->front)
		return true;
	return false;
}

bool GetHead(CirQueue * q, Element * e)
{
	//operation:get the head node's data in a queue
	if (!QueueIsEmpty(q))
	{
		*e = q->base[q->front];
		return true;
	}
	return false;
}

bool EnQueue(CirQueue * q, const Element * e)
{
	//operation:insert a node into a queue(rear)
	if (QueueIsFull(q))
		return false;
	q->base[q->rear] = *e;
	q->rear = (q->rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(CirQueue * q, Element * e)
{
	//operation:remove the head node of a queue
	if (QueueIsEmpty(q))
		return false;
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXQSIZE;
	return true;
}

bool QueueTraverse(CirQueue * q, void(*visit)(Element *))
{
	//operation:apply a function to all nodes in a queue
	if (QueueIsEmpty(q))
		return false;
	int ip = q->front;
	Element *p = q->base + q->front;
	while (p != q->base + q->rear)
	{
		visit(p);
		ip = (ip + 1) % MAXQSIZE;
		p = q->base + ip;
	}
	return true;
}

void PrintELem(const Element * e)
{
	printf("%d ", e->a);
}