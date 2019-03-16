/*****************************************
 *   Experiment 4 -- Circular Queue      *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *            File type.h                *
 *  This head file contains the type and *
 *  macro of this program.               *
 *****************************************/

#pragma once

#define ELEMENT_SIZE sizeof (Element)
#define MAXQSIZE 10		//maximun length of queue
						//the queue can only cantain MAXQSIZE-1 elements

typedef struct
{
	int id;              //patient's id
} Element,Patient;		//the data of the node

typedef struct
{
	Element *base;		//points to dynamic memory for elements
	int front;			//head pointer, it points head element
						//if queue is not empty
	int rear;			//rear pointer, it points read element
						//if queue is not empty
} CirQueue;
