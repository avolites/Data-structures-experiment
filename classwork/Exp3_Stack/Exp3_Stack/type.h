/*********************************************
 *   Data Structure Experiment 2-- Stack     *
 *          Number Base Converter            *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *            file : type.h                  *
 *   This head file contains the types and   *
 *   the macros for this program.            *
 *********************************************/

#pragma once

#define STACK_INIT_SIZE 100		//initial quantity of elements
#define STACK_INCREMENT 10		//increment
#define ELEMENT_SIZE    sizeof(Element) 

#define OCT 8
#define HEX 16
#define BIN 2

typedef struct
{
	unsigned char a;			//to store the non-decimal number
} Element;						//Element of the stack
typedef struct
{
	Element *base;				//stack bottom pointer
								//base will be NULL before construction
								//and after destroy
	Element *top;				//stack top pointer
								//it points the first element over the top one
								//top==base when stack is emtpy
	int stacksize;				//the occupied memory room
								//based on the unit of element
								//0:befroe construction and after destroy
} SqStack;