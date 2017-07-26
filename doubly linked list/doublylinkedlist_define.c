#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

//define of functions

bool InitList(DuLinkList l)
{
	//firstly, create a empty head node
	if (!(l->head = (struct Node*)malloc(NODE_SIZE)))	//if fail
		return false;
	else												//succeed
	{
		l->tail = l->head;
		l->head->next = NULL;
		l->head->prior = NULL;
		l->length = 0;
		return true;
	}
}

void DestroyList(DuLinkList l)
{
	struct Node *p1 = l->head;
	struct Node *p2 = l->head->next;
	if (!p2)			//empty list, free head node only
		free(p1);
	else
	{
		while (p2)
		{
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}
		free(p1);
	}
	l->length = -1;
}
bool IsEmpty(DuLinkList l)
{
	if (l->length > 0)
		return false;
	return true;
}
bool InsFirst(DuLinkList l, struct Element e)
{
	struct Node *temp;
	if (!(temp = (struct Node *)malloc(NODE_SIZE)))	//if fail
		return false;
	temp->data = e;
	temp->next = l->head->next;
	if(l->length>0)								//if it is not emtpy
		l->head->next->prior = temp;
	l->head->next = temp;
	temp->prior = l->head;
	l->length++;
	if (l->length == 1)
		l->tail = temp;
	if (l->length == 0)
		l->tail = l->head;
	return true;
}
bool DelFirst(DuLinkList l, struct Element * e)
{
	struct Node *temp;
	if (l->length == 0)
		return false;
	temp = l->head->next;
	*e = l->head->next->data;					//carry the data
	if(l->length>0)
		temp->next->prior = l->head;
	l->head->next = temp->next;
	free(temp);
	l->length--;
	if (l->length == 0)
		l->tail = l->head;
	return true;
}
bool Append(DuLinkList l, struct Element e)
{
	struct Node *temp;
	if (!(temp = (struct Node *)malloc(NODE_SIZE)))	//if fail
		return false;
	temp->data = e;
	l->tail->next = temp;
	temp->prior = l->tail;
	temp->next = NULL;
	l->tail = temp;
	l->length++;
	return true;
}
bool Remove(DuLinkList l, int pos, struct Element * e)
{
	struct Node *p = l->head->next;
	int i = 1;								//count
	if (!p || pos > l->length || pos < 1)	//list is empty or position is out of range
		return false;
	while (i < pos)
	{
		i++;
		p = p->next;
	}
	//delete
	*e = p->data;						//carry the data
	p->prior->next = p->next;
	if (p != l->tail)
		p->next->prior = p->prior;
	else
		l->tail = p->prior;
	free(p);
	l->length--;
	return true;
}
bool InsBefore(DuLinkList l, int pos, struct Element e)
{
	struct Node *temp,*p=l->head->next;
	int i = 1;											//count
	if (!(temp = (struct Node*)malloc(NODE_SIZE)))		//if fail
		return false;
	if (pos > l->length || pos < 0)						//position out of range
		return false;
	if (l->length == 0)
	{
		Append(l, e);
		return true;
	}
	else
	{
		while (i < pos)
		{
			i++;
			p = p->next;
		}
		temp->data = e;
		temp->prior = p->prior;
		p->prior->next = temp;
		temp->next = p;
		p->prior = temp;
		l->length++;
		return true;
	}
}
bool InsAfter(DuLinkList l, int pos, struct Element e)
{
	struct Node *temp, *p = l->head;
	int i = 0;											//count
	if (!(temp = (struct Node*)malloc(NODE_SIZE)))		//if fail
		return false;
	if (pos > l->length || pos < 0)						//position out of range
		return false;
	if (l->length == pos || l->length == 0)
	{
		Append(l, e);
		return true;
	}
	else
	{
		while (i < pos)
		{
			i++;
			p = p->next;
		}
		temp->data = e;
		temp->next = p->next;
		p->next->prior = temp;
		temp->prior = p;
		p->next = temp;
		l->length++;
		return true;
	}
}
bool SetCurElem(DuLinkList l, int pos, struct Element e)
{
	struct Node *p = l->head->next;
	int i = 1;							//count
	if (l->length == 0)					//empty list
		return false;
	if (pos <= 0 || pos > l->length)	// out of range
		return false;
	while (i < pos)
	{
		i++;
		p = p->next;
	}
	p->data = e;
	return true;
}
bool GetCurElem(DuLinkList l, int pos, struct Element *e)
{
	struct Node *p = l->head->next;
	int i = 1;
	if (l->length == 0)
		return false;
	if (pos <= 0 || pos > l->length)		//out of range
		return false;
	while (i < pos)
	{
		i++;
		p = p->next;
	}
	*e = p->data;
	return true;
}
bool GetElem(DuLinkList l, struct Node * pos, struct Element * e)
{
	if (l->length == 0)
		return false;
	*e = pos->data;
	return true;
}
bool ListTraverse(DuLinkList l, void(*fun)(Element))
{
	struct Node *p = l->head->next;
	if (l->length == 0)
		return false;
	else
		while (p != NULL)
		{
			fun(p->data);
			p = p->next;
		}
	return true;
}
void PrintElem(struct Element e)
{
	printf("%d ", e.a);
}
bool CreateDoublyLinkedList_FIFO(DuLinkList l)
{
	int n, i = 0;
	struct Element e;
	puts("Please input the number of nodes you want to add:");
	scanf("%d", &n);
	if (!InitList(l))
		return false;
	while (i < n)
	{
		puts("Input  the data:");
		scanf("%d", &e.a);
		Append(l, e);
		i++;
	}
	return true;
}
bool CreateDoublyLinkedList_LIFO(DuLinkList l)
{
	int n, i = 0;
	struct Element e;
	puts("Please input the number of nodes you want to add:");
	scanf("%d", &n);
	if (!InitList(l))
		return false;
	while (i < n)
	{
		puts("Input  the data:");
		scanf("%d", &e.a);
		InsFirst(l, e);
		i++;
	}
	return true;
}
int compare(struct Element a, struct Element b)
{
	return a.a - b.a;
}
bool MergeList(DuLinkList la, DuLinkList lb, DuLinkList lc, int(*compare)(struct Element, struct Element))
{
	//la and lb must be in non-descent order
	struct Node *ha = la->head;	//head
	struct Node *hb = lb->head;
	struct Node *pa = ha->next;	//fisrt node
	struct Node *pb = hb->next;
	struct Element a, b;		//temporary variable
	if (!InitList(lc))
		return false;
	while (pa&&pb)				//pa and pb are not NULL
	{
		GetElem(la, pa, &a);	//acquire the data
		GetElem(lb, pb, &b);
		if (compare(a, b) <= 0)	//a<=b
		{
			Append(lc, pa->data);
			pa = pa->next;
		}
		else
		{
			Append(lc, pb->data);
			pb = pb->next;
		}
	}
	if (pa)					//la has remain
		while (pa)
		{
			Append(lc, pa->data);
			pa = pa->next;
		}
	else					//lb has remain
		while (pb)
		{
			Append(lc, pb->data);
			pb = pb->next;
		}
	DestroyList(la);
	DestroyList(lb);
	return true;
}