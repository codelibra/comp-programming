//shivi..coding is adictive!!
//Rotate a Linked List
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

void Rotate(Node  **start,int l)
{
	Node *head=*start;
	int count=1;
	while(head && count<l)
	{
		head=head->next;
		++count;
	}
	
	if(head==NULL)
	return;
	
	Node *k=head->next;
	while(k->next)
	k=k->next;
	
	k->next=*start;
	*start=head->next;
	head->next=NULL;
}

int main()
{
	Node *start=NULL;
	push(&start,10);push(&start,60);push(&start,65);push(&start,14);push(&start,32);push(&start,20);
	print(start);
	cout<<endl;
	Rotate(&start,4);
	print(start);
}
