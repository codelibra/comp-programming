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

Node * flip_alternate_size(Node *start,int k,bool toggle)
{
	if(start==NULL)
	return NULL;
	
	Node *current=start,*prev=NULL,*nxt,*head=start;
	int count=0;
	while(current && count<k)
	{
		nxt=current->next;
		if(toggle) current->next=prev;
		prev=current;
		current=nxt;
		++count;
	}
	if(toggle)
	{
		start=prev;
		head->next=flip_alternate_size(current,k,!toggle);
		return prev;
	}
	else
	{
		prev->next=flip_alternate_size(current,k,!toggle);
		return head;
	}
}


int main()
{
	Node *start=NULL,*start2=NULL;
	push('F',& start);push('E',& start);push('D',& start);push('C',& start);push('B',& start);push('A',& start);push('F',& start);push('E',& start);push('D',& start);push('C',& start);push('B',& start);push('A',& start);
	Print(start);
	start2=flip_alternate_size(start,2,0);
	Print(start2);
}

