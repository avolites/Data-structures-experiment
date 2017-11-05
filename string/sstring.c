#include "sstring.h"
#include <stdio.h>
#include <conio.h>

void StrAssign(SString T, char * chars)
{
	//operation: generate a new string
	T[0] = 0;			//initial length is 0
	char *p = chars;
	while (*p != '\0')
	{
		++T[0];
		T[T[0]] = *p;
		++p;
	}
}

void StrCopy(SString T, SString S)
{
	//operation: copy one string to another
	for (unsigned char i = 1; i <= S[0]; ++i)
		T[i] = S[i];
	T[0] = S[0];
}

bool StrEmpty(SString S)
{
	//operation: decide whether a string is empty
	if (S[0])
		return false;
	return true;
}

int StrCompare(SString S, SString T)
{
	//operation: compare two strings
	int i = 1, j = 1;
	bool k = true;
	int t;
	while (i <= S[0] && j <= T[0])
	{
		t = S[i] - T[i];
		if (t < 0 || t < 0)
		{
			k = false;
			break;
		}
		++i;
		++j;
	}
	if (k)
	{
		if (S[0] > T[0])
			return 1;
		if (T[0] > S[0])
			return -1;
	}
	else
	{
		if (i < S[0])
			return -1;
		if (j < T[0])
			return 1;
	}
	return 0;
}

int StrLength(SString S)
{
	//operation: get a string's length
	return S[0];
}

void ClearString(SString S)
{
	//operation: wipe a string to NULL
	S[0] = 0;
}

bool Concat(SString T, SString S1, SString S2)
{
	//operation: concatenate two strings into one
	if (S1[0] + S2[0] <= MAXSTRLEN)
	{
		for (int i = 1; i <= S1[0]; ++i)
			T[i] = S1[i];
		for (int i = S1[0] + 1; i <= S1[0] + S2[0]; ++i)
			T[i] = S2[i - S1[0]];
		T[0] = S1[0] + S2[0];
		return true;
	}
	else if (S1[0] < MAXSTRLEN)
	{
		for (int i = 1; i <= S1[0]; ++i)
			T[i] = S1[i];
		for (int i = S1[0] + 1; i <= MAXSTRLEN; ++i)
			T[i] = S2[i - S1[0]];
		T[0] = MAXSTRLEN;
		return false;
	}
	else
	{
		for (int i = 1; i <= MAXSTRLEN; ++i)
			T[i] = S1[i];
		T[0] = MAXSTRLEN;
		return false;
	}
}

bool SubString(SString Sub, SString S, unsigned char pos, unsigned char len)
{
	//operation: get one string's sub string
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return false;
	for (int i = 1; i <= len; ++i)
		Sub[i] = S[pos - 1 + i];
	Sub[0] = len;
	return true;
}

unsigned char GetChar(SString S, unsigned char pos)
{
	//operation: get a character from string
	unsigned char c = '\0';
	if (pos >= 1 && pos <= StrLength(S))
		c = S[pos];
	return c;
}

unsigned char Index(SString S, SString T, unsigned char pos)
{
	//operation: decide one certain sub string's position in main string
	unsigned char i = pos;
	unsigned char n = StrLength(S);
	unsigned char m = StrLength(T);
	SString sub;
	if (pos > 0)
	{
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0)
				++i;
			else
				return i;
		}
	}
	return 0;
}

bool Replace(SString S, SString T, SString V)
{
	//operation: replace some sub strings in a string
	unsigned char n;
	if (n = (Index(S, T, 1)))
	{
		StrDelete(S, n, T[0]);
		if (StrInsert(S, n, V))
			return true;
	}
	return false;
}

bool StrInsert(SString S, unsigned char pos, SString T)
{
	//operation: insert a sub string in  main string
	if (pos<1 || pos>S[0] + 1 || S[0] + T[0] > MAXSTRLEN)
		return false;
	for (unsigned char i = S[0]; i >= pos; --i)
		S[i + T[0]] = S[i];
	for (unsigned char i = pos; i < T[0] + pos; ++i)
		S[i] = T[i - pos + 1];
	S[0] += T[0];
	return true;
}

bool StrDelete(SString S, unsigned char pos, unsigned char len)
{
	//operation:delete a sub string in main string
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return false;
	for (unsigned char i = pos + len; i <= S[0]; ++i)
		S[i - len] = S[i];
	S[0] -= len;
	return true;
}

void PrintString(SString S)
{
	//operation: print a string
	for (unsigned char i = 1; i <= S[0]; ++i)
		putchar(S[i]);
}

