#include <iostream>
#include "stack.h"

using namespace std;

SqStack::SqStack()
{
	base = (Element *)malloc(ELEMENT_SIZE*STACK_INIT_SIZE);
	if (!base)
		exit(1);
	top = base;
	stacksize = STACK_INIT_SIZE;
}
bool SqStack::push(const Element &e)
{
	if (top - base >= stacksize)
	{
		base = (Element *)realloc(base, ELEMENT_SIZE*(STACK_INIT_SIZE + STACK_INCREMENT));
		if (!base)
			exit(1);
		stacksize += STACK_INCREMENT;
	}
	*top++ = e;
	return true;
}
bool SqStack::pop(Element &e)
{
	if (top == base)
		return false;
	e = *--top;
	return true;
}