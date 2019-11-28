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
 *            File sqlist.h              *
 * This head file contains the prototype *
 * of the function relating to sequence  *
 * list.                                 *
 *****************************************/

#pragma once

#include <stdbool.h>
#include "type.h"

 //function prototype

 //operation:initial a list
 //pre-conditon:l points to a squence list(linear list)
 //pose-condition:Create a new empty linear list
 //				return true if succeed,otherwise false
bool InitList(SqList *l);

//operation:clear a list
//pre-conditoin:linear list l has already existed
//post-condition:linear list l will be empty
void ClearList(SqList *l);

//operation:destroy a list
//pre-condition:linear list l has already existed
//post-condition:every Records in l will be destroyed
void DestroyList(SqList *l);

//operation:decide if the list l is an empty one
//pre-condition:l points to an initialized list
//post-condition:return true if it's empty, otherwise false
bool ListIsEmpty(const SqList *l);

//operation:get list's length
//pre-condition:l points to an initialized list
//post-conditon:return this list's length
uint32_t ListLength(const SqList *l);

//operation:get a Record in the list l
//pre-condition:l points to a list and l is not empty
//post-condition:i is the number of the Record that you want
//				 use form arguement e to return this element
//				 and the funtion wil return true if succeed
bool GetRecord(const SqList *l, uint32_t i, Record *e);

//operation:find one element's location in the list
//pre-condition:l points to a list,e is the element you want to find, 
//				  compare() is the function to compare element
//post-condition:return the first element's sequence number if it's successful, otherwise 0
uint32_t LocateElem(const SqList *l, const Record *e, bool(*compare)(const Record*, const Record*));

//operation:To insert a Record into the list
//pre-condition:l points to a list, e is the Record that you want to insert
//				you will insert the Record before i,in a plain word,
//				the new inserted Record's sequence number will be i.
//post-condition:return TRUE if it's successful,otherwise FLASE
bool ListInsert(SqList *l, uint32_t i, const Record *e);

//operation:To delete a Record from the list
//pre-condition:l points to a list, you will delete number i Record,
//post-condition:the Record you delete will copy to e,
//				 return TRUE if it's successful,otherwise FALSE
bool ListDelete(SqList *l, uint32_t i, Record *e);

//operation:To traverse all the Records in the list
//pre-condition:l points to a list,visit is the function that you want to apply
void ListTraverse(SqList *l, void(*visit)(Record *));