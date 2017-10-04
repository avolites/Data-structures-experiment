/************************************************************************
 *          Stack Appliance--Integer Elementary Arithmetic              *
 *Input an integere elementary arithmetic expression to get the outcome.*
 *             This head file is only for this appliance                *
 *                     Developed by Gaoxinag Liu                        *
 *     The author has no responsibility for the errors or omissions.    *
 *                Only for sutdy or education purpose.                  *
 ************************************************************************/

#pragma once

#include "stack.h"

//operation:decide whether the character is operaton(+-*/%)
//pre-condition:c is the character
//post-condition:return true if "c" is operator, false otherwise
bool IsOperator(char c);

//operation:get the corresponding value of the operator
//pre-condition:variable "c" should be operator, that means user should use
//				IsOperator first to decide if the character is operator
//post-condition:return corresponding vlaue +:0,-:1,*:2,/:3,%:4,(:5,):6,#:7
int GetOperator(char c);

//operation:piece together all the digits into a integer
//pre-condition:p is a pointer to char, it takes the current location
//				in the expression string
//post-condition:return the corresponding integer
int GetInteger(char *p);

//operation:get the outcome
//pre-condition:a is the first operand, b is the second one, op is operation
//post-condition:return the outcome
int Operate(Element a, int op, Element b);

//operation:get the priority relation between two operator
//pre-condition:op1 and op2 are two operators
//post-condition:if the precedence of op1 is higher than op2, return 1
//				 if the precedence of op1 is as same as op2, return 0
//				 if the precedence of op1 is lower than op2, return -1
//				 if there is something wrong(eg. wrong expressoin), return -2
int Precedence(int op1, int op2);

//operation:get a expression's value
//pre-conditoin:"expr" takes the string of the expression
//post-condition:return the final outcome
int EvaluateExpression(char *expr);