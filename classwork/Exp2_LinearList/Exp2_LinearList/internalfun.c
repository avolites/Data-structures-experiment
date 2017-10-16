#include "internalfun.h"
#include <string.h>

void CopyNode(Node * e1, Node * e2)
{
	strcpy(e1->num, e2->num);
	strcpy(e1->name, e2->name);
	e1->score = e2->score;
}

bool IfNodesEqual(const struct Node *e1, const struct Node *e2)
{
	if (!strcmp(e1->num,e2->num))
		return true;
	return false;
}
bool IfBigger(const struct Node *e1, const struct Node *e2)
{
	if (strcmp(e1->num, e2->num) > 0)
		return true;
	return false;
}

bool IfSmaller(const struct Node *e1, const struct Node *e2)
{
	if (strcmp(e1->num, e2->num) < 0)
		return true;
	return false;
}

char* my_gets(char*ar, int n)
{
	//operation: to input a string safely
	char *ret;
	int i;
	ret = fgets(ar, n, stdin);
	if (ret)							//not NULL
	{
		i = 0;
		while (ar[i] != '\n' && ar[i] != '\0')
			i++;
		if (ar[i] == '\n')				//the length of the string that user 
										//inputs is less than n
			ar[i] = '\0';
		else
			while (getchar() != '\n')	//Dispose of the rest of
				continue;				//characters in stream.
	}
	return ret;
}

void Display(Node * e)
{
	if (e != NULL)
	{
		printf("%s\t\t%s\t\t\t%d\n", e->num, e->name, e->score);
	}
	else
		printf("No data.\n");
}

void PrintTableHead()
{
	//operation: print the table head
	printf("%s\t\t%s\t\t\t%s\n", "ID", "Name", "Score");
	printf("-------------------------------------------------\n");
}

void SearchbyName(SqList l,char *name)
{
	//operation: print all the students' data who have the same name
	Node *p = l.elem;
	bool j = false;
	for (int i = 0; i < l.length; i++)
	{
		if (!strcmp(p[i].name, name))
		{
			if(!j)
				PrintTableHead();
			Display(p + i);
			j = true;
		}
	}
	if (!j)
		puts("No such a sutdent.");
}

bool SearchbyID(SqList l, char * id)
{
	//operation: search a student by ID
	for (int i = 0; i < l.length; i++)
	{
		if (!strcmp(l.elem[i].num, id))
		{
			PrintTableHead();
			Display(l.elem + i);
			return true;
		}
	}
	return false;
}

void InputStudent(Node * e)
{
	//operation: input a student's information
	printf("Please input the student's id: ");
	my_gets(e->num, ID_LEN);
	printf("Please input the student's name: ");
	my_gets(e->name, NAME_LEN);
	printf("Please input the sutdent's score: ");
	scanf("%d", &e->score);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
}
