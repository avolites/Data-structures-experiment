/*******************************************
 *    Data Structure Experiment -- Graph   *
 *        Storage: Adjacency Matrix        *
 *        Developed by Gaoxinag Liu        *
 *               Nov.11, 2017              *
 *  Only for study and education purpose.  *
 *   The author has no responsibility      *
 *     for the errors or omissions!        *
 *******************************************
 *          file: mgraph.h                 *
 *   This head file contains the prototype *
 *   of functions for graph.               *
 *******************************************/

#pragma once

#include "type_mgraph.h"
#include <stdbool.h>

 //operation: create a undinetwork
 //pre-condition: G is the graph
 //post-condition: the graph will be created
void CreateUDN(MGraph *G);

//operation: create a dinetwork
//pre-condition: G is the graph
//post-condition: the graph will be created
void CreateDN(MGraph *G);

//operation: create a undigraph
//pre-condition: G is the graph
//post-condition: the graph will be created
void CreateUDG(MGraph *G);

//operation: create a digraph
//pre-condition: G is the graph
//post-condition: the graph will be created
void CreateDG(MGraph *G);

//operation: locate a vertex
//pre-condition: G is the graph, v is the vertex that you want to find
//post-condition: return the location(integer,the order of vertex array)
int32_t LocateVex(const MGraph *G, const VertexType *v);

//operation: get the first adjacency vertex
//pre-condition: G is the graph, v is the location of vertex
//post-condidtion: return v's first adjacency vertex,
//					reuturn -1 if it doesn't exist
int32_t FirstAdjVex(const MGraph *G, int32_t v);

//operation: get the next adjacency vertex of one vertex
//pre-condition: G is the graph , v and w is the locaion of vertex\
//post-condition: return v's next adjacency vertex(based on w),
//					return -1 if w is the last adjacency vertex of v
int32_t NextAdjVex(const MGraph *G, int32_t v, int32_t w);

//operation: DFS Traverse
//pre-condition: G is the graph that will be traversed
//				 visit is the function will be applied to every vertex
void DFSTraverse(MGraph *G, void(*visit)(VertexType));

//operation: DFS Traverse
//pre-consdition: v is the current vertex that is under traversed
void DFS(MGraph *G, void(*visit)(VertexType), int32_t v);

//operation: BFS Traverse
//pre-consdition: v is the current vertex that is under traversed
void BFSTraverse(MGraph *G, void(*visit)(VertexType));