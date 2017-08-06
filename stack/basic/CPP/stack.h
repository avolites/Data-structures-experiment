/***********************************
*      DataStructures--Stack       *
*       Experiment program         *
*      Developed by Sam Liu        *
*     This is the C++ version      *
*        Only for study            *
************************************/

#pragma once

#define STACK_INIT_SIZE 100		//initial quantity of elements
#define STACK_INCREMENT 10		//increment
#define ELEMENT_SIZE    sizeof(Element) 

typedef struct
{
	int a;
} Element;						//Element of the stack

class SqStack
{
private:
	Element *base;				//stack bottom pointer
								//base will be NULL before construction
								//and after destroy
	Element *top;				//stack top pointer
								//it points the first element over the top one
								//top==base when stack is emtpy
	int stacksize;				//the occupied memory room
								//based on the unit of element
								//0:befroe construction and after destroy
public:
	SqStack();					//initial the stack
	bool push(const Element &e);
	bool pop(Element &e);
};