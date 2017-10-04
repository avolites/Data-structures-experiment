#include <stdio.h>
#include <string.h>
#include "elementaryarithmetic.h"

bool IsOperator(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '(':
	case ')':
	case '#':
		return true;
	}
	return false;
}

int GetOperator(char c)
{
	switch (c)
	{
	case '+':
		return 0;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	case '%':
		return 4;
	case '(':
		return 5;
	case ')':
		return 6;
	case '#':
		return 7;
	}
	return -1;
}

int GetInteger(char * p)
{
	int value = 0;			//the integer's value
	int magnification = 1;
	Element e;
	SqStack s;
	InitStack(&s);
	while (*p >= '0'&&*p <= '9')
	{
		e.a = *p - 48;
		Push(&s, &e);
		p++;
	}
	while (!StackIsEmpty(&s))
	{
		Pop(&s, &e);
		value += e.a*magnification;
		magnification *= 10;
	}
	return value;
}

int Operate(Element a, int op, Element b)
{
	int value = 0;
	switch (op)
	{
	case 0:
		value = a.a + b.a;
		break;
	case 1:
		value = a.a - b.a;
		break;
	case 2:
		value = a.a * b.a;
		break;
	case 3:
		value = a.a / b.a;
		break;
	case 4:
		value = a.a % b.a;
	}
	return value;
}

int Precedence(int op1, int op2)
{
	switch (op1)
	{
	case 0:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return -1;
			break;
		case 3:
			return -1;
			break;
		case 4:
			return -1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 1:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return -1;
			break;
		case 3:
			return -1;
			break;
		case 4:
			return -1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 2:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 3:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 4:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 5:
		switch (op2)
		{
		case 0:
			return -1;
			break;
		case 1:
			return -1;
			break;
		case 2:
			return -1;
			break;
		case 3:
			return -1;
			break;
		case 4:
			return -1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return 0;
			break;
		case 7:
			return -2;
		}
		break;
	case 6:
		switch (op2)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return -2;
			break;
		case 6:
			return 1;
			break;
		case 7:
			return 1;
		}
		break;
	case 7:
		switch (op2)
		{
		case 0:
			return -1;
			break;
		case 1:
			return -1;
			break;
		case 2:
			return -1;
			break;
		case 3:
			return -1;
			break;
		case 4:
			return -1;
			break;
		case 5:
			return -1;
			break;
		case 6:
			return -2;
			break;
		case 7:
			return 0;
		}
	}
	return -2;
}

int EvaluateExpression(char * expr)
{
	//operator priority algorithm to evaluate expression
	//stack "optr" stores operator, stack "opnd" stores operand
	SqStack optr, opnd;
	Element e, a, b;
	char *cur;		//current position in the expression string
	InitStack(&optr);
	InitStack(&opnd);
	e.a = 7;		//#
	Push(&optr, &e);//put # as the first operator to match the last one
	cur = expr;
	while (!StackIsEmpty(&optr))
	{
		if (!IsOperator(*cur))//current character is not a operator
		{
			e.a = GetInteger(cur);
			while (*cur >= '0'&&*cur <= '9')
				cur++;
			Push(&opnd, &e);
		}
		else
		{
			GetTop(&optr, &e);
			switch (Precedence(e.a, GetOperator(*cur)))
			{
			default:
				puts("The expression is wrong.");
				return 0;
				break;
			case -1:		//the operator on stack top has lower precedence
				e.a = GetOperator(*cur);
				Push(&optr, &e);
				cur++;
				break;
			case 0:			//remove one brecket and move on
				Pop(&optr, &e);
				cur++;
				break;
			case 1:			//calc
				Pop(&optr, &e);
				Pop(&opnd, &b);
				Pop(&opnd, &a);
				e.a = Operate(a, e.a, b);
				Push(&opnd, &e);
				break;
			}//switch
		}//else
	}//while
	GetTop(&opnd, &e);
	return e.a;
}