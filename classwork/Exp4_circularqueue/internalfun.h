/*****************************************
 *   Experiment 4 -- Circular Queue      *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *        File: internalfun.h            *
 *  This head file contains the internal *
 *  function prototypes relating to      *
 *  circular queue, which serves this    *
 *  program.                             *
 *****************************************/

 #pragma once

 #include"cirqueue.h"

//operation: print a node's data
//pre-condition: e points to a element
//post-condition: nothing will be changed
void PrintELem(Element *e);

//operation: check whether the new data is legal
//post-condition: return true if it is legal, false otherwise
bool Check(CirQueue *q, Patient e);

//operation: new patient comes, wait in the line(EnQueue)
//pre-condition: e is the patient's information
//post-condition: return true if it success, otherwise false(queue is full)
bool WaitInLine(CirQueue *q, Patient e);

//operation: a patient in line gets treatment(DeQueue)
//post-condition: return true if it success, otherwise false(queue is empty)
bool Treatment(CirQueue *q, Patient *e);
