/*********************************************
 * Data Structure Experiment 5-- Binary Tree *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *             Nov. 4,2017                   *
 *********************************************
 *            File: bitree.h                 *
 *   This head file contains all the         *
 *   prototype of functions for binary       *
 *   tree's operation.                       *
 *********************************************/

#pragma once

#include "type.h"
#include <stdbool.h>
#include <stdint.h>

//operation: 
//pre-condition: tree exists, root points to a binary tree
//post-condition:

//operation: Initialize a binary tree
//pre-condition: root is the root of a binary tree
//post-condition: root will be set to NULL
void InitBiTree(BiTree *root);

//operation: Create a binary tree(pre-order)
//pre-condition: the binary tree exists
//post-condition: root will points the created tree
void CreateBiTree_Pre(BiTree *root);

//operation: Create a binary tree(in-order)
//pre-condition: the binary tree exists
//post-condition: root will points the created tree
void CreateBiTree_In(BiTree *root);

//operation: Create a binary tree(post-order)
//pre-condition: the binary tree exists
//post-condition: root will points the created tree
void CreateBiTree_Post(BiTree *root);

//operation: destroy a binary tree
//pre-condition: tree exists, root points to a binary tree
//post-condition: the tree will be freed, root will be set to NULL
void DestroyBiTree(BiTree *root);

//operation: decide whether a binary tree is empty
//pre-condition: tree exists, root points to a binary tree
//post-condition: return true if it is empty, false otherwise
bool BiTreeIsEmpty(BiTree root);

//operation: get the depth of a binary tree
//pre-condition: tree exists, root points to a binary tree
//post-condition: return the depth(integer) of it, 0 if it is empty
uint32_t BiTreeDepth(BiTree root);

//operation: get the quantity of the nodes in tree
//pre-condition: tree exists, root points to a binary tree
//post-condition: return the number of nodes
uint32_t BiTreeCount(BiTree root);

//operation: traverse the binary(pre-order)
//pre-condition: tree exists, root points to a binary tree
//				 visit is the function will be applied
//post-condition: all the nodes will be applied the function visit
void Traverse_Pre(BiTree root, void(*visit)(BiTree));

//operation: exchange the left and the right child tree
//pre-condition: tree exists, root points to a binary tree
//post-condition: the left and right child tree will be exchanged
void Exchange(BiTree root);

//operation: traverse the binary(in-order)
//pre-condition: tree exists, root points to a binary tree
//				 visit is the function will be applied
//post-condition: all the nodes will be applied the function visit
void Traverse_In(BiTree root, void(*visit)(BiTree));

//operation: traverse the binary(post-order)
//pre-condition: tree exists, root points to a binary tree
//				 visit is the function will be applied
//post-condition: all the nodes will be applied the function visit
void Traverse_Post(BiTree root, void(*visit)(BiTree));