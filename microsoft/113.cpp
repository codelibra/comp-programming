//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Doubly
{
	int data;
	Doubly *right;
	Doubly *left;
};

void push(struct Doubly **start,int k)
{
	Doubly *temp=(struct Doubly*)malloc(sizeof(struct Doubly));
	temp->data=k;
	temp->right=NULL;
	temp->left=NULL;
	
	if(*start==NULL)
	*start=temp;
	else
	{
		temp->right=*start;
		(*start)->left=temp;
		(*start)=temp;
	}
}

void print(struct Doubly *start)
{
	while(start->right)
	{
		cout<<start->data<<" ";
		start=start->right;
	}
	cout<<endl;
	while(start)
	{
		cout<<start->data<<" ";
		start=start->left;
	}
	
}

void deleteNode(Doubly **start,int n)
{
	Doubly *temp;
	if(n==0)
	{
		if((*start)->right!=NULL)
		{
			temp=*start;
			(*start)=(*start)->right;
			free(temp);
			(*start)->left=NULL;
		}
		else
		{
			free(*start);
			*start=NULL;
		}
	}
	
	else
	{
		Doubly *prev;
		temp=*start;
		
		while(--n)
		{
			prev=temp;
			temp=temp->right;
		}
		
		prev->right=temp->right;
		if(temp->right->right)
		{temp->right->left=prev;}
		free(temp);
	}
}

int main()
{
	Doubly *start=NULL;
	push(&start,3);push(&start,33);push(&start,32);push(&start,13);push(&start,2);
	print(start);
	cout<<endl;
	deleteNode(&start,2);
	print(start);
}
