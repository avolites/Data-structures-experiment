#include "linkedlist_head.h"
#include <iostream>

using namespace std;

//definition of functions

bool InsertNode(Lilist **l,int i,struct Element e){
	Lilist *temp=(Lilist*)malloc(NODE_SIZE);//create new node
	if(!temp)								//overflow
		return false;
	temp->data=e;
	temp->next=NULL;
	if(*l==NULL){							//linked list is empty
		*l=temp;
	}
	else{
		Lilist *p=*l;
		int j=0;
		if(i<0){
			free(temp);
			return false;
		}
		if(i==0){							//new node is head
			temp->next=p;
			*l=temp;
		}
		else{								//new node is not head
			while(p->next&&j<i-1){
				p=p->next;
				++j;
			}
			temp->next=p->next;
			p->next=temp;
		}
	}
	return true;
}
bool DeleteNode(Lilist **l,int i,struct Element *e){
	if(i<0)
		return false;
	if(i==0){
		Lilist *p=*l;
		*l=(*l)->next;
		free(p);
	}
	else{
		int j=0;
		Lilist *previous=*l;
		while(previous->next&&j<i-1){
			previous=previous->next;
			++j;
		}
		if(!previous->next)				//error
			return false;
		Lilist *current=previous->next;
		previous->next=current->next;
		free(current);
	}
	return true;
}
void ClearList(Lilist *l){
	Lilist *temp=l;
	while(l){
		l=l->next;
		free(temp);
		temp=l;
	}
}
void DisplayList(Lilist *l){
	if(!l)			//empty
		printf("Empty\n");
	else{
		while(l){
			printf("%d ",l->data.a);
			l=l->next;
		}
	}
}
bool GetData(Lilist *l,int i, struct Element *e){
	if(!l){				//empty
		return false;
	}
	else{
		Lilist *p=l;
		int j=0;
		while(p&&j<i){
			p=p->next;
			++j;
		}
		if(!p)			//location i is wrong
			return false;
		*e=p->data;		//fetch the data
	}
	return true;
}
bool CreateList_FIFO(Lilist **l){
	if(*l!=NULL)
		return false;
	else{
		int count=0;
		int n=0;		//if it is 0, the node is head
		cout<<"Please input the number of nodes you want to add."<<endl;
		cin>>count;
		if(count<=0)
			return false;
		while(count>0){
			Lilist *p1=(Lilist *)malloc(NODE_SIZE),*p2;
			cout<<"Please input the node's value."<<endl;
			cin>>p1->data.a;
			p1->next=NULL;
			if(n==0){				//head
				*l=p1;
				p2=p1;
				n++;
			}
			else{
				p2->next=p1;
				p2=p1;
			}
			count--;
		}
	}
	return true;
}
bool CreateList_LIFO(Lilist **l){
	if(*l!=NULL)
		return false;
	else{
		int count=0;
		int n=0;		//if it is 0, the node is head
		cout<<"Please input the number of nodes you want to add."<<endl;
		cin>>count;
		if(count<=0)
			return false;
		while(count>0){
			Lilist *p1=(Lilist *)malloc(NODE_SIZE),*p2;
			cout<<"Please input the node's value."<<endl;
			cin>>p1->data.a;
			p1->next=NULL;
			if(n==0){			//head
				*l=p1;
				p2=p1;
				n++;
			}
			else{
				p1->next=p2;
				*l=p1;
				p2=p1;
			}
			count--;
		}
	}
	return true;
}
