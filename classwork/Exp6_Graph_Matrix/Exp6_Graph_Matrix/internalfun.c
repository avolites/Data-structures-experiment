#include <stdio.h>
#include "internalfun.h"


void Input_Vertex(VertexType * vertex)
{
	//operation: input a vertex's data
	*vertex = getchar();
	while (getchar() != '\n')
		continue;
}

void Input_Number(int32_t * n)
{
	//operation: input a integer(weight of arc)
	scanf("%d", n);
	while (getchar() != '\n')
		continue;
}

void Prompt_VertexNum(void)
{
	printf("Quantity of Vertexs >");
}

void Prompt_ArcNum(void)
{
	printf("Quantity of Arcs(edges) >");
}

void Prompt_VertexData(void)
{
	printf("Vertex Data >");
}

void Prompt_Weight(void)
{
	printf("Weight >");
}

void Pormpt_VexOrder(void)
{
	printf("The Order of Vertex >");
}

void Info_VertexData(void)
{
	puts("Please input the each vertex's data.");
}

void Info_CreateArcs(void)
{
	puts("Please create arcs(edges),type two vertexs and one arc \
will be created.");
}

void Print_VexData(VertexType v)
{
	putchar(v);
}
