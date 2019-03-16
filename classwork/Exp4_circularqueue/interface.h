/*****************************************
 *   Experiment 4 -- Circular Queue      *
 * Simulate Patients' Treatment process  *
 *     Developed by Gaoxiang Liu         *
 *           Oct. 29, 2017               *
 *****************************************
 *           File: interface.h           *
 *  This head file contains the interface*
 *  function prototypes of this program. *
 *****************************************/

#pragma once

#include "type.h"

//operation: welcome UI
void Welcome();

//operation: display the menu and some information
void Display();

//operation: Wait in line UI
void WaitInLine_UI(CirQueue *q);

//operation: print error message if hospital doesn't accept new patients
void noAccept();

//operation: Treatment UI
void Treatment_UI(CirQueue *q);

//operation: view all the patients in line(Traverse)
void View(CirQueue *q);

//operation: treat all the patients
void TreatAllPatients(CirQueue *q);

//operation: off work
void OffWork();

