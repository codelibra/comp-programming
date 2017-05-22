//shivi..coding is adictive!!
//Write a function to get Nth node in a Linked List
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

void push(Node **start,int p)
{
	Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=p;
	temp->next=*start;
	*start=temp;
}

void Print(Node *start)
{
	while(start)
	{
		cout<<start->data<<endl;
		start=start->next;
	}
}

int NthNode(Node *start,int N)
{
	int count=0;
	while(start && count<N-1)
	{
		++count;
		start=start->next;
	}
	return start->data;
}

int main()
{
	Node *start=NULL;
	push(&start,10);
	push(&start,20);
	push(&start,30);
	push(&start,40);
	push(&start,50);
	push(&start,60);
	push(&start,70);
	Print(start);
	cout<<NthNode(start,5);
}
