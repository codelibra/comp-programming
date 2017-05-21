//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	char data;
	Node *left;
	Node*right;
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

bool Foldable(Node *x,Node* y)
{
	if(x==NULL && y==NULL)
	return 1;
	
	if(x==NULL || y==NULL)
	return 0;
	
	return (Foldable(x->left,x->right)&Foldable(y->left,y->right));
}

bool Isfoldable(Node *start)
{
	if(start==NULL)
	return 1;
	
	else return Foldable(start->left,start->right);
}

int Search(char Inorder[],int lo,int hi,char data)
{
	for(int i=lo;i<=hi;++i)
	{
		if(Inorder[i]==data)
		return i;
	}
}

Node* BuildTree(char inorder[],char preorder[],int lo,int hi)
{
	static int preindex=0;
	if(lo>hi)
	return NULL;
	
	char data=preorder[preindex++];
	Node *temp=new Node(data);
	
	if(lo==hi)
	return temp;
	
	int inindex=Search(inorder,lo,hi,data);
	
	temp->left=BuildTree(inorder,preorder,lo,inindex-1);
	temp->right=BuildTree(inorder,preorder,inindex+1,hi);
	return temp;
}


void print(Node *start)
{
	if(start==NULL)  return;
	print(start->left);
	cout<<start->data<<" ";
	print(start->right);
}

int main()
{
	char Inorder[]={'d','b','e','a','f','c'};
	char PreOrder[]={'a','b','d','e','c','f'};
	Node *start=NULL;
	start=BuildTree(Inorder,PreOrder,0,5);
	print(start);
}
