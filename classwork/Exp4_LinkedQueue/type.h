/*****************************************
 *   Experiment 4 -- Linked Queue        *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *            File type.h                *
 *  This head file contains the type and *
 *  macro of this program.               *
 *****************************************/

#pragma once

#define NODE_SIZE sizeof (Node)

typedef struct
{
	int id;             //patient's ID
} Element, Patient;		//the data of the node
typedef struct QNode
{
	Element data;
	struct QNode *next;
} Node, *NodePtr;
typedef struct
{
	NodePtr front;		//head pointers of queue
	NodePtr rear;		//rear pointers of queue
} LinkQueue;

