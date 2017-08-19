#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//define of the functions

bool InitStack(SqStack * s)
{
	s->base = (Element *)malloc(STACK_INIT_SIZE*ELEMENT_SIZE);
	if (!s->base)				//fail to apply memory room
		return false;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return true;
}
bool DestroyStack(SqStack * s)
{
	if (s->base)				//if it is an initialized stack
	{
		free(s->base);			//destroy
		s->stacksize = 0;
		s->top = s->base;
		return true;
	}
	return false;
}
bool ClearStack(SqStack * s)
{
	if (s->base)					//if it is an initialized stack
	{
		s->top = s->base;			//set stack to emtpy
		return true;
	}
	return false;
}
bool StackIsEmpty(const SqStack * s)
{
	if(s->top==s->base)
		return true;
	return false;
}
int StackLength(const SqStack * s)
{
	return s->stacksize;
}
bool GetTop(const SqStack * s, Element * e)
{
	if (s->base&&s->top != s->base)	//s points to an initialized and non-empty stack
	{
		*e = *(s->top - 1);
		return true;
	}
	return false;
}
bool Push(SqStack * s, const Element * e)
{
	if (s->top - s->base >= s->stacksize)	//the stack is full,apply more room
	{
		s->base = (Element *)realloc(s->base, 
							(STACK_INIT_SIZE + STACK_INCREMENT)*ELEMENT_SIZE);
		if (!s->base)						//fail to apply memory room
			return false;
		s->stacksize += STACK_INCREMENT;
	}
	*(s->top++) = *e;
	return true;
}
bool Pop(SqStack * s, Element * e)
{
	if (s->top == s->base)					//stack is empty
		return false;
	*e = *--s->top;
	return true;
}
bool StackTraverse(SqStack * s, void(*visit)(Element *))
{
	if (!s->base || s->base == s->top)
		return false;
	Element *p = s->base;
	while (p != s->top)
	{
		visit(p);
		p++;
	}
	return true;
}
void PrintElement(Element * e)
{
	printf("%d ", e->a);
}