#include "internalfun.h"
#include <stdio.h>

void Create_List(SqList * L)
{
	//operation: create a sequence list
	KeyType k;
	uint32_t i = 0;
	Record t;
	while (scanf("%d",&k))
	{
		t.key = k;
		++i;
		ListInsert(L, i, &t);
	}
	while (getchar() != '\n')
		continue;
}

void PrintKey(Record * e)
{
	//operation: print a node's key in table
	printf("%d  ",e->key);
}

void PrintTable(SqList * L)
{
	//operation: print all the keys in table
	ListTraverse(L, PrintKey);
}
