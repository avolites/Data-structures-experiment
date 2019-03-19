/*******************************************
 *   Data Structure Experiment 5-- Graph   *
 *             Stroage: Matrix             *
 *        Developed by Gaoxiang Liu        *
 *            Only for study               *
 *             Nov. 11,2017                *
 *******************************************
 *               File:ui.h                 *   
 *  This head file contains the function   *
 *  prototypes of user interface.          *
 *******************************************/

#pragma once

#include "type_mgraph.h"

void welcome(void);

void ui_Create_UDN(MGraph *G);

void ui_Create_DN(MGraph *G);

void ui_Create_UDG(MGraph *G);

void ui_Create_DG(MGraph *G);

void ui_DFS(MGraph *G);

void ui_BFS(MGraph *G);

