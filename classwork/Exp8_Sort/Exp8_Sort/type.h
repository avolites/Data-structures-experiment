/*****************************************
 *        Experiment 8 -- Sort           *
 *           Sequence Table              *
 *       Straight Insertion Sort         *
 *        Binary Insertion Sort          *
 *            Shell's Sort               *
 *             Quicak Sort               *
 *            Merging Sort               *
 *     Developed by Gaoxiang Liu         *
 *             Dec. 2017                 *
 *****************************************
 *      Last Modify: Dec. 7, 2017        *
 *****************************************
 *              File type.h              *
 * This head file contains the types and *
 * macros of search table in this        *
 * program.                              *
 *****************************************/

#pragma once

#include <stdint.h>

#define EQ(a,b) ((a) == (b))    //equal
#define LT(a,b) ((a) < (b))     //less than
#define LQ(a,b) ((a) <= (b))    //less than or equal
#define GT(a,b) ((a) > (b))     //greater than
#define GQ(a,b) ((a) >= (b))    //greater than or equal

#define LIST_INIT_SIZE 100		//linear list's initial size
#define LIST_INCREMENT 10		//increment

//the type of the key
typedef int32_t KeyType;

//other data beyond key
//this is a experiment program, so InfoType has only one member
typedef struct
{
	char c;
} InfoType;

typedef struct Node
{
	KeyType key;		//key
	InfoType otherinfo;	//data in other field
} Record;

//the first element(elem[0]) is empty, for it has special function
typedef struct List
{
	Record *elem;				//the address of storage
	uint32_t length;			//current length
	uint32_t listsize;			//size in all
} SqList;
