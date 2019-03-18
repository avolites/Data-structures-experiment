#include "bitree.h"
#include "internalfun.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void InitBiTree(BiTree *root)
{
	//operation: Initialize a binary tree
	*root = NULL;
}

void CreateBiTree_Pre(BiTree *root)
{
	//operation: Create a binary tree(pre-order)
	ElementType temp;
	InputData(&temp);
	//exit if user input EOF
	if (temp.a == EOF || temp.a == '\n')
		*root = NULL;		//one node completes
	else
	{
		if (!(*root = (BiTree)malloc(NODE_SIZE)))
			exit(1);		//fail to allocate
		(*root)->data = temp;
		CreateBiTree_Pre(&(*root)->lchild);
		CreateBiTree_Pre(&(*root)->rchild);
	}
}

void CreateBiTree_In(BiTree *root)
{
	//operation: Create a binary tree(in-order)
	ElementType temp;
	InputData(&temp);
	//exit if user input EOF
	if (temp.a == EOF || temp.a == '\n')
		*root = NULL;		//one node completes
	else
	{
		if (!(*root = (BiTree)malloc(NODE_SIZE)))
			exit(1);		//fail to allocate
		CreateBiTree_In(&(*root)->lchild);
		(*root)->data = temp;
		CreateBiTree_In(&(*root)->rchild);
	}
}

void CreateBiTree_Post(BiTree *root)
{
	//operation: Create a binary tree(post-order)
	ElementType temp;
	InputData(&temp);
	//exit if user input EOF
	if (temp.a == EOF || temp.a == '\n')
		*root = NULL;		//one node completes
	else
	{
		if (!(*root = (BiTree)malloc(NODE_SIZE)))
			exit(1);		//fail to allocate
		CreateBiTree_Post(&(*root)->lchild);
		CreateBiTree_Post(&(*root)->rchild);
		(*root)->data = temp;
	}
}

void DestroyBiTree(BiTree *root)
{
	//operation: destroy a binary tree
	if (*root)
	{
		DestroyBiTree(&(*root)->lchild);
		DestroyBiTree(&(*root)->rchild);
		free(*root);
		*root = NULL;
	}
}

bool BiTreeIsEmpty(BiTree root)
{
	//operation: decide whether a binary tree is empty
	if(root)
		return false;
	return true;
}

uint32_t BiTreeDepth(BiTree root)
{
	//operation: get the depth of a binary tree
	int depth = 0;
	if (root)
	{
		int ldepth = BiTreeDepth(root->lchild);
		int rdepth = BiTreeDepth(root->rchild);
		depth = 1 + (ldepth > rdepth ? ldepth : rdepth);
	}
	return depth;
}

uint32_t BiTreeCount(BiTree root)
{
	//operation: get the quantity of the nodes in tree
	int total = 0;
	if (root)
	{
		total++;
		total += BiTreeCount(root->lchild);
		total += BiTreeCount(root->rchild);
	}
	return total;
}
//
//uint32_t BiTreeCount(BiTree root)
//{
//	static int total;
//	if (root)
//	{
//		total++;
//		BiTreeCount(root->lchild);
//		BiTreeCount(root->rchild);
//	}
//	return total;
//}

void Traverse_Pre(BiTree root, void(*visit)(BiTree))
{
	//operation: traverse the binary(pre-order)
	if (root)
	{
		visit(root);
		Traverse_Pre(root->lchild, visit);
		Traverse_Pre(root->rchild, visit);
	}
}

void Exchange(BiTree root)
{
	BiTree p;
	if (root)
	{
		p = root->lchild;
		root->lchild = root->rchild;
		root->rchild = p;
		Exchange(root->lchild);
		Exchange(root->rchild);
	}
}

void Traverse_In(BiTree root, void(*visit)(BiTree))
{
	//operation: traverse the binary(in-order)
	if (root)
	{
		Traverse_In(root->lchild, visit);
		visit(root);
		Traverse_In(root->rchild, visit);
	}
}

void Traverse_Post(BiTree root, void(*visit)(BiTree))
{
	//operation: traverse the binary(post-order)
	if (root)
	{
		Traverse_Post(root->lchild, visit);
		Traverse_Post(root->rchild, visit);
		visit(root);
	}
}
