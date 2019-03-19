/*****************************************
*   DataStructures--Circular Queue      *
*         Experiment program            *
*        Developed by Sam Liu           *
* Only for study and education purpose. *
*   The author has no responsibility    *
*     for the errors or omissions!      *
*****************************************/

#pragma once

#include "type_mgraph.h"

#define ELEMENT_SIZE sizeof (Element)
#define MAXQSIZE MAX_VERTEX_NUM		//maximun length of queue
//the queue can only cantain MAXQSIZE-1 elements

typedef struct
{
	int32_t a;
} Element;				//the data of the node

typedef struct
{
	Element *base;		//points to dynamic memory for elements
	int front;			//head pointer, it points head element
						//if queue is not empty
	int rear;			//rear pointer, it points read element
						//if queue is not empty
} CirQueue;