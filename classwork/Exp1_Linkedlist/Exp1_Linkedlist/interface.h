/*********************************************
 * Data Structure Experiment 1-- Linked List *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *            file : interface.h             *
 *   This head file contains the prototype   *
 *   of functions that are used for the      *
 *   interface of this program.              *
 *********************************************/

#pragma once

#include "type.h"

//welcome UI
//pre-condition: l is the linked list
void Welcome(LinkList *l);

//create a student list in sequence order
//pre-condition: l is the linked list
void Create_Se(LinkList *l);

//create a student list in inverse order
//pre-condition: l is the linked list
void Create_In(LinkList *l);

//print all the students' data
//pre-condition: l is the linked list
void PrintStudent(LinkList *l);

//search students by name
//pre-condition: l is the linked list
void Search_Name(LinkList *l);

//search students by id
//pre-condition: l is the linked list
void Search_ID(LinkList *l);

//search students by sequence order
//pre-condition: l is the linked list
void Search_Sequence(LinkList *l);

//add a new student
//pre-condition: l is the linked list
void AddStudent(LinkList *l);

//delete a student
//pre-condition: l is the linked list
void DeleteStudent(LinkList *l);

//sum the number of all the students
//pre-condition: l is the linked list
void Sum(LinkList *l);