/*********************************************
 * Data Structure Experiment 1-- Linear List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *           file : internalfun.h            *
 *   This head file contains the prototype   *
 *   of functions that are used for the      *
 *   interface of this program.              *
 *********************************************/

#pragma once

#include "type.h"

//welcome UI
void Welcome(SqList *l);

//create a sutdent list
void Create(SqList *l);

//show all the students
void ShowStu(SqList *l);

//search by id
void SearchID(SqList *l);

//search by name
void SearchName(SqList *l);

//search by location
void SearchLocation(SqList *l);

//add new student
void AddStu(SqList *l);

//delete a student
void DeleteStu(SqList *l);

//sum the quantity of students
void Sum(SqList *l);