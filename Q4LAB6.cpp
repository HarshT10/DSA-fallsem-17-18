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
struct node *start3=NULL;
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
bool ispresent (struct node *head, int data)
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
	int n1,n2;
	cin>>n1;
	for(int i=0;i<n1;i++)
	insertnode(&start,i+1);
	cin>>n2;
	for(int i=0;i<n2;i++)
	insertnode(&start2,i+3);
	print(start);
	cout<<"**"<<endl;
	print(start2);
	struct node* temp=start;
	while(temp)
	{
		if(!ispresent(start2,temp->data))
		insertnode(&start3,temp->data);
		temp=temp->link;
	}
	cout<<"L1-L2 is "<<endl;
	print(start3);
}
