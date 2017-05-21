//shivi..coding is adictive!!
//mergesort link list
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

void Divide(Node *head,Node **a,Node **b)
{
	if(head==NULL || head->next==NULL)
	{
		*a=head;
		*b=NULL;
		return;
	}
	Node *slow=head,*fast=head->next;
	
	while(fast)
	{
		fast=fast->next;
		if(fast)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	*a=head;
	*b=slow->next;
	slow->next=NULL;
}

Node * Merge(Node *a,Node *b)
{
	Node *ans=NULL;
	
	if(a==NULL)
	return b;
	else if(b==NULL)
	return a;
	
	if(a->data<=b->data)
	{
		ans=a;
		ans->next=Merge(a->next,b);
	}
	else
	{
		ans=b;
		ans->next=Merge(a,b->next);
	}
	return ans;
}

void MergeSort(Node **start)
{
	Node *head=*start;
	Node *a,*b;
	if(head==NULL || head->next==NULL)
	return;
	
	Divide(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	
	*start=Merge(a,b);
}

int main()
{
	Node *start=NULL;
	push(&start,10);push(&start,60);push(&start,65);push(&start,14);push(&start,32);push(&start,20);
	MergeSort(&start);
	print(start);
}
