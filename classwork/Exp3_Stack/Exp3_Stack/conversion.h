/*********************************************
 *   Data Structure Experiment 2-- Stack     *
 *          Number Base Converter            *
 *        Developed by Gaoxiang Liu          *
 *            Only for study                 *
 *               Oct.2017                    *
 *********************************************
 *            file : conversion.h            *
 *   This head file contains the prototype   *
 *   of functions that are used to convert   *
 *   the number base.                        *
 *********************************************/

#pragma once

#include "stack.h"
//operation:To convert a decimial into other bases of number
//pre-condition:n is the decimal integer, base should be 2,8 or 16
//post-conditoin:print the new number
void conversion(unsigned int n, unsigned int base);