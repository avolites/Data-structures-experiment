#include "ui.h"
#include "internalfun.h"
#include "mgraph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void welcome(void)
{
	char choice;
	bool k = true;		//true if it is the first time to run
	MGraph G;
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|----------------------------------------------|");
		puts("\t\t|      Data Structure Experiment 6 -- Graph    |");
		puts("\t\t|            Storage: Adjacency Matrix         |");
		puts("\t\t|            Developed by Gaoxiang Liu         |");
		puts("\t\t|                  Nov.12, 2017                |");
		puts("\t\t|----------------------------------------------|");
		puts("\t\t|             [1] Create a Undigraph           |");
		puts("\t\t|             [2] Create a Digraph             |");
		puts("\t\t|             [3] Create a Undinetwork         |");
		puts("\t\t|             [4] Create a Dinework            |");
		puts("\t\t|             [5] DFS Traverse                 |");
		puts("\t\t|             [6] BFS Traverse                 |");
		puts("\t\t|             [7] Exit                         |");
		puts("\t\t|----------------------------------------------|");
		puts("\t\t|            Please make a choice              |");
		puts("\t\t|----------------------------------------------|");
		printf("\n\t\tCurrent Graph Type:");
		if (k)
		{
			k = false;
			printf("Unknown\n");
		}
		else
			switch (G.kind)
			{
			case UDG:
				puts("Undigraph");
				break;
			case DG:
				puts("Digraph");
				break;
			case UDN:
				puts("Undinetwork");
				break;
			case DN:
				puts("Dinetwork");
				break;
			}
		choice = _getch();
		switch (choice)
		{
		default:
			break;
		case '1':
			ui_Create_UDG(&G);
			break;
		case '2':
			ui_Create_DG(&G);
			break;
		case '3':
			ui_Create_UDN(&G);
			break;
		case '4':
			ui_Create_DN(&G);
			break;
		case '5':
			ui_DFS(&G);
			break;
		case '6':
			ui_BFS(&G);
			break;
		case '7':
			exit(0);
			break;
		}

	}
}

void ui_Create_UDN(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================Create a Undinetwork=======================");
	CreateUDN(G);
	puts("\nDONE");
	_getch();
}

void ui_Create_DN(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================Create a Dinetwork=======================");
	CreateDN(G);
	puts("\nDONE");
	_getch();
}

void ui_Create_UDG(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================Create a Undigrpah=======================");
	CreateUDG(G);
	puts("\nDONE");
	_getch();
}

void ui_Create_DG(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================Create a Digraph=======================");
	CreateDG(G);
	puts("\nDONE");
	_getch();
}

void ui_DFS(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================DFS Traverse=======================");
	DFSTraverse(G, Print_VexData);
	_getch();
}

void ui_BFS(MGraph * G)
{
	system("cls");
	system("color 0e");
	puts("=======================BFS Traverse=======================");
	BFSTraverse(G, Print_VexData);
	_getch();
}
