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
 *      Last Modify: Dec. 10, 2017       *
 *****************************************
 *            File sort.h                *
 * This head file contains the prototype *
 * of the function relating to sort.     *
 *****************************************/

#pragma once

#include "sqlist.h"

//operation: Straight Insertion Sort
//pre-condition: L points to an existed list
//post-condition: all the record will be sorted by key
void StrInsertion(SqList *L);

//operation: Binary Insertion Sort
//pre-condition: L points to an existed list
//post-condition: all the record will be sorted by key
void BinInsertion(SqList *L);

//operation: Shell's Sort
//pre-condition: L points to an existed list,dlta[0..t-1]
//post-condition: all the record will be sorted by key
void ShellSort(SqList *L, uint32_t dlta[], uint32_t t);

//operation: one round of Shell' sort
//pre-condition: L points to an existed list
static void ShellInsert(SqList *L, uint32_t dk);

//operation: Quick Sort
//pre-condition: L points to an existed list
//post-condition: all the record will be sorted by key
void Quick(SqList *L, uint32_t low, uint32_t high);

//operation: decide one element's position
//pre-condition: L points to a table, low and high mark 
//				 the head and tail element
static uint32_t Partition(SqList *L, uint32_t low, uint32_t high);

//operation: Merge Sort
//pre-condition: L points to an existed list
//post-condition: all the record will be sorted by key
void MergeSort(SqList *L);

//operation: sort every two adjacent elements in an "array"
//pre-condition: SR is source array, TR is target array
//post-condition: SR[i..m] and SR[m+1..n] will be merged into ordered TR[1..n]
void Merge(Record SR[], Record TR[], uint32_t i, uint32_t m, uint32_t n);

//operation: Merge Sort
//pre-condition: SR is the source array, tr is the targe array
//post-condition: SR[s..t] will be merge sorted into TR[s..t]
void MSort(Record SR[], Record TR[], uint32_t s, uint32_t t);