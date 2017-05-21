//shivi..coding is adictive!!
//XOR Linked List – A Memory Efficient Doubly Linked List | Set 2
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *nptr;
};
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void Insert(Node **head,int data)
{
	Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->nptr=XOR(*head,NULL);
	
	if(*head)
	{
		Node *temp2=XOR((*head)->nptr,NULL);
		(*head)->nptr=XOR(temp,temp2);
	}
	*head=temp;
}

void print(Node *start)
{
	Node *curr=start,*prev=NULL,*nxt;
	
	while(curr)
	{
		cout<<curr->data<<endl;
		nxt=XOR(prev,curr->nptr);
		prev=curr;
		curr=nxt;
	}
	
}


int main()
{
	
}
