/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************/

#include "ui.h"
#include "sstable.h"
#include "internalfun.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void welcome(void)
{
	SSTable st;
	sst_Init(&st);
	char choice;
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|   Data Structure Experiment -- 7     |");
		puts("\t\t|       Developed by Gaoxiang Liu      |");
		puts("\t\t|          Static Search Table         |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    [1] Create a Static Search Table  |");
		puts("\t\t|    [2] Sequence Search               |");
		puts("\t\t|    [3] Sequence Search Demostration  |");
		puts("\t\t|    [4] Binary Search                 |");
		puts("\t\t|    [5] Binary Search Demostration    |");
		puts("\t\t|    [6] Show the Table                |");
		puts("\t\t|    [7] Sort the Table                |");
		puts("\t\t|    [8] Exit                          |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    Please make choice by pressing    |");
		puts("\t\t|            a number key.             |");
		puts("\t\t|--------------------------------------|");
		choice = _getch();
		switch (choice)
		{
		case '1':
			ui_create(&st);
			break;
		case '2':
			ui_Search_Seq(&st);
			break;
		case '3':
			ui_Search_Seq_Demo(&st);
			break;
		case '4':
			ui_Search_Bin(&st);
			break;
		case '5':
			ui_Search_Bin_Demo(&st);
			break;
		case '6':
			ui_Print_Table(&st);
			break;
		case '7':
			sst_Sort(&st);
			ui_Done();
			break;
		case '8':
			sst_Destroy(&st);
			exit(0);
		}
	}
}

void ui_create(SSTable *st)
{
	Node temp;
	system("cls");
	system("color 0e");
	puts("===================Create a Static Search Table===================");
	puts("Please input every key's value and press Enter, type letter to exit.");
	sst_Clear(st);
	while (1)
	{
		if (!scanf("%d", &temp.key))
		{
			getchar();
			break;
		}
		while (getchar() != '\n')
			continue;
		sst_Insert(st, st->length + 1, &temp);
	}
	puts("Done!");
	_getch();
}

void ui_Search_Seq_Demo(SSTable * st)
{
	KeyType key;
	system("cls");
	system("color 0e");
	puts("===================Sequence Search Demostraion===================");
	printf("key:");
	scanf("%d", &key);
	sst_Search_Seq_Demo(st, key);
	_getch();
}

void ui_Search_Seq(SSTable * st)
{
	KeyType key;
	uint32_t t;
	system("cls");
	system("color 0e");
	puts("===================Sequence Search===================");
	printf("key:");
	scanf("%d", &key);
	t = sst_Search_Seq(st, key);
	if (t == 0)
		printf("There isn't %d in table.\n", key);
	else
		printf("The key %d is at %d.\n", key, t);
	_getch();
}

void ui_Search_Bin_Demo(SSTable * st)
{
	KeyType key;
	system("cls");
	system("color 0e");
	puts("===================Binary Search Demostraion===================");
	printf("key:");
	scanf("%d", &key);
	sst_Search_Bin_Demo(st, key);
	_getch();
}

void ui_Search_Bin(SSTable * st)
{
	KeyType key;
	uint32_t t;
	system("cls");
	system("color 0e");
	puts("===================Binary Search===================");
	printf("key:");
	scanf("%d", &key);
	t = sst_Search_Bin(st, key);
	if (t == 0)
		printf("There isn't %d in table.\n", key);
	else
		printf("The key %d is at %d.\n", key, t);
	_getch();
}

void ui_Done(void)
{
	system("cls");
	system("color 0e");
	puts("Done!");
	_getch();
}

void ui_Print_Table(SSTable * st)
{
	system("cls");
	system("color 0e");
	puts("===================Print a Static Search Table===================");
	sst_Traverse(st, PrintNode);
	_getch();
}
