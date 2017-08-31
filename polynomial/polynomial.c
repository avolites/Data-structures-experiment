#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>

//local function prototypes

static bool AddElement(Polynomial * p, const Element * e)
{
	//operation:add an item of a polynomial(used by CreatePolynomial())
	NodePtr temp;
	if (p->head != p->tail)							//linked list is not empty
	{
		if (LocateELement(p, e, &temp, IsEqual))	//the exponent has already 
													//in the polynomial
			return false;
		if (IsGreater(&p->tail->data, e))			//to arrange the item in 
													//an increment order
			return false;
	}
	temp = (NodePtr)malloc(NODE_SIZE);
	if (!temp)										//fail to apply room
		exit(0);
	temp->data = *e;
	temp->next = NULL;
	p->tail->next = temp;
	p->tail = temp;
	++p->count;
	return true;
}

static bool DeleteNode(LinkedList * l, NodePtr pp, NodePtr p)
{
	//operation:delete a node in the linked list
	if (l->head == l->tail || l->head == NULL || l->tail == NULL)
		return false;
	if (p == l->tail)
		l->tail = pp;
	pp->next = p->next;
	free(p);
	--l->count;
	return true;
}

static bool InsertNode(LinkedList * l, NodePtr pp, const Element * e)
{
	//operation:insert a node in the linked list
	NodePtr newnode;
	if (l->head == NULL | l->tail == NULL)
		return false;
	newnode = (NodePtr)malloc(NODE_SIZE);
	if (!newnode)
		exit(0);
	newnode->data = *e;
	newnode->next = pp->next;
	pp->next = newnode;
	++l->count;
	return true;
}

static bool AppendPositive(LinkedList * lt, NodePtr na)
{
	//operation:appent some nodes of one linked list to another linked list
	while (na)
	{
		if (!AddElement(lt, &na->data))
			return false;
		na = na->next;
	}
	return true;
}

//public function prototypes

bool AppendNegative(LinkedList * lt, NodePtr na)
{
	//operation:appent some nodes of one linked list to another linked list
	while (na)
	{
		na->data.coefficient=0-na->data.coefficient;
		if (!AddElement(lt, &na->data))
			return false;
		na = na->next;
	}
	return true;
}

bool InitList(LinkedList * l)
{
	//operation:initialize a linked list(polynomial)
	l->head = l->tail = (NodePtr)malloc(NODE_SIZE);
	if (!l->head)			//fail to apply room
		exit(0);
	l->head->next = NULL;
	l->count = 0;
	return true;
}

bool CreatePolynomial(LinkedList * l)
{
	//operation:create a polynomial(accept user's input)
	int n = 0;
	Element e;
	puts("Please input how many items in the polynomial.");
	scanf("%d", &n);
	for (; n > 0; --n)
	{
		puts("Please input the item's coefficient and exponent.");
		scanf("%f%d", &e.coefficient, &e.exponent);
		if (e.coefficient != 0.)
		{
			if (!AddElement(l, &e))			//fail to add
				return false;
		}
		else
		{
			puts("Invalid! Coefficient shouldn\'t be 0!");
			++n;
		}
	}
	return true;
}

bool LocateELement(LinkedList * l, const Element * e, NodePtr * q, 
				bool(*cmp)(const Element *, const Element *))
{
	//operation:decide whether the element(item)'s exponent 
	//in a list(polynomial)
	NodePtr p = l->head->next;
	*q = NULL;
	while (p)
	{
		if (cmp(&p->data, e))		//if the exponents are equal
		{
			*q = p;
			return true;
		}
		p = p->next;
	}
	return false;
}

void CopyList(LinkedList * target, LinkedList * source)
{
	//operation:copy one list to another
	if (source->head == NULL)
		return;
	AppendPositive(target, source->head->next);
}

bool IsEqual(const Element * a, const Element * b)
{
	//operation:decide whether two elements(item in polyment)'s exponent 
	//are equal
	if (a->exponent == b->exponent)
		return true;
	return false;
}

bool IsGreater(const Element * a, const Element * b)
{
	//operation:decide whether two elements(item in polyment)'s exponent 
	//are equal
	if (a->exponent > b->exponent)
		return true;
	return false;
}

short CompareExponent(const Element * a, const Element * b)
{
	//operation:compare two exponents 
	if (a->exponent > b->exponent)
		return 1;
	else if (a->exponent < b->exponent)
		return -1;
	else
		return 0;
}

void DestroyPolynomial(LinkedList * l)
{
	//operation:destroy a linked list(polynomial)
	NodePtr p1 = l->head;
	NodePtr p2 = p1->next;
	if (!p1)
		return;
	while (p2)
	{
		free(p1);
		p1 = p2;
		p2 = p2->next;
	}
	free(p1);
	l->count = -1;
}

void ResetPolynomial(LinkedList * l)
{
	//operation:reset a linked list(polynomial)
	DestroyPolynomial(l);
	InitList(l);
}

void PrintPolynomial(const Polynomial * p)
{
	//operation:print a polynomial
	bool IfFirst = true;		//print the frist element
	NodePtr cur = p->head->next;
	if (PolynomialLength(p) == 0)
		puts("Empty");
	else
		while (cur)
		{
			if (!IfFirst)
			{
				if (cur->data.coefficient > 0)
					putchar('+');
			}
			else
				IfFirst = false;
			if(cur->data.coefficient!=1.&&cur->data.coefficient!=-1.)
				printf("%.0f", cur->data.coefficient);
			if (cur->data.coefficient == -1.)
				putchar('-');
			switch (cur->data.exponent)
			{
			default:
				printf("X^%d", cur->data.exponent);
				break;
			case 0:
				break;
			case 1:
				putchar('X');
			}
			cur = cur->next;
		}
}

size_t PolynomialLength(const Polynomial * p)
{
	//operation:obtain the length(the number of items) of a polynomial
	return p->count;
}

void AddPolynomial(Polynomial * pa, Polynomial * pb)
{
	//operation:addition operation for the polynomial
	NodePtr ha = pa->head;
	NodePtr hb = pb->head;			//head node
	NodePtr qa = ha->next;
	NodePtr qb = hb->next;			//fist item in polynomial
	float sum = 0;					//temporary variable used to store
									//the sum of two coefficient
	while (qa&&qb)					//qa and qb are not empty
	{
		switch (CompareExponent(&qa->data, &qb->data))
		{
		case -1:		//qa's exponent is less than qb's exponent
			ha = qa;
			qa = qa->next;
			break;
		case 0:			//qa's exponent is equal to qb's exponent
			sum = qa->data.coefficient + qb->data.coefficient;
			if (sum != 0.)
			{
				qa->data.coefficient = sum;
				ha = qa;
			}
			else
				DeleteNode(pa, ha, qa);
			DeleteNode(pb, hb, qb);
			qb = hb->next;
			qa = ha->next;
			break;
		case 1:			//qa's exponent is greater than qb's exponent
			InsertNode(pa, ha, &qb->data);
			DeleteNode(pb, hb, qb);
			ha = ha->next;
			qb = hb->next;
		}
	}
	if (PolynomialLength(pb) != 0)
		AppendPositive(pa, qb);
	DestroyPolynomial(pb);
}

void SubtractPolynomial(Polynomial * pa, Polynomial * pb)
{
	//operation:subtraction operatoin for the polynomial
	NodePtr ha = pa->head;
	NodePtr hb = pb->head;			//head node
	NodePtr qa = ha->next;
	NodePtr qb = hb->next;			//fist item in polynomial
	float sum = 0;					//temporary variable used to store
									//the sum of two coefficient
	while (qa&&qb)					//qa and qb are not empty
	{
		switch (CompareExponent(&qa->data, &qb->data))
		{
		case -1:		//qa's exponent is less than qb's exponent
			ha = qa;
			qa = qa->next;
			break;
		case 0:			//qa's exponent is equal to qb's exponent
			sum = qa->data.coefficient - qb->data.coefficient;
			if (sum != 0.)
			{
				qa->data.coefficient = sum;
				ha = qa;
			}
			else
				DeleteNode(pa, ha, qa);
			DeleteNode(pb, hb, qb);
			qb = hb->next;
			qa = ha->next;
			break;
		case 1:			//qa's exponent is greater than qb's exponent
			qb->data.coefficient = 0 - qb->data.coefficient;
			InsertNode(pa, ha, &qb->data);
			DeleteNode(pb, hb, qb);
			ha = ha->next;
			qb = hb->next;
		}
	}
	if (PolynomialLength(pb) != 0)
		AppendNegative(pa, qb);
	DestroyPolynomial(pb);
}

void MultiplyPolynomial(Polynomial * pa, Polynomial * pb)
{
	//operation:multiplication operation for the polynomial
	Polynomial temp, product;
	NodePtr qa, qb;
	Element e;
	InitList(&temp);
	InitList(&product);
	qa = pa->head->next;
	qb = pb->head->next;
	while (qa)			//qa hasn't pointed the last node
	{
		while (qb)		//qb hasn't pointed the last node
		{
			e.coefficient = qa->data.coefficient*qb->data.coefficient;
			e.exponent = qa->data.exponent+qb->data.exponent;
			AddElement(&temp, &e);
			qb = qb->next;
		}
		AddPolynomial(&product, &temp);
		InitList(&temp);	//for temp has already been destroyed
							//initializeing it can reset the linked list
		qb = pb->head->next;
		qa = qa->next;
	}
	DestroyPolynomial(pb);
	ResetPolynomial(pa);
	InitList(pa);
	AppendPositive(pa, product.head->next);
	//pa will carry the product
}