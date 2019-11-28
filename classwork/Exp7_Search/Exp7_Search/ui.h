/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************
 *              File ui.h                *
 * This head file contains the function  *
 * prototypes of user interface.         *
 *****************************************/

#pragma once

#include "type.h"

void welcome(void);

//operation: create a static seach table
void ui_create(SSTable *st);

//operation: sequence search demo
void ui_Search_Seq_Demo(SSTable *st);

//operation: sequence search
void ui_Search_Seq(SSTable *st);

//operation: binary search demo
void ui_Search_Bin_Demo(SSTable *st);

//operation: binary search
void ui_Search_Bin(SSTable *st);

//operation: print "DONE";
void ui_Done(void);

//operation: print table
void ui_Print_Table(SSTable *st);
