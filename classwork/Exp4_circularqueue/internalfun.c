#include "internalfun.h"
#include <stdio.h>

void PrintELem(Element * e)
{
    //operation:print a node's data
	printf("%d\n", e->id);
}

bool Check(CirQueue *q, Patient e)
{
    //operation: check whether the new data is legal
    if(!QueueIsEmpty(q))
    {
        int ip = q->front;
        Element *p = q->base + ip;
        while (p != q->base + q->rear)
        {
            if(p->id==e.id)
                return false;
            ip = (ip + 1) % MAXQSIZE;
            p = q->base + ip;
        }
    }
	return true;
}

bool WaitInLine(CirQueue *q, Patient e)
{
    //operation: new patient comes, wait in the line(EnQueue)
    if(EnQueue(q, &e))
        return true;
    return false;
}

bool Treatment(CirQueue *q, Patient *e)
{
    //operation: a patient in line gets treatment(DeQueue)
    if(DeQueue(q, e))
        return true;
    return false;
}
