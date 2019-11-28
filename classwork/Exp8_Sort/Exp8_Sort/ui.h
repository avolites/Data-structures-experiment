/*****************************************
*        Experiment 8 -- Sort           *
*           Sequence Table              *
*       Straight Insertion Sort         *
*        Binary Insertion Sort          *
*            Shell's Sort               *
*             Quicak Sort               *
*            Merging Sort               *
*     Developed by Gaoxiang Liu         *
*             Dec. 2017                 *
*****************************************
*      Last Modify: Dec. 19, 2017       *
*****************************************
*             File ui.h                 *
* This head file contains the user      *
* interface function prototype.         *
*****************************************/

#pragma once

#include "type.h"

void ui_Welcome();

void ui_Create(SqList *L);

void ui_Clear(SqList *L);

void ui_StrIns(SqList *L);

void ui_BinIns(SqList *L);

void ui_Shell(SqList *L);

void ui_Quick(SqList *L);

void ui_Merge(SqList *L);

void ui_ShowTable(SqList *L);