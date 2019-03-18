/*****************************************
 *   Experiment 4 -- Linked Queue        *
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
void WaitInLine_UI(LinkQueue *q);

//operation: print error message if hospital doesn't accept new patients
void noAccept();

//operation: Treatment UI
void Treatment_UI(LinkQueue *q);

//operation: view all the patients in line(Traverse)
void View(LinkQueue *q);

//operation: treat all the patients
void TreatAllPatients(LinkQueue *q);

//operation: off work
void OffWork();

