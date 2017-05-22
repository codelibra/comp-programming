//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};

struct Bender
{
	int without;
	int with;
};

bool isLeaf(Node *x)
{
	if(x->left==NULL && x->right==NULL)
	return 1;
	return 0;
}

Bender MaxWithBend(Node *head,Node *parent,Bender &ans2)
{
	if(head==NULL)
	{
		Bender useless;
		useless.without=0;
		useless.with=0;
		return useless;
	}
	
	if(isLeaf(head))
	{
		Bender leaf;
		leaf.with=1;
		leaf.without=1;
		return leaf;
	}
	
	Bender l=MaxWithBend(head->left,head,ans2);
	Bender r=MaxWithBend(head->right,head,ans2); 
	
	
	if(parent==NULL)
	{
		Bender ans;
		ans.without=max(l.without,r.without)+1;
		ans.with=max(l.with,r.with)+1;
		if(l.without+r.without+1>ans2.with)
		{
			ans2.without=0;
			ans2.with=l.without+r.without+1;
		}
		return ans;
	}
	
	else if(head==parent->left)
	{
		Bender leftchild;
		leftchild.with=1+r.without;
		leftchild.without=1+l.without;
		if(l.without+r.without+1>ans2.with)
		{
			ans2.without=0;
			ans2.with=l.without+r.without+1;
		}
		return leftchild;
	}
	else
	{
		Bender rightchild;
		rightchild.with=1+l.without;
		rightchild.without=1+r.without;
		if(l.without+r.without+1>ans2.with)
		{
			ans2.without=0;
			ans2.with=l.without+r.without+1;
		}
		return rightchild;
	}
}

int Helper(Node *head)
{
	Bender ans,ans2;//ans2 -> bend at node + extreme left + extreme right
	ans2.without=0;
	ans2.with=0;
	Node *parent=NULL;
	ans=MaxWithBend(head,parent,ans2);
	return max(ans.without,max(ans.with,ans2.with));
}

int main()
{
	Node *head=NULL;
	head = new Node(100);
	head->left = new Node(100);
	head->right = new Node(100);
	head->left->left = new Node(100);
	head->left->right = new Node(100);
	head->right->left = new Node(100);
	head->right->right = new Node(100);
	head->left->left->right = new Node(100);
	head->left->left->right->right = new Node(100);
	head->left->left->right->right->right = new Node(100);
	head->left->left->right->right->left = new Node(100);
	head->left->left->right->right->left->left = new Node(100);
	head->left->left->right->right->left->left->left = new Node(100);
	head->left->left->right->right->left->left->left->left = new Node(100);
	head->left->left->right->right->right->right = new Node(100);
	head->left->left->right->right->right->right->right = new Node(100);
	head->left->left->right->right->right->right->right->right = new Node(100);
	head->left->left->right->right->right->right->right->right->right = new Node(100);
	
	
	/*head->right->left->left=new Node(28);
	head->right->left->right=new Node(30);
	head->right->right->right=new Node(100);
	head->right->right->right=new Node(100);
	head->right->right->right->right=new Node(110);*/
	cout<<Helper(head);
}
