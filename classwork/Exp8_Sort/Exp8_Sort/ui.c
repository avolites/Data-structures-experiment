#include "ui.h"
#include "sqlist.h"
#include "internalfun.h"
#include "sort.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void ui_Welcome()
{
	char choice;
	SqList L;
	InitList(&L);
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|   Data Structure Experiment -- 8     |");
		puts("\t\t|       Developed by Gaoxiang Liu      |");
		puts("\t\t|                 Sort                 |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    [0] Create a Sort Table           |");
		puts("\t\t|    [1] Wipe the Table                |");
		puts("\t\t|    [2] Print the Table               |");
		puts("\t\t|    [3] Straight Insertion Sort       |");
		puts("\t\t|    [4] Binary Insertion Sort         |");
		puts("\t\t|    [5] Shell's Sort                  |");
		puts("\t\t|    [6] Quick Sort                    |");
		puts("\t\t|    [7] Merging Sort                  |");
		puts("\t\t|    [8] Exit                          |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    Please make choice by pressing    |");
		puts("\t\t|            a number key.             |");
		puts("\t\t|--------------------------------------|");
		choice = _getch();
		switch (choice)
		{
		case '0':
			ui_Create(&L);
			break;
		case '1':
			ui_Clear(&L);
			break;
		case '2':
			ui_ShowTable(&L);
			break;
		case '3':
			ui_StrIns(&L);
			break;
		case '4':
			ui_BinIns(&L);
			break;
		case '5':
			ui_Shell(&L);
			break;
		case '6':
			ui_Quick(&L);
			break;
		case '7':
			ui_Merge(&L);
			break;
		case '8':
			DestroyList(&L);
			exit(0);
		}
	}
}

void ui_Create(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Create a Table=====================");
	puts("Please input a series of numbers, each of them should be separted \
by a sapce, tab or enter. Input Ctrl+D or any non-number character to end.");
	Create_List(L);
	puts("\nDone.");
	_getch();
}

void ui_Clear(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Wipe the Table=====================");
	ClearList(L);
	puts("\nDone.");
	_getch();
}

void ui_StrIns(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Straight Insertion Sort=====================");
	StrInsertion(L);
	puts("\nDone.");
	_getch();
}

void ui_BinIns(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Binary Insertion Sort=====================");
	BinInsertion(L);
	puts("\nDone.");
	_getch();
}

void ui_Shell(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Shell's Sort=====================");
	uint32_t dlta[100], t;
	puts("Please input the quantity of parts.");
	scanf("%u",&t);
	while (getchar() != '\n')
		continue;
	puts("Please input each part's span.");
	for (uint8_t i = 0; i < t; ++i)
		scanf("%u", dlta + i);
	while (getchar() != '\n')
		continue;
	ShellSort(L, dlta, t);
	puts("\nDone.");
	_getch();
}

void ui_Quick(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Quick Sort=====================");
	Quick(L, 1, L->length);
	puts("\nDone.");
	_getch();
}

void ui_Merge(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Merge Sort=====================");
	MergeSort(L);
	puts("\nDone.");
	_getch();
}

void ui_ShowTable(SqList * L)
{
	system("cls");
	system("color 0e");
	puts("=====================Print the Table=====================");
	puts("");
	if (ListIsEmpty(L))
		puts("Empty");
	PrintTable(L);
	_getch();
}
