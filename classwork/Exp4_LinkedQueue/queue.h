/*****************************************
 *   Experiment 4 -- Linked Queue        *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *            File queue.h               *
 * This head file contains the function  *
 * prototypes of all the basic operations*
 * of linked queue.                      *
 *****************************************/

#pragma once

#include <stdbool.h>
#include "type.h"

//function prototypes

//operatoin:initialize a new queue
//pre-condition: q points to a queue
//post-condtiion:return true if it succeeds, false otherwise
bool InitQueue(LinkQueue *q);

//operation:destroy an existed queue
//pre-condition:q points to an initialized queue
//post-condition:return true if it succeeds, false otherwise
bool DestroyQueue(LinkQueue *q);

//operation:wipe all the nodes in a queue
//pre-condition:q points to an initialized queue
//post-condition:return true if it succeeds, false otherwise
bool ClearQueue(LinkQueue *q);

//operation:get the length of a queue
//pre-condition:q points to an initialized queue
//post-condition:return the number of nodes in the queue
int QueueLength(const LinkQueue *q);

//operation:decide whether the queue is emtpy
//pre-condition:q points to an initialized queue
//post-condition:return true if it is emtpy, false otherwise
bool QueueIsEmpty(const LinkQueue *q);

//operation:get the head node's data in a queue
//pre-condition:q points to an initialized queue
//post-condition:if the head node exists, return true and "e" will carry
//				 the data, otherwise return false and "e" won't be changed
bool GetHead(LinkQueue *q, Element *e);

//operation:insert a node into a queue(rear)
//pre-condition:q points to an initialized queue, e is the node's data
//post-condition:return true if it succeeds, false otherwise
bool EnQueue(LinkQueue *q, const Element *e);

//operation:remove the head node of a queue
//pre-condition:q points to an initialized queue
//post-condition:if it succeeds, return true and "e" will carry the
//				 deleted node's data, otherwise return false
//				 and "e" won't be changed
bool DeQueue(LinkQueue *q, Element *e);

//operation:apply a function to all nodes in a queue
//pre-condition:q points to an initialized queue, visit is the function
//post-condition:return true if it succeeds, otherwise false
bool QueueTraverse(LinkQueue *q, void(*visit)(Element *));
