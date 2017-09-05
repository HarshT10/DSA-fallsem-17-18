#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* link;
};
struct node *start=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node* createnode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(node));
    return n;
}

void insertnode(int data,struct node **start)
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
void print(struct node *start)
{
	struct node* k=start;
    while(k)
    {
    	cout<<k->data<<endl;
    	k=k->link;
	}
}
void deletenode(int n)
{
	struct node* temp1=start;
	if(n==1)
	{
		start=temp1->link;
	}
	else
	{
		for(int i=0;i<n-2;i++)
		temp1=temp1->link;
		struct node *temp2=temp1->link;
		temp1->link=temp2->link;
	}
}
int main()
{
	int n,data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter a number: ";
    	cin>>data;
		insertnode(data,&start);
	}
		print(start);
	struct node *temp=start;
	for(int i=0;i<n/2+1;i++)		
	{
		insertnode(temp->data,&start2);
		deletenode(1);	
		temp=temp->link;
	}
	cout<<"***"<<endl;
	print(start2);
	cout<<"***"<<endl;
	print(start);
	return 0;
}

