//shivi..coding is adictive!!
//cycle detect
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

void push(Node **start,int k)
{
	Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=*start;
	temp->data=k;
	*start=temp;
}

void print(Node *start)
{
	while(start)
	{
		cout<<start->data<<" ";
		start=start->next;
	}
	cout<<endl;
}

void del(Node **start)
{
	Node *temp;
	while(*start)
	{
		temp=*start;
		*start=(*start)->next;
		delete temp;
	}
}

void reverse(Node **start)
{
	Node *current=*start,*prev=NULL,*nxt;
	
	while(current)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
	}
	*start=prev;
}

void CycleDetection(Node *start)
{
	Node *slow=start,fast=start;
	while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			cout<<"cycle found";
			return;
		}
	}
	
}

int main()
{
	struct Node *start=NULL;
	push(&start,0);push(&start,-10);push(&start,20);push(&start,30);push(&start,40);push(&start,50);
	print(start);
	//del(&start);
	//print(start);
	reverse(&start);
	print(start);
}
