//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node  *right;
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

void Print(Node *x)
{
	if(x==NULL) return;
	Print(x->left);
	cout<<x->data<<" ";
	Print(x->right);
}

int LargestBST_CODE(Node *start,bool* isBST,int *mini,int *maxi,int *maxsize)
{
	if(start==NULL)
	{
		*isBST=1;
		return 0;
	}
	
	int lsze,rsze,min=INT_MAX,max=INT_MIN;
	bool l=0,r=0;
	
	maxi=INT_MIN;	
	lsze=LargestBST_CODE(start->left,isBST,mini,maxi,maxsize);
	if(*isBST==1 && start->data>*maxi)
	l=1;
	
	min=mini;
	
	mini=INT_MAX;
	rsze=LargestBST_CODE(start->right,isBST,mini,maxi,maxsize);
	if(*isBST==1 && start->data<*mini)
	r=1;
	
	
	
	if(*mini>min)
	*mini=min;
	if(start->data>*maxi)
	*maxi=start->data;
	if(start->data<*mini)
	*mini=start->data;
	
	
	if(l && r)
	{
		if(lsze+rsze+1>maxsize)
		*maxsize=lsze+rsze+1;
		return (*maxsize);
	}
	else
	{
		*isBST=0;
		return 0;
	}
}


int LargestBST(Node *start)
{
	int mini=INT_MIN;
	int maxi=INT_MAX;
	int maxsize=0;
	bool isBST=0;
	maxsize=LargestBST_CODE(start,&isBST,&mini,&maxsize);
	return maxsize;
}
	
int main()
{
	Node *start4=NULL;
	start4=new Node(60);
	start4->left=new Node(20);
	start4->left->left=new Node(15);
	start4->left->right=new Node(5);
	start4->right=new Node(10);
	start4->right->left=new Node(5);
	start4->right->right=new Node(5);

}
