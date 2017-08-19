#include <stdio.h>
#include "bracketscheck.h"

int main()
{
	char s[100];
	puts("Please input an expression, it may contain (),{},[],<>");
	gets_s(s,100);
	if (BracketsCheck(s))
		printf("This expression's brackets are matched.\n");
	else
		printf("There is something wrong with brackets.\n");
	return 0;
}