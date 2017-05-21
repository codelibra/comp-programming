//shivi..coding is adictive!!
//reverse in groups
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

Node * reverse(Node *start,int k)
{
	Node *current=start;
	Node *prev=NULL,*nxt;
	
	int count=0;
	
	while(current!=NULL && count<k)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		++count;
	}
	
	if(nxt!=NULL)
	{
		start->next=reverse(nxt,k);
	}
	
	return prev;
}


int main()
{
	Node *start=NULL;
	push(&start,10);push(&start,60);push(&start,65);push(&start,14);push(&start,32);push(&start,20);
	//MergeSort(&start);
	print(start);
	start=reverse(start,2);
	cout<<endl;
	print(start);
}
