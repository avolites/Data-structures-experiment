/************************************************************************
 *              Stack Appliance--Solutions of Labyrinth                 *
 *    Print all the solutions(simple path) of a given labyrinth         *
 *             This head file is only for this appliance                *
 *                     Developed by Gaoxinag Liu                        *
 *     The author has no responsibility for the errors or omissions.    *
 *                Only for sutdy or education purpose.                  *
 ************************************************************************/

#pragma once

#include "stack.h"

#define X_axis 10
#define Y_axis 10

typedef struct
{
	int map[X_axis][Y_axis];	//0:corridor block,-1:wall block,
								//1:footprint
								//that means this block is in the solution path
								//that means this block is wrong
	Position entrance;
	Position exit;
} Labyrinth;

//operation:to leave the footprint on a block
//pre-conditoin:pos is a pointer to a block,
//post-conditoin:the corresponding coordinate will be set to 1
void FootPrint(Labyrinth *maze, const Position *pos);

//operation:clean the footprint
//pre-conditoin:maze points to const Labyrinth, pos points to const Position
//post-consition:the block will be reset to 0
void ClearPrint(Labyrinth *maze,const Position *pos);

//operation:give the next position
//pre-condition:pos is current position,dir is direction(1,2,3,4);
//post-condition:return the next position
Position NextPos(const Position *pos, int dir);

//operation:decide whether the block is corridor
//pre-conditoin:maze points to const Labyrinth, pos points to const Position
//post-conditoin:return true if it is corridor blocks, false otherwise
bool Pass(const Labyrinth *maze, const Position *pos);

//operation:print the map with solution
//pre-condition:maze is a pointer to the labyrinth, n is the solution's order
//post-condition:the map and the solution will be printed
void PrintMap(const Labyrinth *maze, int n);

//operation:solve the labyrinth
//pre-conditoin: "maze" is the labyrinth
//post-conditoin:print all the solutions
void MazePath(Labyrinth *maze);