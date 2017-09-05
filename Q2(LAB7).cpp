#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* start=NULL;
struct node* createnode()
{
	struct node* n;
	n=(struct node*)malloc(sizeof(node));
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
void insertnodeatpos(int data,int n)
{
	struct node* temp=createnode();
	temp->data=data;
	if(n==1 || n==1)
	{
		if(start==NULL && n==1)
	{
		start=temp;
		return;	
	}
	start->prev=temp;
	temp->next=NULL;
	temp->next=start;
	start=temp;
	return;
}
	struct node* t=start,*temp2;
	for(int i=0;i<n-2;i++)
	t=t->next;
	temp->next=t->next;
	temp->prev=t;
	t->next=temp;
	if(temp->next!=NULL)
	{
		temp2=temp->next;
		temp2->prev=temp;
	}
}
void deletenode(int n)
{
	struct node *t=start;
	if(n==1)
	{
		start=(start)->next;
		start->next->prev=NULL;
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
	insertnode(&start,1);insertnode(&start,2);insertnode(&start,3);insertnode(&start,4);insertnode(&start,5);
	print(start);
	int a[30],j=0;	
	struct node* temp=start;
	while(temp->next!=NULL)
	{
		a[j]=temp->data+temp->next->data;
		j++;
		temp=temp->next;
	}
	for(int i=0;i<4;i++)
	cout<<a[i]<<endl;
	j=0;
	int p=0,k=2;
	while(p<4)
	{
		insertnodeatpos(a[j],k);
		j++;
		p++;
		k=k+2;
	}
	cout<<"after addition"<<endl;
	print(start);
}
