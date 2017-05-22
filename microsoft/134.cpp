//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node*right;
	Node *next;
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
		next=NULL;
	}
};

Node* Push(Node *start,int d)
{
	if(start==NULL) return new Node(d);
	else if(start->data>d) start->left=Push(start->left,d);
	else if(start->data<d) start->right=Push(start->right,d);
	else start->data=d;
	return start;
}

void Inorder(Node *x)
{
	if(x==NULL) return;
	Inorder(x->left);
	int k=x->next?x->next->data:0;
	cout<<x->data<<" "<<k<<endl;
	Inorder(x->right);
}

void InorderSuccessor(Node *x,Node **succ)
{
	if(x==NULL) return;
	InorderSuccessor(x->right,succ);
	
	x->next=*succ;
	*succ=x;
	
	InorderSuccessor(x->left,succ);
}

int Sumtree(Node *start)
{
	if(start==NULL)
	return 0;
		
	if(start->left==NULL && start->right==NULL)
	{
		int k=start->data;
		start->data=0;
		return k;
	}
		
	else
	{
		int l=0,r=0,data;
		l=Sumtree(start->left);
		r=Sumtree(start->right);
		data=l+r+start->data;
		start->data=l+r;
		return data;
	}
}

int main()
{
	Node *start=NULL,*temp=NULL;
	start=Push(start,10);start=Push(start,45);start=Push(start,15);start=Push(start,8);start=Push(start,13);start=Push(start,34);start=Push(start,4);
	//InorderSuccessor(start,&temp);
	//Inorder(start);
	//cout<<start->left->next->data;
	Sumtree(start);
	cout<<endl;
	Inorder(start);
}
