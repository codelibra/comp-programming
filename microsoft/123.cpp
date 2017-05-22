//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	char data;
	Node *next;
};

void push(int data,Node **start)
{
	Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=*start;
	*start=temp;
}

void Print(Node *start)
{
	while(start)
	{
		cout<<start->data<<" ";
		start=start->next;
		getch();
	}
	cout<<endl;
}

void flip(Node **start)
{
	if(*start==NULL || (*start)->next==NULL)
	return;
	
	Node *current=*start,*prev=NULL,*nxt,*head=*start;
	int count=2;
	*start=current->next;
	while(current && head)
	{
		nxt=current->next;
		if(count!=0)
		current->next=prev;
		else if(nxt==NULL)
		{head->next=current;head=head->next;}
		else 
		{head->next=nxt;head=current;count=2;}
		
		prev=current;
		current=nxt;
		--count;
	}
	head->next=NULL;
}

Node * flip2(Node *start)
{
	if(start==NULL)
	return NULL;
	else if(start->next==NULL)
	return start;
	
	Node *head=start,*others,*nxt;
	if(head->next)
	others=head->next;
	else if(others)
	others=head;
	
	nxt=others->next;
	others->next=head;
	
	
	head->next=flip2(nxt);
	return others;
}


int main()
{
	Node *start=NULL,*start2=NULL;
	push('A',& start);push('B',& start);//push('C',& start);push('D',& start);push('E',& start);//push('F',& start);
	Print(start);
	start2=flip2(start);
	Print(start2);
}
