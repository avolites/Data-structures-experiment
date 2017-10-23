#include <stdio.h>
#include <stdbool.h>
#include "conversion.h"

void conversion(unsigned int n, unsigned int base)
{
	bool j = false;		//whether n is 0
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
			j = true;		//n is not 0
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
		if (!j)				//if n is 0, the result is 0
			printf("0");
	}
}