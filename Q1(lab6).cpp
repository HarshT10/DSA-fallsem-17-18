#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* link;	
};
struct node* start=NULL;
struct node* createnode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(node));
    return n;
}
void insertbtw(int n1,int data)
{
	struct node *ac;ac=createnode();
	ac->data=data;
	struct node *temp;
	temp=createnode();temp=start;
	if(n1==0)
	{
		ac->link=start;
		start=ac;
		return;
	}
	for(int i=0;i<n1-1;i++)
	temp=temp->link;
	ac->link=temp->link;
	temp->link=ac;
}
void insertnode()
{
    struct node* temp,*t;
    temp=createnode();
    cout<<"enter a number: ";
    cin>>temp->data;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void print()
{
	struct node* k;k=createnode();
	k=start;
    while(k!=NULL)
    {
    	cout<<k->data<<endl;
    	 	k=k->link;
	}
}
int main()
{
	int n1,data;
	for(int i=0;i<5;i++)
	insertnode();print();
	//struct node* ac=NULL;
	cout<<"input data for ac: ";
	cin>>data;
	cin>>n1;
	insertbtw(n1,data);
	print();
}
