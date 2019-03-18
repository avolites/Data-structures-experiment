/*****************************************
 *   Experiment 4 -- Linked Queue        *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *        File: internalfun.h            *
 *  This head file contains the internal *
 *  function prototypes relating to      *
 *  linked queue, which serves this      *
 *  program.                             *
 *****************************************/

 #pragma once

 #include "type.h"
 #include <stdbool.h>

 //operation:print a node's data
//pre-conditoin:e points to a element
//post-conditoin:nothing will be changed
void PrintELem(Element *e);

//operation: check whether the new data is legal
//post-condition: return true if it is legal, false otherwise
bool Check(LinkQueue *q, Patient e);

//operation: new patient comes, wait in the line(EnQueue)
//pre-condition: e is the patient's information
//post-condition: return true if it success, otherwise false(queue is full)
bool WaitInLine(LinkQueue *q, Patient e);

//operation: a patient in line gets treatment(DeQueue)
//post-condition: return true if it success, otherwise false(queue is empty)
bool Treatment(LinkQueue *q, Patient *e);
