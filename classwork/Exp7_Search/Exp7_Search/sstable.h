/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************
 *           File sstable.h              *
 * This head file contains the function  *
 * prototypes of the operation relating  *
 * to static search table.               *
 *****************************************/

#pragma once

#include "type.h"
#include <stdbool.h>

//operation: initialize a static search table
//pre-condition: st is the table
//post-condition: allocate some room in memory
void sst_Init(SSTable *st);

//operation: destroy a table
//pre-condition: st points to the table
//post-condition: the static room in memory will be free
void sst_Destroy(SSTable *st);

//operation: wipe all the element in the table
//pre-condition: st is the table
//post-condition: length will be set to 0
void sst_Clear(SSTable *st);

//operation: insert a node into the table
//pre-condition: st points to a table, e is the node that will be inserted
//				 you will insert the node before i,in a plain word,
//				 the new inserted node's sequence number will be i.
//post-condition: return TRUE if it's successful,otherwise FLASE
bool sst_Insert(SSTable *st, uint32_t i, const Node *e);

//operation: delete a node from the list
//pre-condition: st points to a list, you will delete number i node,
//post-condition: the node you delete will copy to e,
//				  return TRUE if it's successful,otherwise FALSE
bool sst_Delete(SSTable *st, uint32_t i, Node *e);

//operation: traverse all the element in a table
//pre-condition: st is the table, visit is the function that will be applied
//post-condition: all the node's data will be applied with visit
void sst_Traverse(SSTable *st, void(*visit)(Node *));

//operation: sequence search demostration process
//pre-condition: st is the table, key is the key that will be searched
//post-condition: if it does not find, create that element in table
//                print how many times to compare and the compared keys as well
void sst_Search_Seq_Demo(SSTable *st, KeyType key);

//operation: binary search demostration process
//pre-condition: st is the table, key is the key that will be searched
//				 sort the element in ascent order before use this function
//post-condition: if it does not find, create that element in table
//                print how many times to compare and the compared keys as well
void sst_Search_Bin_Demo(SSTable *st, KeyType key);

//operation: sequence search
//pre-condition: st is the table, key is the key that will be searched
//post-condition: return the location of the element, return 0 if it does not find
uint32_t sst_Search_Seq(SSTable *st, KeyType key);

//operation: binary search
//pre-condition: st is the table, key is the key that will be searched
//				 sort the element in ascent order before use this function
//post-condition: return the location of the element, return 0 if it does not find
uint32_t sst_Search_Bin(SSTable *st, KeyType key);

//operation: sort all the key in ascent order
//pre-condition: st is the table
//post-condition: all the element will be sorted in ascent order
void sst_Sort(SSTable *st);