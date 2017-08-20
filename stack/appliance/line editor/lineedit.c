#include <stdio.h>
#include "lineedit.h"

void LineEdit()
{
	SqStack s;
	InitStack(&s);
	Element e;
	e.a = getchar();
	while (e.a != EOF)					//whole funciton will be end when encounters EOF
	{
		while (e.a != EOF&&e.a != '\n')
		{
			switch (e.a)
			{
			default:
				Push(&s, &e);
				break;
			case '#':
				Pop(&s, &e);
				break;
			case '@':
				ClearStack(&s);
			}
			e.a = getchar();
		}
		StackTraverse(&s, PrintElement);		//print one line when finished
		putchar('\n');
		ClearStack(&s);
		if (e.a != EOF)
			e.a = getchar();
	}
}
