#include <stdio.h>
#include "labyrinth.h"

void FootPrint(Labyrinth * maze, const Position * pos)
{
	maze->map[pos->x][pos->y] = 1;
}

void MarkPrint(Labyrinth * maze, const Position * pos)
{
	maze->map[pos->x][pos->y] = 2;
}

Position NextPos(const Position * pos, int dir)
{
	Position temp;
	switch (dir)
	{
	case 1:
		temp.y= pos->y + 1;
		temp.x = pos->x;
		break;
	case 2:
		temp.x = pos->x + 1;
		temp.y = pos->y;
		break;
	case 3:
		temp.y = pos->y - 1;
		temp.x = pos->x;
		break;
	case 4:
		temp.x = pos->x - 1;
		temp.y = pos->y;
	}
	return temp;
}

bool Pass(const Labyrinth *maze, const Position * pos)
{
	if (maze->map[pos->x][pos->y] == 0)
		return true;
	return false;
}

void PrintMap(const Labyrinth * maze)
{
	for (int x = 0; x < X_axis; x++)
	{
		for (int y = 0; y < Y_axis; y++)
		{
			switch (maze->map[x][y])
			{
			case 0:
				printf("¡õ");
				break;
			case -1:
				printf("¨€");
				break;
			case 1:
				printf("¡ò");
				break;
			default:
				printf("  ");
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

void MazePath(Labyrinth * maze)
{
	SqStack s;
	InitStack(&s);
	Position curpos = maze->entrance;		//current position
	int cursetp = 1;						//current step
	Element e;
	do
	{
		if (Pass(maze, &curpos))
		{
			FootPrint(maze, &curpos);
			e.dir = 1;
			e.order = cursetp;
			e.seat = curpos;
			Push(&s, &e);
			if (curpos.x == maze->exit.x&&curpos.y == maze->exit.y)
			{
				PrintMap(maze);
				//return;
			}
			curpos = NextPos(&curpos, 1);
			cursetp++;						//move on
		}
		else
		{
			if (!StackIsEmpty(&s))
			{
				Pop(&s, &e);						//retreat
				while (e.dir==4&&!StackIsEmpty(&s))	//remove all wrong blocks
				{
					MarkPrint(maze, &e.seat);
					Pop(&s,&e);
				}
				if (e.dir < 4)
				{
					e.dir++;
					Push(&s,&e);
					curpos = NextPos(&e.seat, e.dir);
				}
			}
		}
	} while (!StackIsEmpty(&s));			//stack is not empty
}