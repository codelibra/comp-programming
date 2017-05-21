//shivi..coding is adictive!!
//Write a C function to print the middle of a given linked list
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

int middle1(Node *start)
{
	Node *slow=start,*fast=start;
	if(start)
	{
		while(fast->next!=NULL && fast->next->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
	}
	return slow->data;
}

int middle2(Node *start)
{
	Node *mid=start;
	int count=0;
	while(start)
	{
		if(count&1)
		mid=mid->next;
		
		++count;
		start=start->next;
	}
	return mid->data;
}


int main()
{
	struct Node *start=NULL;
	push(&start,0);push(&start,-10);push(&start,20);push(&start,30);push(&start,40);push(&start,50);
	print(start);
	cout<<middle1(start)<<endl<<middle2(start)<<endl;
}
