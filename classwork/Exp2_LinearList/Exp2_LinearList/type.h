/*********************************************
 * Data Structure Experiment 1-- Linear List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *               file : type.h               *
 *   This head file contains the type        *
 *   definition for this program.            *
 *********************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS		//overlook the warning in VS

#define ID_LEN 8
#define NAME_LEN 20

typedef struct Node
{
	char num[ID_LEN];		//ID
	char name[NAME_LEN];
	int score;
} Node, Student;

typedef struct List
{
	Node *elem;					//the address of storage
	int length;					//current length
	int listsize;				//the max current capacity
								//which can be enlarged later
} SqList;