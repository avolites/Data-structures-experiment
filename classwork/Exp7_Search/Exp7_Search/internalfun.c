/*****************************************
 *       Experiment 7 -- Search          *
 *         Static Search Table           *
 *    Sequence Search & Binary Search    *
 *     Developed by Gaoxiang Liu         *
 *             Nov. 2017                 *
 *****************************************
 *      Last Modify: Nov. 19, 2017       *
 *****************************************/

 #include "internalfun.h"
 #include <stdio.h>

void PrintNode(Node * e)
{
	//operation: print a node's data
	printf("%d ",e->key);
}

bool IsEqual(KeyType a, KeyType b)
{
	printf("Comparing the key %d with %d\n", a, b);
	return EQ(a,b);
}

void Print_ne(KeyType key)
{
	printf("The key %d doesn't exist.\n",key);
}

void Print_sa(KeyType key)
{
	printf("The key %d has been successfully added.\n", key);
}

void Comp_Times(uint32_t n)
{
	//operation: print how many times have compared
	printf("\nCompared for %d time(s).",n);
}
