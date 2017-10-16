#include "interface.h"
#include "Linkedlist.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
//definition of the functions in "interface.h"

void Welcome(LinkList *l)
{
	//welcome UI
	char choice;
	bool j = true;		//to decide whether the input in correct
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|              Experiment 1              |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|               Linked List              |");
		puts("\t\t|       Data: Students' Information      |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|        Developed by Gaoxiang Liu       |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|    [0] Create Student List(Sequence)   |");
		puts("\t\t|    [1] Create Student List(Inverse)    |");
		puts("\t\t|    [2] Show All the Students           |");
		puts("\t\t|    [3] Search Student by ID            |");
		puts("\t\t|    [4] Search Student by Name          |");
		puts("\t\t|    [5] Search Student by location      |");
		puts("\t\t|    [6] Add a New Student               |");
		puts("\t\t|    [7] Delete a Student                |");
		puts("\t\t|    [8] Sum the Number of Students      |");
		puts("\t\t|    [9] Exit                            |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|        Please make a choice by         |");
		puts("\t\t|          pressing number key.          |");
		puts("\t\t|----------------------------------------|");
		while (1)
		{
			choice = _getch();
			switch (choice)
			{
			default:
				j = false;
				break;
			case '0':
				Create_Se(l);
				j = true;
				break;
			case '1':
				Create_In(l);
				j = true;
				break;
			case '2':
				PrintStudent(l);
				j = true;
				break;
			case '3':
				Search_ID(l);
				j = true;
				break;
			case '4':
				Search_Name(l);
				j = true;
				break;
			case '5':
				Search_Sequence(l);
				j = true;
				break;
			case '6':
				AddStudent(l);
				j = true;
				break;
			case '7':
				DeleteStudent(l);
				j = true;
				break;
			case '8':
				Sum(l);
				j = true;
				break;
			case '9':
				DestroyList(*l);					//free the storage
				exit(0);
			}
			if (j)
				break;
		}
	}
}

void Create_Se(LinkList *l)
{
	//create a student list in sequence order
	int c = 0;
	system("cls");
	system("color 0e");
	puts("Warning: All the data will be cleared.");
	puts("This function will create a student list based on student \
number in sequence order.");
	printf("Please input the number of students:");
	scanf("%d", &c);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	CreateList_Sequence(l, c);
	puts("Done!");
	_getch();
}

void Create_In(LinkList *l)
{
	//create a student list in inverse order
	int c = 0;
	system("cls");
	system("color 0e");
	puts("Warning: All the data will be cleared.");
	puts("This function will create a student list based on student \
number in inverse order.");
	printf("Please input the number of students:");
	scanf("%d", &c);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	CreateList_Inverse(l, c);
	puts("Done!");
	_getch();
}

void PrintStudent(LinkList *l)
{
	//print all the students' data
	system("cls");
	system("color 0e");
	PrintList(*l);
	puts("Press any key to return the last menu.");
	_getch();
}

void Search_Name(LinkList *l)
{
	//search students by name
	char name[NAME_LEN];
	system("cls");
	system("color 0e");
	printf("Please input the student's name:");
	my_gets(name,NAME_LEN);
	SearchStudentAndPrint(*l,name);
	puts("\nPress any key to return the last menu.");
	_getch();
}

void Search_ID(LinkList * l)
{
	//search students by id
	char id[ID_LEN];
	ElemType *e;
	system("cls");
	system("color 0e");
	printf("Please input the student's ID:");
	my_gets(id, ID_LEN);
	e = SearchStudent_ID(*l, id);
	if (e)
		PrintNode(*e);
	else
		puts("No student!");
	puts("\nPress any key to return the last menu.");
	_getch();
}

void Search_Sequence(LinkList *l)
{
	//search students by sequence order
	int i = 0;
	ElemType e;
	system("cls");
	system("color 0e");
	printf("Please input the student's order:");
	scanf("%d",&i);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	if (GetElem(*l, i, &e))
		PrintNode(e);
	else
		puts("Error: no such a student.");
	puts("Press any key to reuturn the last menu.");
	_getch();
}

void AddStudent(LinkList *l)
{
	//add a new student
	Node e;
	int i;
	system("cls");
	system("color 0e");
	puts("Please input the locatoin that you want to insert.");
	scanf("%d",&i);
	if (i <= 0 || i > ListLength(*l) + 1)
	{
		puts("The location is wrong!");
		_getch();
		return;
	}
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	puts("Please input the student's information:");
	InputData(&e);
	ListInsert(*l, i, e.data);
	puts("Done!");
	_getch();
}

void DeleteStudent(LinkList *l)
{
	//delete a student
	ElemType e;
	int i = 0;
	char c;
	system("cls");
	system("color 0e");
	puts("Please input the location of the student that you want to delete.");
	scanf("%d",&i);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	if (GetElem(*l,i,&e))
	{
		puts("The student is:");
		PrintNode(e);
		puts("Are you sure that you want to delete it?[y/n]");
		c = _getch();
		if (c == 'y')
		{
			ListDelete(*l, i, &e);
			puts("Done!");
			_getch();
		}
	}
	else
	{
		puts("Error: no such a student.");
		_getch();
	}
}

void Sum(LinkList *l)
{
	//sum the number of all the students
	system("cls");
	system("color 0e");
	printf("Sum: %d student(s)\n",ListLength(*l));
	puts("Press any key to return the last menu.");
	_getch();
}
