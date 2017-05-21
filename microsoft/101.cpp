//shivi..coding is adictive!!
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
		cout<<start->data<<" ";
		start=start->next;
	}
}
int Nthfromend(Node *start,int n)
{
	Node *a=start,*b=start;
	while(n-- && b->next!=NULL)b=b->next;
	
	while(b)
	{
		b=b->next;
		a=a->next;
	}
	return a->data;
}

int main()
{
	struct Node *start=NULL;
	push(&start,0);push(&start,-10);push(&start,20);push(&start,30);push(&start,40);push(&start,50);
	Print(start);
	
	cout<<endl<<Nthfromend(start,
	3);
}
