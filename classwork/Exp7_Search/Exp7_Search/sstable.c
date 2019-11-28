/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************/

#include "sstable.h"
#include "internalfun.h"
#include <stdlib.h>

void sst_Init(SSTable *st)
{
    //operation: initialize a static search table
    st->elem = (Node*)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!st->elem)
		exit(1);			//memory overflow
	st->length = 0;
	st->listsize = LIST_INIT_SIZE;
}

void sst_Destroy(SSTable *st)
{
    //operation: destroy a table
    if (st->elem != NULL)
		free(st->elem);
}

void sst_Clear(SSTable * st)
{
	//operation: wipe all the element in the table
	st->length = 0;
}

bool sst_Insert(SSTable *st, uint32_t i, const Node *e)
{
    //operation: insert a node into the table
	if (i<1U || i>st->length + 1)			//To check if i is legal
		return false;
	if (st->length >= st->listsize)			//storage room has been full, apply some new room
	{
		st->elem = (struct Node*)realloc(st->elem,
                    (st->listsize + LIST_INCREMENT) * sizeof(struct Node));
		if (st->elem == NULL)				//memory overflow
			exit(1);
		st->listsize += LIST_INCREMENT;
	}
	Node *q = st->elem + i;					//q is inserting location
	for (Node *p = st->elem + st->length; p >= q; --p)
		*(p + 1) = *p;
	*q = *e;
	++st->length;
	return true;
}

bool sst_Delete(SSTable *st, uint32_t i, Node *e)
{
    //operation: delete a node from the list
    if (i<1U || i>st->length)					//To check if i is illegal
		return false;
	*e = *(st->elem + i);
	for (struct Node *p = st->elem + i + 1; p <= st->elem + st->length; ++p)
		*(p - 1) = *p;
	--st->length;
	return true;
}

void sst_Traverse(SSTable *st, void(*visit)(Node *))
{
    //operation: traverse all the element in a table
	Node *q = st->elem + 1;		//the first element
	while (q <= st->elem + st->length)
	{
		visit(q);
		++q;
	}
}

void sst_Search_Seq_Demo(SSTable * st, KeyType key)
{
	//operation: sequence search demostration process
	uint32_t count = 0;			//counter
	uint32_t i = st->length;	//location
	st->elem[0].key = key;
	while (i)
	{
		++count;
		if (IsEqual(key, st->elem[i].key))	//found
			break;
		--i;
	}
	if (i == 0)					//the key doesn't exist
	{
		Node temp;
		temp.key = key;			//create a temporary node
		Print_ne(key);
		sst_Insert(st, st->length + 1, &temp);
		Print_sa(key);
		sst_Traverse(st, PrintNode);
	}
	Comp_Times(count);
}

void sst_Search_Bin_Demo(SSTable * st, KeyType key)
{
	//operation: binary search demostration process
	uint32_t low = 1;
	uint32_t high = st->length;
	uint32_t mid;
	uint32_t count = 0;
	while (low<=high)
	{
		++count;
		mid = (low + high) / 2;
		if (IsEqual(key, st->elem[mid].key))
			break;
		else if (LT(key, st->elem[mid].key))
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low > high)
	{
		Node temp;
		temp.key = key;			//create a temporary node
		Print_ne(key);
		sst_Insert(st, st->length + 1, &temp);
		Print_sa(key);
		sst_Traverse(st, PrintNode);
	}
	Comp_Times(count);
}

uint32_t sst_Search_Seq(SSTable *st, KeyType key)
{
    //operation: sequence search
	st->elem[0].key = key;		//the element that will be found
	uint32_t i;					//location
	for (i = st->length; !EQ(st->elem[i].key, key); --i)
		continue;
    return i;
}

uint32_t sst_Search_Bin(SSTable *st, KeyType key)
{
    //operation: binary search
	uint32_t low = 1;
	uint32_t high = st->length;
	uint32_t mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key, st->elem[mid].key))
			return mid;
		else if (LT(key, st->elem[mid].key))
			high = mid - 1;
		else
			low = mid + 1;
	}
    return 0;
}

void sst_Sort(SSTable * st)
{
	//operation: sort all the key in ascent order
	uint32_t i, j;
	KeyType t;
	for (i = 1; i <= st->length; ++i)
		for (j = i + 1; j < st->length; ++j)
			if (st->elem[i].key > st->elem[j].key)
			{
				t = st->elem[i].key;
				st->elem[i].key = st->elem[j].key;
				st->elem[j].key = t;
			}
}
