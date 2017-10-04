#include <stdio.h>
#include "elementaryarithmetic.h"

int main()
{
	char a[100];
	gets_s(a, 100);
	char *p = a;
	while (*p != '\0')
		p++;
	*p = '#';
	p++;
	p = '\0';
	printf("%d",EvaluateExpression(a));
	return 0;
}