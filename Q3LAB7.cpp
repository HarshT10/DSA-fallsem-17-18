#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *prev;
	struct node *next;	
};
struct node *start=NULL;
struct node * createnode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(node));
	n->next=NULL;
	n->prev=NULL;	
	return n;
}
void insertnode(struct node **start,int data)
{
	struct node *temp=createnode();
	temp->data=data;
	if(*start==NULL)
	{
		*start=temp;
		 return;
	}
	(*start)->prev=temp;
	temp->next=(*start);
	*start=temp;
}
void deletenode(struct node **start,int n)
{
	struct node *t=*start;
	if(n==1)
	{
		*start=(*start)->next;
		(*start)->next->prev=NULL;
		return;
	}
	for(int i=0;i<n-2;i++)
	t=t->next;
	t->next->prev=t;
	t->next=t->next->next;
}
void print(struct node* start)
{
	while(start!=NULL)
	{
		cout<<start->data<<endl;
		start=start->next;
	}
}
int main()
{
	int n1,n2;
	insertnode(&start,72);insertnode(&start,65);insertnode(&start,15);insertnode(&start,78);
	insertnode(&start,56);insertnode(&start,34);insertnode(&start,12);
	print(start);
	cin>>n1>>n2;
	for(int i=0;i<n2-n1+1;i++)
	deletenode(&start,n1);
	print(start);
}
