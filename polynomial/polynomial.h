/*
 * Appliance of Linked List--Polynomial
 *
 * This head file only contain the type and
 * function prototypes of this appliance.
 *
 * This may be one of possible methods to store and operate the polynomials.
 *
 * Developed by Gaoxiang Liu (Sam)
 * Only for study and education.
 * The author will take no responsibility for the errors or omissions.
 */

#pragma once

#include <stdbool.h>
#include <stdio.h>

//instructoin:The polynomial will be stored in memory in the linked list
//            structure, that means all each item in a polynomial will be one
//            node in the linked list. Each node's data contains two variable, 
//            coefficient and exponent. And the head node is an empty node.
//            From the head node to tail node, the exponent is in increment
//            order.
//For example:To represent 3x+2x^2+10x^5, there are 4 nodes in all

#define NODE_SIZE sizeof(Node)

//type define

//represent the item in polynomial as data type in linked list
typedef struct
{
	float coefficient;
	int exponent;
} Element;

//linked list's node type
typedef struct Node
{
	Element data;
	struct Node * next;
} Node, *NodePtr;

//linked list type
typedef struct
{
	NodePtr head;		//points the head node of a list
						//head node will contain no data
	NodePtr tail;		//points the tail node of a list
	size_t count;		//the number of the nodes in a list
} Polynomial,LinkedList;

//local function prototypes

//operation:add an item of a polynomial(used by CreatePolynomial())
//pre-condition:p is the polynomial,e is the item(data)
//post-conditoin:return true if it succeeds, false otherwise
static bool AddElement(Polynomial *p, const Element *e);

//operation:delete a node in the linked list
//pre-condition:l points to the list,
//				pp is the prior node of the node will be deleted
//				p is the node that will be deleted
//post-condition:return true if it succeeds, false otherwise
static bool DeleteNode(LinkedList *l, NodePtr pp, NodePtr p);

//operation:insert a node in the linked list
//pre-condition:l points to the list,
//				pp is the location where the new node will be added after it
//				e is the new node's data that will be inserted
//post-condition:return true if it succeeds, false otherwise
static bool InsertNode(LinkedList *l, NodePtr pp, const Element *e);

//operation:append some nodes of one linked list to another linked list
//pre-condition:lt is the target list,
//				na is the list's node pointer, which the rest of list 
//				will be appended to lt
//post-condition:return true if it succeeds, false otherwise
//				 all the appended data will be as same as before
static bool AppendPositive(LinkedList *lt, NodePtr na);

////operation:appent some nodes of one linked list to another linked list
//pre-condition:lt is the target list,
//				na is the list's node pointer, which the rest of list 
//				will be appended to lt
//post-condition:return true if it succeeds, false otherwise
//				 if the appended data's coefficient is positive,
//				 it will become negative
//				 and vice versa
static bool AppendNegative(LinkedList *lt, NodePtr na);

//public function prototypes

//operation:initialize a linked list(polynomial)
//pre-condition:l points to a linked list
//post-condition:return true if it succeeds, false otherwise
bool InitList(LinkedList *l);

//operation:create a polynomial(accept user's input)
//pre-condition:l points to a linked list
//post-condidion:return true if it succeeds, false otherwise
bool CreatePolynomial(LinkedList *l);

//operation:decide whether the element(item)'s exponent in a list(polynomial)
//pre-condition:l points to a linked list,e is the element that user
//				wants to find, cmp is the compare function's address
//post-condition:if the exponent of e in the list, return true and q will carry
//				 the node's address, otherwise, return false
bool LocateELement(LinkedList *l, const Element *e, NodePtr *q,
					bool(*cmp)(const Element *, const Element *));

//operation:copy one list to another
//pre-condition:target and source are two lists
//post-condition:the list source will be copied into target
//				 source will be remained
void CopyList(LinkedList *target, LinkedList*source);

//operation:decide whether two elements(item in polyment)'s exponent are equal
//pre-condition:a and b are the two elements respectively
//post-condition:return true if they're equal, false otherwise
bool IsEqual(const Element *a, const Element *b);

//operation:decide whether two elements(item in polyment)'s exponent are equal
//pre-condition:a and b are the two elements respectively
//post-condition:return true if a's > b's, false otherwise
bool IsGreater(const Element *a, const Element *b);

//operation:compare two exponents 
//pre-condition:a and b are two elements respectively
//post-conditoin:return 1 if a's exponent is Greater than b's
//				 return 0 if they are equal
//				 reutrn -1 if b's exponent is Greater than a's
short CompareExponent(const Element *a, const Element *b);

//operation:destroy a linked list(polynomial)
//pre-condition:l points to a linked list
//post-condition:the liked list(polynomial) will be destroyed
void DestroyPolynomial(LinkedList *l);

//operation:reset a linked list(polynomial)
//pre-condition:l points to a linked list
//post-condition:all the data will be cleaned
void ResetPolynomial(LinkedList *l);

//operation:print a polynomial
//pre-condition:p points to a polynomial
//post-condition:nothing in the list will be changed
void PrintPolynomial(const Polynomial *p);

//operation:obtain the length(the number of items) of a polynomial
//pre-condition:p points to a polynomial
//post-conditoin:return the lenght of the list, and nothing will be chagned
size_t PolynomialLength(const Polynomial *p);

//operation:addition operation for the polynomial
//pre-condition:pa and pb are two polynomials
//post-condition:pa=pa+pb, in other words, pb will be destroyed
//				 pa will carry the final outcome
void AddPolynomial(Polynomial *pa, Polynomial *pb);

//operation:subtraction operatoin for the polynomial
//pre-condition:pa and pb are two polynomials
//post-condition:pa=pa-pb, in other words, pb will be destroyed
//				 pa will carry the final outcome
void SubtractPolynomial(Polynomial *pa, Polynomial *pb);

//operation:multiplication operation for the polynomial
//pre-condition:pa and pb are two polynomials
//post-condition:pa=pa*pb, in other words, pb will be destroyed
//				 pa will carry the final outcome
void MultiplyPolynomial(Polynomial *pa, Polynomial *pb);