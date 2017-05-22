//shivi..coding is adictive!!
//Add two numbers represented by linked lists | Set 1
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
	if(!start)	
	return;
	else
	print(start->next);
	cout<<start->data<<" ";
}

Node* Add(Node *start,Node *start2)
{
	Node *add=NULL;
	int carry=0;
	while(start && start2)
	{
		int data=start->data+start2->data+carry;
		if(data<10)
		{
		push(&add,data);
		carry=0;
		}
		else
		{
			data=data%10;
			carry=1;
			push(&add,data);
		}
		start=start->next;
		start2=start2->next;
	}
	cout<<endl;
//	print(add);
	

	while(start)
	{
		int data=start->data+carry;
		if(data<10)
		{
		push(&add,data);
		carry=0;
		}
		else
		{
			data=data%10;
			carry=1;
			push(&add,data);
		}
		start=start->next;
	}
	while(start2)
	{
		int data=start2->data+carry;
		if(data<10)
		{
		push(&add,data);
		carry=0;
		}
		else
		{
			data=data%10;
			carry=1;
			push(&add,data);
		}
		start=start->next;
	}
	cout<<endl;
	while(add)
	{
		cout<<add->data<<" ";
		add=add->next;
	}
}

int main()
{
	Node *start=NULL,*start2=NULL;
	push(&start,1);push(&start,6);push(&start,5);push(&start,4);push(&start,3);push(&start,2);push(&start,6);push(&start,4);push(&start,1);
	push(&start2,4);push(&start2,1);push(&start2,7);push(&start2,9);push(&start2,5);push(&start2,9);
	print(start);
	cout<<endl;
	print(start2);
	Add(start,start2);
	
}
