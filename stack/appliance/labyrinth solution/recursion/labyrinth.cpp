#include <iostream>

using namespace std;

#define X 6
#define Y 10
#define startx 0
#define starty 0
#define endx 5
#define endy 9

int map[X][Y] = {
   0,2,2,2,2,2,2,2,2,2,
   0,2,0,0,2,0,0,0,2,2,
   0,0,0,2,2,0,2,0,0,2,
   0,2,2,0,0,0,2,2,0,2,
   0,0,0,0,2,0,0,0,0,2,
   2,2,2,2,2,2,2,2,0,0
}; 

int startX = startx, startY = starty, endX = endx, endY = endy, c = 0, j = 0;
//0:corridoer,2:wall,c:number of method,j:whether has exit
void printmap(void);
void labyrinth(int ,int);
void printmethod(int);
int main()
{
	printmap();
	labyrinth(startX,startY);
	if (c == 0)
		cout << "There is no exit!" << endl;
	return 0;
}
void printmap(void)
{
	int i, j;
	cout << "The map is:" << endl;
	for (j = 0; j < X; j++)
	{
		for (i = 0; i < Y; i++)
		{
			if (map[j][i] == 0)
				cout << "  ";
			else
				cout <<"█";
		}
		cout << endl;
	}
}
void printmethod(int c)
{
	int i, j;
	cout << "Method" << c << ':' << endl;
	j = 1;
	for (j = 0; j < X; j++)
	{
		for (i = 0; i < Y; i++)
		{
			if (map[j][i] == 0)
				cout << "  ";
			else if (map[j][i] == 2)
				cout << "█";
			else if (map[j][i] == 1)
				cout << "◎";
		}
		cout << endl;
	}
	cout << endl;
}
void labyrinth(int x,int y)
{
	bool successful;
	if (x == endX && y == endY)
		successful = true;
	else
		successful = false;
	map[x][y] = 1;
	if (successful == false)
	{
		if (y - 1 >= 0 && map[x][y - 1] == 0)
			labyrinth(x,y - 1);
		if (y + 1 < Y && map[x][y + 1] == 0)
			labyrinth(x, y + 1);
		if (x - 1 >= 0 && map[x - 1][y] == 0)
			labyrinth(x - 1, y);
		if (x + 1 < X && map[x + 1][y] == 0)
			labyrinth(x + 1, y);
	}
	else
	{
		c++;
		printmethod(c);
	}
	map[x][y] = 0;
}
