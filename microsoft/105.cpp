//shivi..coding is adictive!!
//check string is a pallindrome
#include<shiviheaders.h>
using namespace std;
struct Node
{
	char data;
	Node *next;
};

void push(Node **start,char k)
{
	Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=*start;
	temp->data=k;
	*start=temp;
}

void insert(Node **start,char  c,int n)
{
	Node *temp=*start,*prev;
	if(n==0)
	{
		Node *k=(struct Node *)malloc(sizeof(struct Node));
		k->data=c;
		k->next=temp;
		*start=k;
		return;
	}
	while(n--)
	{
		prev=temp;
		temp=temp->next;
	}
	Node *k=(struct Node *)malloc(sizeof(struct Node));
	k->data=c;
	
	prev->next=k;
	k->next=temp;
}

void Print(Node *start)
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
	Node *slow=start,*fast=start;
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

bool checkPallindrome1(Node *start)
{
	Node *mid=start,*head=start;
	
	while(head->next!=NULL && head->next->next!=NULL)
	{
		mid=mid->next;
		head=head->next->next;
	}
	Node *head2=mid->next,*prev=NULL,*current=head2,*nxt;
	mid->next=NULL;
	while(current)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
	}
	head2=prev;
	
	while(start!=NULL && head2!=NULL)
	{
		if(start->data!=head2->data)
		return 0;
		else
		{
			start=start->next;
			head2=head2->next;
		}
		
	}
	
	
	return 1;
}

int main()
{
	struct Node *start=NULL;
	push(&start,'r');push(&start,'a');push(&start,'d');push(&start,'a');push(&start,'r');
	Print(start);
	//del(&start);
	//print(start);
	//reverse(&start);
	//print(start);
	//cout<<checkPallindrome1(start);
	//Print(start);
	insert(&start,'$',5);
	Print(start);
}
