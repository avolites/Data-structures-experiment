#include <stdio.h>
#include "conversion.h"

void conversion(unsigned int n, unsigned int base)
{
	SqStack s;
	InitStack(&s);
	Element e;
	if (base == 2 || base == 8 || base == 16)
	{
		while (n)
		{
			e.a = n%base;
			Push(&s, &e);
			n /= base;
		}
		while (!StackIsEmpty(&s))
		{
			Pop(&s, &e);
			switch (base)
			{
			case 16:
				printf("%X", e.a);
				break;
			default:
				printf("%d", e.a);
			}
		}
	}
}