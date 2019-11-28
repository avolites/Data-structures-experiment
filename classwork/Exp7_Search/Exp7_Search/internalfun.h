/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************
 *          File internalfun.h           *
 * This head file contains the function  *
 * prototypes of the operation relating  *
 * to this program.                      *
 *****************************************/

 #pragma once

#include "type.h"
#include <stdbool.h>

//operation: print a node's data
//pre-condition: e is the node
//post-condition: nothing will be changed
void PrintNode(Node *e);

//operation: compare two keys and print the information
//pre-condition: a and b are the two keys
//post-condition: return true if a == b, false otherwise
bool IsEqual(KeyType a, KeyType b);

//operation: print "not exist"
void Print_ne(KeyType key);

//operation: print"successfully added"
void Print_sa(KeyType key);

//operation: print how many times have compared
void Comp_Times(uint32_t n);