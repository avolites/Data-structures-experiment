#include "internalfun.h"
#include <stdio.h>
#include <string.h>

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

void PrintNode(ElemType e)
{
	//operation: to print a node's data
	printf("Id   :%s\n", e.num);
	printf("Name :%s\n", e.name);
	printf("Score:%d\n", e.score);
}

void InputData(Node * e)
{
	//operation: acquire all the data for one node
	printf("input id:");
	my_gets(e->data.num, ID_LEN);
	printf("input name:");
	my_gets(e->data.name, NAME_LEN);
	printf("input score:");
	scanf("%d",&e->data.score);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
}

bool IsLess(ElemType a, ElemType b)
{
	//operation: compare the data of two nodes, to decide who is greater
	if (a.num <= b.num)
		return true;
	return false;
}

ElemType * SearchStudent_Name(LinkList l, char * name)
{
	//operation: search a node base on student's name
	Node *s = l->next;
	while (s)
	{
		if (strcmp(name, s->data.name) == 0)	//match successfully
			return &s->data;
		s = s->next;
	}
	return NULL;
}

ElemType * SearchStudent_ID(LinkList l, char * id)
{
	//operation: search a node base on student's ID
	Node *s = l->next;
	while (s)
	{
		if (strcmp(id, s->data.num) == 0)	//match successfully
			return &s->data;
		s = s->next;
	}
	return NULL;
}

void SearchStudentAndPrint(LinkList l, char * name)
{
	//operation: search all the students who have the same name
	Node *s = l->next;
	int count = 0;
	while (s)			//the s is not pointing NULL
	{
		if (strcmp(name, s->data.name) == 0)
		{
			++count;
			printf("No. %d:\n",count);
			PrintNode(s->data);
			putchar('\n');
		}
		s = s->next;
	}
	if (count == 0)
		puts("No students were found!");
}

bool CompareStudentId(ElemType a, ElemType b)
{
	//operation: to compare whether two students' data are equal
	if (!strcmp(a.num, b.num))
		return true;
	return false;
}

void PrintErr()
{
	//operation: print error message
	puts("This ID has already existed, please try another one.");
}
