#include "ui.h"
#include "bitree.h"
#include "internalfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void welcome()
{
	BiTree root;
	InitBiTree(&root);
	char choice;
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|   Data Structure Experiment -- 5     |");
		puts("\t\t|             Binary Tree              |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    [1] Create A Binary Tree          |");
		puts("\t\t|    [2] Pre Order Traverse            |");
		puts("\t\t|    [3] In Order Traverse             |");
		puts("\t\t|    [4] Post Order Traverse           |");
		puts("\t\t|    [5] Show Tree's Depth             |");
		puts("\t\t|    [6] Show the Quantity of Nodes    |");
		puts("\t\t|    [7] Exchange Right and Left Child |");
		puts("\t\t|    [8] Exit                          |");
		puts("\t\t|--------------------------------------|");
		puts("\t\t|    Please make choice by pressing    |");
		puts("\t\t|            a number key.             |");
		puts("\t\t|--------------------------------------|");
		choice = _getch();
		switch (choice)
		{
		default:
			ChoiceError();
			break;
		case '1':
			CreateBiTree_UI(&root);
			break;
		case '2':
			Traverse_Pre_UI(&root);
			break;
		case '3':
			Traverse_In_UI(&root);
			break;
		case '4':
			Traverse_Post_UI(&root);
			break;
		case '5':
			GetDepth(&root);
			break;
		case '6':
			GetNodeQuantity(&root);
			break;
		case '7':
			Exchange_UI(&root);
			break;
		case '8':
			DestroyBiTree(&root);
			exit(0);
		}
	}
}

void CreateBiTree_UI(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Create A Binary Tree====================");
	puts("Directions:");
	puts("\tTo create a new binary tree in this program, you should input \
each node's data(a character there) respectively accroding to pre-order \
traversing. In an another word, you should input root's data first, then left \
child and right child. If the current node has data, you should input the \
chcaracter(only accept one character once) and press Enter. If the current \
node does not exist, you can simply press Enter directly or input EOF and \
press Enter. EOF can be inputed by pressing Ctrl+Z(Windows, DOS) or Ctrl+D \
(MAC, Unix, Linux).");
	puts("\n\t\tPress any key to continue.");
	_getch();
	system("cls");
	CreateBiTree_In(root);
	puts("\nDone");
	_getch();
}

void Traverse_Pre_UI(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Pre-order Traverse====================");
	if (BiTreeIsEmpty(*root))
		puts("The binary tree is empty.");
	else
		Traverse_Pre(*root, PrintNode);
	_getch();
}

void Traverse_In_UI(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================In-order Traverse====================");
	if (BiTreeIsEmpty(*root))
		puts("The binary tree is empty.");
	else
		Traverse_In(*root, PrintNode);
	_getch();
}

void Traverse_Post_UI(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Post-order Traverse====================");
	if (BiTreeIsEmpty(*root))
		puts("The binary tree is empty.");
	else
		Traverse_Post(*root, PrintNode);
	_getch();
}

void GetDepth(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Show Tree's Depth====================");
	printf("Current Depth: %d", BiTreeDepth(*root));
	_getch();
}

void GetNodeQuantity(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Show The Quantity of Nodes====================");
	printf("Current Nodes Quantity: %d", BiTreeCount(*root));
	_getch();
}

void Exchange_UI(BiTree *root)
{
	system("cls");
	system("color 0e");
	puts("====================Exchange Right and Left Child====================");
	Exchange(*root);
	puts("DONE!");
	_getch();
}

void ChoiceError()
{
	system("cls");
	system("color 0e");
	puts("\t\tYour choice is wrong, please try again.");
	puts("\n\t\t   Press any key to return to menu.");
	_getch();
}
