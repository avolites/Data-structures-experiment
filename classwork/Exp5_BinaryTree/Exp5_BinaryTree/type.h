/*********************************************
 * Data Structure Experiment 5-- Binary Tree *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *             Nov. 4,2017                   *
 *********************************************
 *              File: type.h                 *
 *     This head file contains all the       *
 *     types and macros of this program.     *
 *********************************************/

#pragma once

#define NODE_SIZE sizeof(BiNode)

typedef struct
{
	char a;		//the data of every noe
} ElementType;

typedef struct BiNode
{
	ElementType data;
	struct BiNode *lchild, *rchild;
	//left child and right child
} BiNode,*BiTree;
