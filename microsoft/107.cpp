//shivi..coding is adictive!!
//remove duplicates from sorted list
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

void removeduplicates(Node **start)
{
	Node *temp=(*start)->next,*prev=*start,*deli,*temp2;
	int data=prev->data;
	
	while(temp)
	{
		deli=temp;
		while(temp!=NULL &&  temp->data==data )
			temp=temp->next;
			
		prev->next=temp;
		
		if(temp)
		data=temp->data;
		
		while(deli!=temp)	
		{
			temp2=deli;
			deli=deli->next;
			delete temp2;
		}
		if(temp)
		{
		prev=temp;
		temp=temp->next;
		}
	}
	//if(prev->data==temp->data)
	//{delete temp;prev->next=NULL;}
}

void  pairwiseswap(Node **start)
{
	Node *temp,*head=(*start)->next,*i=*start,*j=head;
	while(i!=NULL)
	{
		temp=i;
		i=j->next;
		j->next=temp;
		if(i==NULL || i->next==NULL)
		{
			temp->next=i;
			break;
		}
		else
		{
			j=i->next;
			temp->next=j;
		}
	}
	*start=head;
	
}

Node* pairwiseswaprecur(Node **start)
{
	
}

int main()
{
	struct Node *start=NULL;
	push(&start,11);push(&start,12);push(&start,13);push(&start,21);push(&start,43);push(&start,44);push(&start,60);push(&start,61);push(&start,62);
	print(start);
	//del(&start);
	//print(start);
	//reverse(&start);
	//print(start);
	//removeduplicates(&start);
	//print(start);
	pairwiseswap(&start);
	print(start);
	
	
}
