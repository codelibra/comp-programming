//shivi..coding is adictive!!
//Segregate even and odd nodes in a Linked List
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

void push(Node **start,int k)
{
	Node *temp=(Node *)malloc(sizeof(struct Node));
	temp->data=k;
	temp->next=*start;
	*start=temp;
}

void print(Node *start)
{
	while(start)
	{
		cout<<start->data<<" ";
		start=start->next;
	}
}

void segregate(Node *start)
{
	Node *odd=NULL,*even=NULL,*head1,*head2;
	
	while(start)
	{
		if((start->data)%2==0)
		{
			if(even==NULL)
			{head1=start;even=head1;}
			else
			{even->next=start;even=even->next;}
		}
		else
		{
			if(odd==NULL)
			{head2=start;odd=head2;}
			else
			{odd->next=start;odd=odd->next;}
		}
		start=start->next;
	}
	even->next=NULL;
	odd->next=head1;
	//print(head1);
	print(head2);
}

int main()
{
	Node *start=NULL;
	push(&start,10);push(&start,61);push(&start,65);push(&start,14);push(&start,32);push(&start,20);
	segregate(start);
}
