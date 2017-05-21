//shivi..coding is adictive!!
//alernate split
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

void deleealternate(Node *start)
{
	Node *p=start->next,*temp,*head=start;
	if(!p)
	return;
	
	else
	{
		while(p && p->next)
		{
			temp=p;
			p=p->next;
			head->next=p;
			delete temp;
			head=head->next;
			p=p->next;
		}
	}
	print(start);
}

void delrecursivealternate(Node *start)
{
	if(start==NULL)
	return;
	
	Node *nxt;
	nxt=start->next;
	
	if(nxt->next==NULL)
	return;
	
	start->next=nxt->next;
	
	free (nxt);
	
	delrecursivealternate(start->next);
}

void alternatesplit(Node *start,Node **head1,Node **head2)
{
	
	Node *a=start;
	Node *b=start->next;
	*head1=a,*head2=b;
	
	while(b->next && a && b)
	{
		a->next=b->next;
		
		a=a->next;
		
		b->next=a->next;
		
		b=b->next;
	}
	b->next=NULL;
	a->next=NULL;
}

int main()
{
	struct Node *start=NULL,*head1,*head2;
	push(&start,0);push(&start,1);push(&start,0);push(&start,1);push(&start,0);push(&start,1);
	print(start);
	//del(&start);
	//print(start);
	//reverse(&start);
	//print(start);
	//deleealternate(start);
	//delrecursivealternate(start);
	//print(start);
	alternatesplit(start,&head1,&head2);
	print(head1);print(head2);
	
}
