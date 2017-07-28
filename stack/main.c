#include <stdio.h>
#include "stack.h"

int main()
{
	SqStack s;
	Element e;
	InitStack(&s);
	e.a = 1;
	Push(&s, &e);
	e.a = 2;
	Push(&s, &e);
	e.a = 3;
	Push(&s, &e);
	e.a = 4;
	Push(&s, &e);
	e.a = 5;
	Push(&s, &e);
	Pop(&s, &e);
	printf("%d ", e.a);
	Pop(&s, &e);
	printf("%d ", e.a);
	Pop(&s, &e);
	printf("%d ", e.a);
	Pop(&s, &e);
	printf("%d ", e.a);
	Pop(&s, &e);
	printf("%d ", e.a);
	return 0;
}