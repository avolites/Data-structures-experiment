#include "mgraph.h"
#include "internalfun.h"
#include "queue.h"

static bool visited[MAX_VERTEX_NUM];	//record whether the vertex is visited
										//false: haven't been visited

void CreateUDN(MGraph * G)
{
	//operation: create a undinetwork
	G->kind = UDN;
	Prompt_VertexNum();
	Input_Number(&G->vexnum);
	Prompt_ArcNum();
	Input_Number(&G->arcnum);
	Info_VertexData();
	for (int32_t i = 0; i < G->vexnum; ++i)		//acquire vertexs' data
	{
		Prompt_VertexData();
		Input_Vertex(&G->vertexs[i]);
	}
	for (int32_t i = 0; i < G->vexnum; ++i)		//initialize adjacency
		for (int32_t j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = INFINITY;
	Info_CreateArcs();
	for (int32_t k = 0; k < G->arcnum; ++k)		//construct adjacency matrix
	{
		int32_t i, j;
		int32_t w;
		Pormpt_VexOrder();
		Input_Number(&i);
		Pormpt_VexOrder();
		Input_Number(&j);
		Prompt_Weight();
		Input_Number(&w);
		G->arcs[i][j] = G->arcs[j][i] = w;
	}
}

void CreateDN(MGraph * G)
{
	//operation: create a dinetwork
	G->kind = DN;
	Prompt_VertexNum();
	Input_Number(&G->vexnum);
	Prompt_ArcNum();
	Input_Number(&G->arcnum);
	Info_VertexData();
	for (int32_t i = 0; i < G->vexnum; ++i)		//acquire vertexs' data
	{
		Prompt_VertexData();
		Input_Vertex(&G->vertexs[i]);
	}
	for (int32_t i = 0; i < G->vexnum; ++i)		//initialize adjacency
		for (int32_t j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = INFINITY;
	Info_CreateArcs();
	for (int32_t k = 0; k < G->arcnum; ++k)		//construct adjacency matrix
	{
		int32_t i, j;
		int32_t w;
		Pormpt_VexOrder();
		Input_Number(&i);
		Pormpt_VexOrder();
		Input_Number(&j);
		Prompt_Weight();
		Input_Number(&w);
		G->arcs[i][j] = w;
	}
}

void CreateUDG(MGraph * G)
{
	//operation: create a undigraph
	G->kind = UDG;
	Prompt_VertexNum();
	Input_Number(&G->vexnum);
	Prompt_ArcNum();
	Input_Number(&G->arcnum);
	Info_VertexData();
	for (int32_t i = 0; i < G->vexnum; ++i)		//acquire vertexs' data
	{
		Prompt_VertexData();
		Input_Vertex(&G->vertexs[i]);
	}
	for (int32_t i = 0; i < G->vexnum; ++i)		//initialize adjacency
		for (int32_t j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = 0;
	Info_CreateArcs();
	for (int32_t k = 0; k < G->arcnum; ++k)		//construct adjacency matrix
	{
		int32_t i, j;
		Pormpt_VexOrder();
		Input_Number(&i);
		Pormpt_VexOrder();
		Input_Number(&j);
		G->arcs[i][j] = G->arcs[j][i] = 1;
	}
}

void CreateDG(MGraph * G)
{
	//operation: create a digraph
	G->kind = DG;
	Prompt_VertexNum();
	Input_Number(&G->vexnum);
	Prompt_ArcNum();
	Input_Number(&G->arcnum);
	Info_VertexData();
	for (int32_t i = 0; i < G->vexnum; ++i)		//acquire vertexs' data
	{
		Prompt_VertexData();
		Input_Vertex(&G->vertexs[i]);
	}
	for (int32_t i = 0; i < G->vexnum; ++i)		//initialize adjacency
		for (int32_t j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = 0;
	Info_CreateArcs();
	for (int32_t k = 0; k < G->arcnum; ++k)		//construct adjacency matrix
	{
		int32_t i, j;
		Pormpt_VexOrder();
		Input_Number(&i);
		Pormpt_VexOrder();
		Input_Number(&j);
		G->arcs[i][j] = 1;
	}
}

int32_t LocateVex(const MGraph * G, const VertexType * v)
{
	//operation: locate a vertex
	for (int32_t i = 0; i < G->vexnum; ++i)
	{
		if (G->vertexs[i] == *v)
			return i;
	}
	return -1;
}

int32_t FirstAdjVex(const MGraph * G, int32_t v)
{
	//operation: get the first adjacency vertex
	if (v < G->vexnum)
	{
		for (int32_t i = 0; i < G->vexnum; ++i)
			if (G->arcs[v][i] != 0 && G->arcs[v][i] != INFINITY)
				return i;
	}
	return -1;
}

int32_t NextAdjVex(const MGraph * G, int32_t v, int32_t w)
{
	//operation: get the next adjacency vertex of one vertex
	if (v < G->vexnum)
	{
		for (int32_t i = w + 1; i < G->vexnum; ++i)
		{
			if (G->arcs[v][i] != 0 && G->arcs[v][i] != INFINITY)
				return i;
		}
	}
	return -1;
}

void DFSTraverse(MGraph * G, void(*visit)(VertexType))
{
	for (int32_t v = 0; v < G->vexnum; ++v)	//initialize visit token
		visited[v] = false;
	for (int32_t v = 0; v < G->vexnum; ++v)
		if (!visited[v])
			DFS(G, visit, v);
}

void DFS(MGraph * G, void(*visit)(VertexType), int32_t v)
{
	visited[v] = true;
	visit(G->vertexs[v]);
	for (int32_t w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (!visited[w])
			DFS(G, visit, w);
}

void BFSTraverse(MGraph * G, void(*visit)(VertexType))
{
	CirQueue Q;
	Element temp1,temp2;
	InitQueue(&Q);
	for (int32_t v = 0; v < G->vexnum; ++v)	//initialize
		visited[v] = false;
	for (int32_t v = 0; v < G->vexnum; ++v)
	{
		if (!visited[v])
		{
			visited[v] = true;
			visit(G->vertexs[v]);
			temp1.a = v;
			EnQueue(&Q, &temp1);
			while (!QueueIsEmpty(&Q))
			{
				DeQueue(&Q, &temp2);
				for(int32_t w = FirstAdjVex(G,temp2.a);w>=0;w=NextAdjVex(G,temp2.a,w))
					if (!visited[w])
					{
						visited[w] = true;
						visit(G->vertexs[w]);
						temp1.a = w;
						EnQueue(&Q, &temp1);
					}
			}
		}
	}
	DestroyQueue(&Q);
}

