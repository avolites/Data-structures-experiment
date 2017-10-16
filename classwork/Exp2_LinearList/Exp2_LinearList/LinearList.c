#include "LinearList.h"
#include "internalfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool InitList(SqList *l)
{
	l->elem = (Node*)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!l->elem)
		exit(1);			//memory overflow
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
	return true;
}

void ClearList(SqList *l)
{
	DestroyList(l);
	l->elem = NULL;
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList *l)
{
	if (l->elem != NULL)
		free(l->elem);
}

bool ListIsEmpty(const SqList *l)
{
	if (l->length == 0)
		return true;
	return false;
}

int ListLength(const SqList *l)
{
	return l->length;
}

bool GetNode(const SqList *l, int i, struct Node *e)
{
	if (l->length == 0 || i<1 || i>l->length)
		return false;
	*e = *(l->elem + i - 1);
	return true;
}

int LocateElem(const SqList *l, const struct Node *e, bool(*compare)(const struct Node*, const struct Node*))
{
	int n = 0;
	bool sw = false;
	if (!ListIsEmpty(l))				//list is not emepty
	{
		for (; n < l->length; ++n)
		{
			if (compare(e, l->elem + n))
			{
				sw = true;
				++n;
				break;
			}
		}
		if (!sw)
			n = 0;
	}
	return n;
}

bool ProirElem(const SqList *l, const struct Node *cur_e, struct Node *pre_e)
{
	if (!ListIsEmpty(l))				//list is not empty
	{
		struct Node *temp;
		temp = l->elem;
		CopyNode(pre_e, l->elem);
		if (!IfNodesEqual(temp, cur_e))	//the current node is not the first one of the list
		{
			for (int i = 1; i < l->length - 1; ++i)
			{
				CopyNode(pre_e, l->elem + i);
				if (IfNodesEqual(l->elem + i + 1, cur_e))
					return true;
			}
		}
	}
	return false;
}

bool NextElem(const SqList *l, const struct Node *cur_e, struct Node *next_e)
{
	if (!ListIsEmpty(l))			//list is not empty
	{
		for (int i = 0; i < l->length - 1; ++i)
		{
			if (IfNodesEqual(l->elem + i, cur_e))
			{
				CopyNode(next_e, l->elem + i + 1);
				return true;
			}
		}
	}
	return false;
}

bool ListInsert(SqList * l, int i, const Node * e)
{
	if (i<1 || i>l->length + 1)				//To check if i is legal
		return false;
	if (l->length >= l->listsize)			//storage room has been full, apply some new room
	{
		l->elem = (struct Node*)realloc(l->elem, (l->listsize + LIST_INCREMENT) * sizeof(struct Node));
		if (l->elem == NULL)					//memory overflow
			exit(1);
		l->listsize += LIST_INCREMENT;
	}
	struct Node *q = l->elem + i - 1;			//q is inserting location
	for (struct Node *p = l->elem + l->length - 1; p >= q; --p)
		*(p + 1) = *p;
	*q = *e;
	++l->length;
	return true;
}

bool ListDelete(SqList * l, int i, Node * e)
{
	if (i<1 || i>l->length)					//To check if i is illegal
		return false;
	*e = *(l->elem + i - 1);
	for (struct Node *p = l->elem + i; p <= l->elem + l->length - 1; ++p)
		*(p - 1) = *p;
	--l->length;
	return true;
}

void ListTraverse(SqList * l, void(*visit)(Node *))
{
	for (struct Node *p = l->elem; p <= l->elem + l->length - 1; ++p)
		visit(p);
}

void ListUnion(SqList * la, SqList * lb)
{
	int la_length = la->length;
	int lb_length = lb->length;
	struct Node e;
	for (int i = 1; i <= lb_length; ++i)
	{
		GetNode(lb, i, &e);
		if (!LocateElem(la, &e, IfNodesEqual))
			ListInsert(la, ++la_length, &e);
	}
}

void ListMerge(const SqList * la, const SqList * lb, SqList * lc)
{
	InitList(lc);
	int la_length = la->length;
	int lb_length = lb->length;
	int i = 1, j = 1, k = 0;
	//i is the pointer number of la
	//j,lb and k,lc
	struct Node ea, eb;
	//temporary node
	while ((i <= la_length) && (j <= lb_length))
	{
		GetNode(la, i, &ea);
		GetNode(lb, j, &eb);
		if (IfBigger(&ea, &eb))
		{
			ListInsert(lc, ++k, &eb);
			++j;
		}
		else
		{
			ListInsert(lc, ++k, &ea);
			++i;
		}
	}
	while (i <= la_length)
	{
		GetNode(la, i++, &ea);
		ListInsert(lc, ++k, &ea);
	}
	while (j <= lb_length)
	{
		GetNode(lb, j++, &eb);
		ListInsert(lc, ++k, &eb);
	}
}


