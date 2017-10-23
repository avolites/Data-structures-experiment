#include"interface.h"
#include"type.h"
#include"conversion.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

void Welcome(void)
{
	//welcome UI
	char choice;
	bool j = false;
	while (1)
	{
		system("cls");
		system("color 0a");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|              Experiment 3              |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|                  Stack                 |");
		puts("\t\t|          Number Base Converter         |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|        Developed by Gaoxiang Liu       |");
		puts("\t\t|----------------------------------------|");
		puts("\t\t|    [1] Decimal to Binary               |");
		puts("\t\t|    [2] Decimal to Octal                |");
		puts("\t\t|    [3] Decimal to Hexadecimal          |");
		puts("\t\t|    [4] Exit                            |");
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
				Con(BIN);
				j = true;
				break;
			case '2':
				Con(OCT);
				j = true;
				break;
			case '3':
				Con(HEX);
				j = true;
				break;
			case '4':
				exit(0);
			}
			if (j)
				break;
		}
	}
}

void Con(unsigned int n)
{
	//decimal to other number bases
	system("cls");
	system("color 0e");
	unsigned int d;
	printf("-----------------Decimal to %s-----------------\n",
		(n==2)?"binary":((n==8)?"Octal":"Hexadecimal"));
	printf("Please input a decimal integer:   ");
	scanf("%u", &d);
	while (getchar() != '\n')
		continue;
	printf("Result:   ");
	conversion(d, n);
	puts("\n\nPress any key to return to menu.");
	_getch();
}
