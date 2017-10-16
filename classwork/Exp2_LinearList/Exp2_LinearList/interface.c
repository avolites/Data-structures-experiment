#include "interface.h"
#include "LinearList.h"
#include "internalfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

void Welcome(SqList * l)
{
	//welcome UI
	char choice;
	bool j = true;		//to decide whether the input in correct
	InitList(l);
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|              Experiment 2              |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|               Linear List              |");
		puts("\t\t|       Data: Students' Information      |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|        Developed by Gaoxiang Liu       |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|    [1] Create Student List             |");
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
			case '1':
				Create(l);
				j = true;
				break;
			case '2':
				ShowStu(l);
				j = true;
				break;
			case '3':
				SearchID(l);
				j = true;
				break;
			case '4':
				SearchName(l);
				j = true;
				break;
			case '5':
				SearchLocation(l);
				j = true;
				break;
			case '6':
				AddStu(l);
				j = true;
				break;
			case '7':
				DeleteStu(l);
				j = true;
				break;
			case '8':
				Sum(l);
				j = true;
				break;
			case '9':
				DestroyList(l);
				exit(0);
			}
			if (j)
				break;
		}
	}
}

void Create(SqList * l)
{
	//create a sutdent list
	Node e;
	int i, j;
	system("cls");
	system("color 0e");
	puts("=============Create A List================");
	printf("Please input the number of students you want to add: ");
	scanf("%d", &i);
	while (getchar() != '\n')	//Dispose of the rest of
		continue;				//characters in stream.
	for (j = 1; j <= i; ++j)
	{
		InputStudent(&e);
		if (LocateElem(l, &e, IfNodesEqual))
		{
			puts("This student's ID has already exists, please try another one.");
			--j;
		}
		else
			ListInsert(l, j, &e);
	}
	puts("DONE");
	puts("Press any key to continue.");
	_getch();
}

void ShowStu(SqList * l)
{
	//show all the students
	system("cls");
	system("color 0e");
	if (!ListIsEmpty(l))
	{
		PrintTableHead();
		ListTraverse(l, Display);
		printf("\nSum: %d\n\n", ListLength(l));
	}
	else
		puts("There is no student.");
	puts("Press any key to continue.");
	_getch();
}

void SearchID(SqList * l)
{
	//search by id
	char id[ID_LEN];
	system("cls");
	system("color 0e");
	if (ListIsEmpty(l))
		puts("There is no student.");
	else
	{
		puts("=============Search Student by ID================");
		puts("Please input the ID of the student you want to find.");
		my_gets(id, ID_LEN);
		if (!SearchbyID(*l, id))
			puts("The ID doesn't exist.");
	}
	puts("Press any key to continue.");
	_getch();
}

void SearchName(SqList * l)
{
	//search by name
	char name[NAME_LEN];
	system("cls");
	system("color 0e");
	if (ListIsEmpty(l))
		puts("There is no student.");
	else
	{
		puts("=============Search Student by Name================");
		puts("Please input the name of the student you want to find.");
		my_gets(name, NAME_LEN);
		SearchbyName(*l, name);
	}
	puts("Press any key to continue.");
	_getch();
}

void SearchLocation(SqList * l)
{
	//search by location
	int i = 0;
	Node e;
	system("cls");
	system("color 0e");
	if (ListIsEmpty(l))
		puts("No data");
	else
	{
		puts("=============Search Student by Location================");
		puts("Please input the lcoation of the student.");
		scanf("%d", &i);
		while (getchar() != '\n')
			continue;
		if (GetNode(l, i, &e))
		{
			PrintTableHead();
			Display(&e);
		}
		else
		{
			puts("The location is wrong.");
		}
	}
	puts("Press any key to continue.");
	_getch();
}

void AddStu(SqList * l)
{
	//add new student
	Node e;
	int i = 0;
	system("cls");
	system("color 0e");
	puts("=============Add a Student================");
	puts("Please input the location that you want to insert.");
	scanf("%d", &i);
	while (getchar() != '\n')
		continue;
	if (i<1 || i>l->length + 1)
		puts("The location is wrong.");
	else
	{
		puts("Please input the sutdent's information.");
		InputStudent(&e);
		if (LocateElem(l, &e, IfNodesEqual))
			puts("This ID has already existed.");
		else
		{
			if (ListInsert(l, i, &e))
				puts("DONE!");
			else
				puts("Something went wrong.");
		}
	}
	puts("Press any key to continue.");
	_getch();
}

void DeleteStu(SqList * l)
{
	//delete a student
	Node e;
	int i = 0;
	char choice;
	system("cls");
	system("color 0e");
	puts("=============Delete a Student================");
	if (ListIsEmpty(l))
		puts("No data!");
	else
	{
		puts("Please input the locatoin that you want to delete.");
		scanf("%d", &i);
		while (getchar() != '\n')
			continue;
		if (GetNode(l, i, &e))			//successful
		{
			puts("The student's information is:");
			PrintTableHead();
			Display(&e);
			puts("Are you sure that you want to delete it?[y/n]");
			choice = _getch();
			if (choice == 'Y' || choice == 'y')
			{
				ListDelete(l, i, &e);
				puts("DONE!");
			}
		}
		else
		{
			puts("The location is wrong.");
		}
	}
	puts("Press any key to continue.");
	_getch();
}

void Sum(SqList * l)
{
	//sum the quantity of students
	system("cls");
	system("color 0e");
	puts("=============Sum================");
	printf("Sum: %d student(s).\n",ListLength(l));
	puts("Press any key to continue.");
	_getch();
}
