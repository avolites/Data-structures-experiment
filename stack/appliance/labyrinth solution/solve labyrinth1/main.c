#include <stdio.h>
#include "labyrinth.h"

int main()
{
	Labyrinth l = { 
		{
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,0,0,-1,0,0,0,-1,0,-1},
			{-1,0,0,-1,0,0,0,-1,0,-1},
			{-1,0,0,0,0,-1,-1,0,0,-1},
			{-1,0,-1,-1,-1,0,0,0,0,-1},
			{-1,0,0,0,-1,0,0,0,0,-1},
			{-1,0,-1,0,0,0,-1,0,0,-1},
			{-1,0,-1,-1,-1,0,-1,-1,0,-1},
			{-1,-1,0,0,0,0,0,0,0,-1},
			{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }
		},
		{1,1},{8,8} };
	MazePath(&l);
	return 0;
}