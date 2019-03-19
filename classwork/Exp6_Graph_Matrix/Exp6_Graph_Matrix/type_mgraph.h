/*******************************************
 *    Data Structure Experiment -- Graph   *
 *        Storage: Adjacency Matrix        *
 *        Developed by Gaoxinag Liu        *
 *               Nov.11, 2017              *
 *  Only for study and education purpose.  *
 *   The author has no responsibility      *
 *     for the errors or omissions!        *
 *******************************************
 *          file: type_mgraph.h            *
 *   This head file contains the type of   *
 *   this program.                         *
 *******************************************/

#pragma once

#include <stdint.h>


#define INFINITY 32767		//the max weight
#define MAX_VERTEX_NUM 100	//max quantity of vertexs

//the type of graph
//{digraph,dinetwork,undigraph,undinetwork}
typedef enum 
{
	DG,DN,UDG,UDN
} GraphKind;

typedef char VertexType;	//vertex's type
typedef int32_t ArcCell;	//arc type, for undigraph it is 0 or 1
							//          for digraph it is weight
typedef struct MGraph
{
	VertexType vertexs[MAX_VERTEX_NUM];				//vertexs set
	ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//arcs set
	int32_t vexnum, arcnum;						//quantity of vertexs
													//and arcs(edges)
	GraphKind kind;									//graph's type
}MGraph;