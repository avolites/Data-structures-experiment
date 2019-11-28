/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
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

typedef int32_t KeyType;

typedef struct Node
{
	KeyType key;
} Node;


//the first cell(elem[0]) is empty, it will be used in search
//namely, the first element is in elem[1] 
typedef struct List
{
	Node *elem;					//the address of storage
	uint32_t length;			//current length
	uint32_t listsize;			//size in all
} SSTable;                      //static search table
