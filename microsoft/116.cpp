//shivi..coding is adictive!!
//reverse aternate K nodes
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

Node * reverse(Node *start,int k,int dongle)
{
	if(!dongle) dongle=1;
	else dongle=0;
	
	Node *current=start;
	Node *prev=NULL,*nxt;
	int count=0;
	if(dongle)
	{
		while(current!=NULL && count<k)
		{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		++count;
		}
		
		if(nxt!=NULL)
		start->next=reverse(nxt,k,dongle);
	
		return prev;
	}
	else
	{
		while(current!=NULL && count<k)
		{
		prev=current;	
		current=current->next;
		++count;
		}
		
		if(current!=NULL)
		prev->next=reverse(current,k,dongle);
		
		return start;
	}
}


int main()
{
	Node *start=NULL;
	push(&start,10);push(&start,60);push(&start,65);push(&start,14);push(&start,32);push(&start,20);
	//MergeSort(&start);
	print(start);
	start=reverse(start,2,0);
	cout<<endl;
	print(start);
}
