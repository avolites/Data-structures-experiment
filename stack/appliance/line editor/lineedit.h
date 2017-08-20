/************************************************************************
*                      Stack Appliance--Line Edit                      *
*             This head file is only for this appliance                *
*                     Developed by Gaoxinag Liu                        *
*     The author has no responsibility for the errors or omissions.    *
*                Only for sutdy or education purpose.                  *
************************************************************************/

#pragma once

#include "stack.h"

//operation:to simulate line edit
//pre-condition:input a line(press ENTER to finish,EOF to quit),
//				two characters have special meaning,
//				'#'means backspace(delete the previous character),
//				'@' means delete the whole line
//post-conidtion:print the final line
void LineEdit();