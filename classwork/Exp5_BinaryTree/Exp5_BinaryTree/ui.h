/*********************************************
 * Data Structure Experiment 5-- Binary Tree *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *             Nov. 4,2017                   *
 *********************************************
 *               File: ui.h                  *
 *    This head file contains all the        *
 *    prototype of functions of user         *
 *    interface(UI).                         *
 *********************************************/

#pragma once

#include "type.h"

void welcome();

void CreateBiTree_UI(BiTree *);

void Traverse_Pre_UI(BiTree *);

void Traverse_In_UI(BiTree *);

void Traverse_Post_UI(BiTree *);

void GetDepth(BiTree *);

void GetNodeQuantity(BiTree *);

void Exchange_UI(BiTree *);

//if user's choice is wrong, it will print error message
void ChoiceError();
