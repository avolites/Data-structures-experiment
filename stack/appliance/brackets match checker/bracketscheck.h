/************************************************************************
 *               Stack Appliance--Brackets Match Check                  *
 *  To check whether the brackets in a expression can match each other. *
 *             This head file is only for this appliance                *
 *                     Developed by Gaoxinag Liu                        *
 *     The author has no responsibility for the errors or omissions.    *
 *                Only for sutdy or education purpose.                  *
 ************************************************************************/

#pragma once

#include "stack.h"

//operation:to check whether the brackets in a expression can match each other
//pre-condition:the variable "exp" is the expression given by user
//				there are only four types of brackets in the expression
//				(),[],{},<>, otherwise, it can't recognize
//post-condition:the expression will not be changed
//				 return true if the brackets are correct, false otherwise
bool BracketsCheck(const char *exp);