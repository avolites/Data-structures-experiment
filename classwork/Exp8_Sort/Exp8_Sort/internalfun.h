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
 *           File internalfun.h          *
 * This head file contains the prototype *
 * of the function relating to the       *
 * exclusive operation of this program.  *
 *****************************************/

#pragma once

#include "sqlist.h"

//operation: create a sequence list
//pre-condition: L is empty
//post-condiiton: the data will be typed by user
void Create_List(SqList *L);

//operation: print a node's key in table
void PrintKey(Record *e);

//operation: print all the keys in table
void PrintTable(SqList *L);