#include "sqlist.h"
#include <stdlib.h>

bool InitList(SqList *l)
{
	l->elem = (Record*)malloc(LIST_INIT_SIZE * (sizeof(Record) + 1));
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
	InitList(l);
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

uint32_t ListLength(const SqList *l)
{
	return l->length;
}

bool GetRecord(const SqList *l, uint32_t i, Record *e)
{
	if (l->length == 0 || i<1 || i>l->length)
		return false;
	*e = *(l->elem + i);
	return true;
}

uint32_t LocateElem(const SqList *l, const Record *e, bool(*compare)(const Record*, const Record*))
{
	uint32_t n = 1;
	bool sw = false;
	if (!ListIsEmpty(l))				//list is not emepty
	{
		for (; n <= l->length; ++n)
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

bool ListInsert(SqList * l, uint32_t i, const Record * e)
{
	if (i<1 || i>l->length + 1)				//To check if i is legal
		return false;
	if (l->length >= l->listsize)			//storage room has been full, apply some new room
	{
		l->elem = (Record*)realloc(l->elem, (l->listsize + LIST_INCREMENT) * sizeof(Record));
		if (l->elem == NULL)					//memory overflow
			exit(1);
		l->listsize += LIST_INCREMENT;
	}
	Record *q = l->elem + i;			//q is inserting location
	for (Record *p = l->elem + l->length; p >= q; --p)
		*(p + 1) = *p;
	*q = *e;
	++l->length;
	return true;
}

bool ListDelete(SqList * l, uint32_t i, Record * e)
{
	if (i<1 || i>l->length)					//To check if i is illegal
		return false;
	*e = *(l->elem + i);
	for (Record *p = l->elem + i + 1; p <= l->elem + l->length; ++p)
		*(p - 1) = *p;
	--l->length;
	return true;
}

void ListTraverse(SqList * l, void(*visit)(Record *))
{
	for (Record *p = l->elem + 1; p <= l->elem + l->length; ++p)
		visit(p);
}