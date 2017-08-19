#include "bracketscheck.h"

bool BracketsCheck(const char * exp)
{
	SqStack s;
	InitStack(&s);
	Element e;
	char *p = exp;
	while (*p != '\0')		//fetch every character in "exp"
	{
		e.a = *p;
		bool rightbracket = false;
		switch (e.a)
		{
		case '(':			//left bracket
		case '{':
		case '[':
		case '<':
			Push(&s, &e);
			rightbracket = false;
			break;
		case ')':			//right bracket
		case '}':
		case ']':
		case '>':
			Pop(&s, &e);
			rightbracket = true;
		}
		if (rightbracket)	//to decide whether the right bracket can
							//match the nearest left bracket
		{
			switch (e.a)
			{
			case ')':
				if (*p != '(')
					return false;
				break;
			case '}':
				if (*p != '{')
					return false;
				break;
			case ']':
				if (*p != '[')
					return false;
				break;
			case '>':
				if (*p != '<')
					return false;
			}
		}
		p++;
	}
	if (StackIsEmpty(&s))
		return true;
	return false;
}