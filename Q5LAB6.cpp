#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
struct node *start2=NULL;
struct node *createnode()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(node));
	return n;
}
void insertnode(struct node** start,int data)
{
    struct node* temp,*t;
    temp=createnode();
    temp->data=data;
    temp->link=NULL;
    if(*start==NULL)
    {
        *start=temp;
    }
    else
    {
        t=*start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void deletenode(int n)
{
	struct node *t=start;
	if(n==1)
	{
		start=t->link;
		free(t);
		return;
	}
	for(int i=0;i<n-2;i++)
	t=t->link;
	struct node *temp=t->link;
	t->link=temp->link;
	free(temp);
}
void print(struct node *k)
{
    while(k!=NULL)
    {
    	cout<<k->data<<endl;
   	 	k=k->link;
	}
}
bool removeduplicates(struct node *head, int data)
{
    struct node *t=head;
    while (t!=NULL)
    {
        if(t->data==data)
            return 1;
        	t=t->link;
    }
    return 0;
}
int main()
{
	insertnode(&start,1);
	insertnode(&start,2);
	insertnode(&start,3);
	insertnode(&start,4);
	insertnode(&start,4);
	insertnode(&start,5);
	struct node* temp=start;
	while(temp)
	{
		if(!removeduplicates(start2,temp->data))
		insertnode(&start2,temp->data);
		temp=temp->link;
	}
	cout<<"after removal"<<endl;
	print(start2);
	
}
