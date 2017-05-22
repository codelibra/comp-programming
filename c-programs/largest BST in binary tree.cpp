//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
	Node (int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

struct val
{
	int sz;
	bool isBST;
};

bool printancestors(Node *root,int key)
{
	if(root==NULL) return 0;
	bool l=0,r=0;
	l=printancestors(root->left,key);
	r=printancestors(root->right,key);
	
	if(root->data==key) return 1;
	
	else if(l||r)
	{
		cout<<root->data<<endl;
		return 1;
	}
	return 0;
}

val LargestBST(Node *root,int mini,int maxi)
{
	if(root==NULL)
	{
		val temp;
		temp.sz=0;
		temp.isBST=1;
		return temp;
	}
	
	val l=LargestBST(root->left,mini,root->data-1);
	val r=LargestBST(root->right,root->data+1,maxi);
	
	
	if(root->data<mini || root->data>maxi)
	{
		val temp;
		temp.sz=max(l.sz,r.sz);
		temp.isBST=0;
		return temp;
	}
	else if(l.isBST&&r.isBST)
	{
		val temp;
		temp.sz=l.sz+r.sz+1;
		temp.isBST=1;
		
		cout<<root->data<<" "<<temp.sz<<endl;
		return temp;
	}
	else
	{
		val temp;
		temp.sz=max(l.sz,r.sz);
		temp.isBST=0;
		return temp;
	}
}

void TreeToDll(Node *root,Node *&start,Node *&prev)
{
	if(root==NULL) return;
	TreeToDll(root->left,start,prev);
	
	if(!start)start=root;
	if(prev)prev->right=root;
	root->left=prev;
	prev=root;
	TreeToDll(root->right,start,prev); 
}

void Traverse(Node*x)
{
	while(x)
	{
		cout<<x->data<<endl;
		x=x->right;
	}
}
Node* push(Node *x,int d)
{
	if(x==NULL) return new Node(d);
	else if(x->data <d) x->right=push(x->right,d);
	else if(x->data >d) x->left=push(x->left,d);
	else x->data=d;
	return x;
}

void PrintIn(Node *head)
{
	if(head==NULL) return;
	PrintIn(head->left);
	cout<<head->data<<endl;
	PrintIn(head->right);
}

void rootleaf(Node *root,int &sum)
{
	if(root==NULL) return;
	
	sum+=root->data;
	rootleaf(root->left,sum);
	rootleaf(root->right,sum);
	cout<<root->data<<"-> "<<sum<<endl;
}

int main()
{
	Node* head=NULL;
	head=push(head,10);
	head=push(head,5);
	head=push(head,15);
	head=push(head,1);
	head=push(head,8);
	head=push(head,7);
	val ans;
	//ans=LargestBST(head,INT_MIN,INT_MAX);
	//cout<<endl;
	//cout<<ans.sz<<endl;
	Node* head2=NULL;
	head2=new Node(10);
	head2->left=new Node(5);
	head2->left->left=new Node(1);
	head2->left->right=new Node(8);
	head2->right=new Node(15);
	head2->right->right=new Node(7);
	
	//ans=LargestBST(head2,INT_MIN,INT_MAX);
	//cout<<endl;
	//cout<<ans.sz<<endl;
	Node *start=NULL,*prev=NULL;
	//TreeToDll(head,start,prev);
	//Traverse(start);
	//PrintIn(head);
	//printancestors(head,7);
	int sum=0;
	rootleaf(head,sum);
	
}

