/*****************************************
 *     DataStructures--Linear list       *
 *         Experiment program            *
 *        Developed by Sam Liu           *
 * Only for study and education purpose. *
 * The author has no responsibility      *
 *   for the errors or omissions!        *
 *****************************************/

#ifndef LINEAR_LIST_HEAD
#define LINEAR_LIST_HEAD

#define LIST_INIT_SIZE 100		//linear list's initial size
#define LIST_INCREMENT 10		//increment

struct Node
{
	int a;
};
struct List
{
	Node *elem;					//the address of storage
	int length;					//current length
	int listsize;				//size in all
};
typedef struct List SqList;

//function prototype

//begin of interface functions

//operation:initial a list
//pre-conditon:l points to a squence list(linear list)
//pose-condition:Create a new empty linear list
//				return true if succeed,otherwise false
bool InitList(SqList *l);

//operation:clear a list
//pre-conditoin:linear list l has already existed
//post-condition:linear list l will be empty
void ClearList(SqList *l);

//operation:destroy a list
//pre-condition:linear list l has already existed
//post-condition:every nodes in l will be destroyed
void DestroyList(SqList *l);

//operation:decide if the list l is an empty one
//pre-condition:l points to an initialized list
//post-condition:return true if it's empty, otherwise false
bool ListIsEmpty(const SqList *l);

//operation:get list's length
//pre-condition:l points to an initialized list
//post-conditon:return this list's length
int ListLength(const SqList *l);

//operation:get a node in the list l
//pre-condition:l points to a list and l is not empty
//post-condition:i is the number of the node that you want
//				 use form arguement e to return this element
//				 and the funtion wil return true if succeed
bool GetNode(const SqList *l, int i, struct Node *e);

//operation:find one element's location in the list
//pre-condition:l points to a list,e is the element you want to find, 
//				  compare() is the function to compare element
//post-condition:return the first element's sequence number if it's successful, otherwise 0
int LocateElem(const SqList *l, const struct Node *e, bool(*compare)(const struct Node*,const struct Node*));

//operation:To get the prior element of the current element
//pre-condition:l points to a list,cur_e is the current element,
//				pre_e is the prior element that will be returned.
//post-condition:if the curent element has no prior one, it will return false
bool ProirElem(const SqList *l, const struct Node *cur_e, struct Node *pre_e);

//operation:To get the next element of the current element
//pre-condition:l points to a list, cur_e is the current element,
//				next_e is the next element that will be returned.
//post-condition:if the current element has no next one, it will return false
bool NextElem(const SqList *l, const struct Node *cur_e, struct Node *next_e);

//operation:To insert a node into the list
//pre-condition:l points to a list, e is the node that you want to insert
//				you will insert the node before i,in a plain word,
//				the new inserted node's sequence number will be i.
//post-condition:return TRUE if it's successful,otherwise FLASE
bool ListInsert(SqList *l, int i, const struct Node *e);

//operation:To delete a node from the list
//pre-condition:l points to a list, you will delete number i node,
//post-condition:the node you delete will copy to e,
//				 return TRUE if it's successful,otherwise FALSE
bool ListDelete(SqList *l, int i, struct Node *e);

//operation:To traverse all the nodes in the list
//pre-condition:l points to a list,visit is the function that you want to apply
void ListTraverse(SqList *l, void(*visit)(struct Node *));

//operation:To merge two lists
//pre-condition:la and lb point to two lists
//post-condition:elements in lb will be inserted into the la(la hasn't this element)
//				 the length of la will be enlargeed.
void ListUnion(SqList *la, SqList *lb);

//operation:To merge two lists that elements in increasing order
//pre-condition:la and lb and lc point to 3 lists
//				la and lb's elements are in increasing order
//post-condition:lc has ala the elements of la and lb
//				 and lc is also increasing order
void ListMerge(const SqList *la, const SqList *lb, SqList *lc);

//end of interface functions
//begin of local functions

//operation:copy one node to another
//pre-condition:e1 points to a node, e1 points to another node
//post-condition:copy e2 to e1
void CopyNode(struct Node *e1, struct Node *e2);

//operation:decide if the two elements are equal
//pre-condition:e1 and e2 are two nodes of the list
//post-condition:return TRUE if they are equal, otherwise FALSE
bool IfNodesEqual(const struct Node *e1, const struct Node *e2);

//operation:decide if the first element is bigger than the latter one
//pre-condition:e1 and e2 point two nodes respectively in the list
//post-condition:return TRUE if former one is bigger than latter one
//				 return FALSE otherwise
bool IfBigger(const struct Node *e1,const struct Node *e2);

//operation:decide if the fist element is smaller than the latter one
//pre-condition:e1 and e2 point two nodes resepctively in the list
//poot-condition:return TRUE if the former one is bigger than the latter one
//				 return FALSE otherwise
bool IfSmaller(const struct Node *e1, const struct Node *e2);

//operation:display the node
//pre-condition:e points to a node
//post-condition:display e
void Display(struct Node *e);

//end of local functions
#endif // !LINEAR_LIST_HEAD
