//shivi..coding is adictive!!
//revese a link list
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

void Intersecton(Node *start2,Node *start)
{
	Node *ans=NULL;
	
	while(start->next!=NULL && start2->next!=NULL)
	{
		//cout<<start->data<<" "<<start2->data<<endl;
		if(start->data>start2->data)
		start=start->next;
		
		else if(start->data<start2->data)
		start2=start2->next;
		
		else
		{
			//cout<<start->data<<endl;
			push(&ans,start->data);
			start=start->next;
			start2=start2->next;
		}
	}
	print(ans);
}

Node * Intersectonrecur(Node *start,Node *start2,Node *ans)
{
	if(start==NULL || start2==NULL)
	return NULL;
	
		if(start->data<start2->data)
		return  Intersectonrecur(start->next,start2,ans);
		
		else if(start->data>start2->data)
		return  Intersectonrecur(start,start2->next,ans);
		
		else
		{
			Node *temp=(Node *)malloc(sizeof(struct Node));
			temp->data=start->data;
			if(ans==NULL)
			{
				ans=temp;
			}
			
			else
			{
				ans->next=temp;
				ans=temp;
			}
			ans->next=Intersectonrecur(start->next,start2->next,ans);
		}
	return ans;
}

int main()
{
	struct Node *start=NULL,*start2=NULL,*ans=NULL;
	push(&start,0);push(&start,-10);push(&start,20);push(&start,30);push(&start,40);push(&start,50);
	push(&start2,0);push(&start2,10);push(&start2,15);push(&start2,30);push(&start2,40);push(&start2,55);
	print(start);
	print(start2);
	
	Intersecton(start,start2);
	Intersectonrecur(start,start2,ans);
	print(ans);
}
