/*****************************************
 *   Experiment 4 -- Circular Queue      *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *            File cirqueue.h            *
 * This head file contains the function  *
 * prototypes of all the basic operations*
 * of circular queue.                    *
 *****************************************/

#pragma once

#include <stdbool.h>
#include "type.h"


//this is circular queue, the structure is just like a circle
//the last element in base will store nothing
//but mark the status of the queue(empty,full)
//if the queue is empty, front==rear
//if the queue is full, (rear+1) mod MAXQSIZE==front

//function prototypes

//operation:initialize a new queue
//pre-condition: q points to a queue
//post-condition:return true if it succeeds, false otherwise
bool InitQueue(CirQueue *q);

//operation:destroy an existed queue
//pre-condition:q points to an initialized queue
//post-condition:return true if it succeeds, false otherwise
bool DestroyQueue(CirQueue *q);

//operation:wipe all the nodes in a queue
//pre-condition:q points to an initialized queue
//post-condition:return true if it succeeds, false otherwise
bool ClearQueue(CirQueue *q);

//operation:get the length of a queue
//pre-condition:q points to an initialized queue
//post-condition:return the number of nodes in the queue
int QueueLength(const CirQueue *q);

//operation:decide whether the queue is empty
//pre-condition:q points to an initialized queue
//post-condition:return true if it is empty, false otherwise
bool QueueIsEmpty(const CirQueue *q);

//operation:decide whether the queue is full
//pre-condition:q points to an initialized queue
//post-condition:return true if it is empty, false otherwise
bool QueueIsFull(const CirQueue *q);

//operation:get the head node's data in a queue
//pre-condition:q points to an initialized queue
//post-condition:if the head node exists, return true and "e" will carry
//				 the data, otherwise return false and "e" won't be changed
bool GetHead(CirQueue *q, Element *e);

//operation:insert a node into a queue(rear)
//pre-condition:q points to an initialized queue, e is the node's data
//post-condition:return true if it succeeds, false otherwise
bool EnQueue(CirQueue *q, const Element *e);

//operation:remove the head node of a queue
//pre-condition:q points to an initialized queue
//post-condition:if it succeeds, return true and "e" will carry the
//				 deleted node's data, otherwise return false
//				 and "e" won't be changed
bool DeQueue(CirQueue *q, Element *e);

//operation:apply a function to all nodes in a queue
//pre-condition:q points to an initialized queue, visit is the function
//post-condition:return true if it succeeds, otherwise false
bool QueueTraverse(CirQueue *q, void(*visit)(Element *));


