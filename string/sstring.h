/*****************************************
* DataStructures--String (fixed length) *
*         Experiment program            *
*        Developed by Sam Liu           *
* Only for study and education purpose. *
*   The author has no responsibility    *
*     for the errors or omissions!      *
*****************************************/

#pragma once

#include <stdbool.h>

//Fixed length sequence string storage structure

#define MAXSTRLEN 255				//string should not exceed 255 characters
typedef unsigned char SString[MAXSTRLEN + 1];	//SString[0]is the length

												//function prototype

												//operation: generate a new string
												//pre-condition: chars is a string const
												//post-condition: T will equal to chars
void StrAssign(SString T, char *chars);

//operation: copy one string to another
//pre-condition: S exists
//post-condition: T will equal to S
void StrCopy(SString T, SString S);

//operation: decide whether a string is empty
//pre-condition: S exists
//post-condtion: return true if it is empty, false otherwise
bool StrEmpty(SString S);

//operation: compare two strings
//pre-condition:S and T exist
//post-condition: return >0 if S>T, =0 if S=0, <0 if S<T
int StrCompare(SString S, SString T);

//operation: get a string's length
//pre-condition: S exists
//post-condition:return S's length
int StrLength(SString S);

//operation: wipe a string to NULL
//pre-condition: S exists
//post-condition: S will be set to NULL
void ClearString(SString S);

//operation: concatenate two strings into one
//pre-condition: S1 and S2 exist
//post-condition: T will carry the new string(S1+S2)
//				  return true if the two strings are perserved in T,
//				  false other wise
bool Concat(SString T, SString S1, SString S2);

//operation: get one string's sub string
//pre-condition: S exists, 1<=pos<=StrLength(S), 0<=len<=StrLength(S)-pos+1
//post-condition: Sub will carry the sub string of S(start from pos,
//				  length is len), return true if it succeeds, false
//				  otherwise
bool SubString(SString Sub, SString S, unsigned char pos, unsigned char len);

//operation: get a character from string
//pre-condition: S exists, pos is the position(>=1 <=StrLength(S))
//post-condition: return the corresponding characert, if it is not return '\0'
unsigned char GetChar(SString S, unsigned char pos);

//operation: decide one certain sub string's position in main string
//pre-condition: S and T exist, T is not empty, 1<=pos<=StrLength(S)
//post-condition: if there exists a sub string that equals to T in the main
//				  string S, then return the location(a integer greater than 
//				  or equal pos ) that T first appears in S after
//				  pos number of characters. otherwise return 0
unsigned char Index(SString S, SString T, unsigned char pos);

//operation: replace some sub strings in a string
//pre-condition: S, T and V exist, T is not empty
//post-condition: replace all the sub strings that equal to T but overlap
//				  in main string S with V,
//				  return true if it succeeds, false otherwise
bool Replace(SString S, SString T, SString V);

//operation: insert a sub string in  main string
//pre-condition: S and T exist, 1<=pos<=StrLength(S)+1
//post-condition: insert T before the pos number character in string S
bool StrInsert(SString S, unsigned char pos, SString T);

//operation:delete a sub string in main string
//pre-conditoin: S exist, 1<=pos<=StrLength(S)-len+1
//post-condition: delete a sub string that the length is len in S
//				  from the pos character
bool StrDelete(SString S, unsigned char pos, unsigned char len);

//operation: print a string
//pre-condition: S exists
//post-condition: S will be printed, and nothing will be changed
void PrintString(SString S);
