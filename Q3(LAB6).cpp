#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* link;
};
struct node* createnode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(node));
    return n;
}

struct node *start=NULL;
struct node *start2=NULL;
void insertnode(struct node** start)
{
    struct node* temp,*t;
    temp=createnode();
    cout<<"enter a number: ";
    cin>>temp->data;
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

void print(struct node *k)
{
    while(k!=NULL)
    {
    	cout<<k->data<<endl;
   	 	k=k->link;
	}
}
bool isPresent (struct node *head, int data)
{
    struct node *t=head;
    while (t!= NULL)
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
	insertnode(&start);
	cin>>n2;
	for(int i=0;i<n2;i++)
	insertnode(&start2);
	print(start);
	cout<<"**"<<endl;
	print(start2);
	struct node *temp=start;
	while(temp)
	{
		if(isPresent(start2,temp->data))
		cout<<"common elements: "<<temp->data<<endl;
		temp=temp->link;
	}
}
