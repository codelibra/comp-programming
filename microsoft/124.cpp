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

Node * flip_size(Node *start,int k)
{
	if(start==NULL)
	return NULL;
	
	Node *prev=NULL,*current=start,*nxt,*head=start;
	int count=0;
	while(current && count<k)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		++count;
	}
	start=prev;
	head->next=flip_size(current,k);
	return prev;
}


int main()
{
	Node *start=NULL,*start2=NULL;
	push('A',& start);push('B',& start);push('C',& start);push('D',& start);push('E',& start);//push('F',& start);
	Print(start);
	start2=flip_size(start,2);
	Print(start2);
}

