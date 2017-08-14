/******************************************************************
 *        Stack Appliance--Conversion of Number Base              *
 *   To convert a decimal into binary, ocatl or hexadeciaml.      *
 *                   Developed by Gaoxinag Liu                    *
 *  The author has no responsibility for the errors or omissions. *
 *              Only for sutdy or education purpose.              *
 ******************************************************************/

#pragma once

#include "stack.h"
//operation:To convert a decimial into other bases of number
//pre-condition:n is the decimal integer, base should be 2,8 or 16
//post-conditoin:print the new number
void conversion(unsigned int n, unsigned int base);