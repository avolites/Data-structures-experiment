/*********************************************
 *   Data Structure Experiment 2-- Stack     *
 *          Number Base Converter            *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *              file : stack.h               *
 *   This head file contains the prototype   *
 *   of functions of the basic operation of  *
 *   stack.                                  *
 *********************************************/

#pragma once

#include<stdbool.h>
#include"type.h"

//function prototypes

//operation:initialize an empty stack
//pre-condition:s poionts an uninitialized stack
//post-condition:return true if it succeeds, false otherwise
bool InitStack(SqStack *s);

//operation:destroy a stack
//pre-condition:s points a stack
//post-conditoin:the stack will no longer exist
//				 return true if it succeeds, false otherwise
bool DestroyStack(SqStack *s);

//operation:wipe a stack to empty
//pre-condition:s points to a non-empty stack
//post-condition:return true if it succeeds, false otherwise
bool ClearStack(SqStack *s);

//operation:decide whether the stack is empty
//pre-conditoin:s points to a stack(pointer to const type)
//post-condition:return true if it is emtpy, false otherwise
//				 nothing will be changed
bool StackIsEmpty(const SqStack *s);

//operation:get the occupied memory based on element, namely, stack's lenght
//pre-condition:s points to a stack(pointer to const type)
//post-condition:return an integer, nothing will be changed
int StackLength(const SqStack *s);

//operatoin:get the top element of the stack
//pre-condition:s points to a const stack
//post-condition:e will carry the top element if the stack is not empty
//				 and return true, false otherwise
bool GetTop(const SqStack *s, Element *e);

//operatoin:insert a new element to a stack
//pre-condition:s points to a stack, e is the new element will be instered
//post-condition:reutrn true if it succeeds, false otherwise
bool Push(SqStack *s, const Element *e);

//operation:fetch the top element of the stack
//pre-condition:s points to a stack
//post-condition:e will carry to top element if the stack is not empty
//				 and return true, otherwise, false
bool Pop(SqStack *s, Element *e);

//operation:apply a function to all the elements in the stack(from bottom to top)
//pre-condition:s points to a stack, visit points to a function
//post-condition:return true if the stack is not empty and function is
//				 successfully applied to each element
bool StackTraverse(SqStack *s, void(*visit)(Element *));

//operation:print the element
//pre-condition:e is a pointer to Element
//post-condition:nothing will be changed
void PrintElement(Element *e);