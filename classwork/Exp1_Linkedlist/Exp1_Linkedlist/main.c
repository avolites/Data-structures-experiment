#include "interface.h"
#include "Linkedlist.h"
#include <string.h>

int main()
{
	LinkList l;
	CreateList_Sequence(&l, 0);		//reset the linked list in 
									//order to avoiding error
	Welcome(&l);
	return 0;
}