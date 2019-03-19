/*******************************************
 *    Data Structure Experiment -- Graph   *
 *        Storage: Adjacency Matrix        *
 *        Developed by Gaoxinag Liu        *
 *               Nov.11, 2017              *
 *  Only for study and education purpose.  *
 *   The author has no responsibility      *
 *     for the errors or omissions!        *
 *******************************************
 *         file: internalfun.h             *
 *   This head file contains the prototype *
 *   of functions for some operations      *
 *   for this type of graph.               *
 *******************************************/

#pragma once

#include "type_mgraph.h"

//operation: input a vertex's data
void Input_Vertex(VertexType *vertex);

//operation: input a integer(weight of arc,quantity of vertexs or arcs)
void Input_Number(int32_t *n);

//operation: prompt:input vertex number
void Prompt_VertexNum(void);

//operation: prompt:input arc(edge) number
void Prompt_ArcNum(void);

//operation: prompt:input vertex's data
void Prompt_VertexData(void);

//operation: prompt:input weight
void Prompt_Weight(void);

//operation: prompt:input the order(create order) of vertex
void Pormpt_VexOrder(void);

//please input the each vertex's data
void Info_VertexData(void);

//please create arcs(edges),type two vertexs and one arc will be created
void Info_CreateArcs(void);

//operation: print a vertex's data
void Print_VexData(VertexType v);