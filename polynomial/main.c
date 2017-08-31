#include <stdio.h>
#include <conio.h>
#include "polynomial.h"

int main()
{
	Polynomial p1, p2, t1, t2;
	InitList(&p1);
	InitList(&p2);
	InitList(&t1);
	InitList(&t2);
	puts("Please input the first polynomial.");
	printf("P(A)=");
	CreatePolynomial(&p1);
	puts("Now, input the second polynomial.");
	printf("P(B)=");
	CreatePolynomial(&p2);
	CopyList(&t1, &p1);
	CopyList(&t2, &p2);
	printf("\n\nP(A)=");
	PrintPolynomial(&p1);
	printf("\nP(B)=");
	PrintPolynomial(&p2);
	printf("\n\nP(A)+P(B)=");
	AddPolynomial(&p1, &p2);
	PrintPolynomial(&p1);
	ResetPolynomial(&p1);
	InitList(&p2);
	CopyList(&p1, &t1);
	CopyList(&p2, &t2);
	printf("\nP(A)-P(B)=");
	SubtractPolynomial(&p1, &p2);
	PrintPolynomial(&p1);
	ResetPolynomial(&p1);
	InitList(&p2);
	CopyList(&p1, &t1);
	CopyList(&p2, &t2);
	printf("\nP(A)*P(B)=");
	MultiplyPolynomial(&p1, &p2);
	PrintPolynomial(&p1);
	_getch();
	return 0;
}