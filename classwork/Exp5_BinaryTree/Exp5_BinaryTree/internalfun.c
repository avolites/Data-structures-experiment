#include "internalfun.h"
#include <stdio.h>

void InputData(ElementType *e)
{
	//operation: input a node's data
	e->a = getchar();
	if (e->a != EOF && e->a != '\n')
		while (getchar() != '\n')
			continue;
}

void PrintNode(BiTree bt)
{
	//operation: print a node's data
	putchar(bt->data.a);
}
