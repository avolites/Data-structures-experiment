#include "internalfun.h"
#include "queue.h"
#include <stdio.h>

void PrintELem(Element * e)
{
	printf("%d\n",e->id);
}

bool Check(LinkQueue *q, Patient e)
{
    //operation: check whether the new data is legal
    if(!QueueIsEmpty(q))
    {
        NodePtr p;
        p = q->front->next;
        while (p)
        {
            if(p->data.id==e.id)
                return false;
            p = p->next;
        }
    }
	return true;
}

bool WaitInLine(LinkQueue *q, Patient e)
{
    //operation: new patient comes, wait in the line(EnQueue)
    if(EnQueue(q, &e))
        return true;
    return false;
}

bool Treatment(LinkQueue *q, Patient *e)
{
    //operation: a patient in line gets treatment(DeQueue)
    if(DeQueue(q, e))
        return true;
    return false;
}
