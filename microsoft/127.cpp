//shivi..coding is adictive!!
//Write a C program to Calculate Size of a tree
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

Node* insert(Node *x,int d)
{
	if(x==NULL) return new Node(d);
	else if(x->data>d) x->left=insert(x->left,d);
	else if(x->data<d) x->right=insert(x->right,d);
	else x->data=d;
	return x;
}

void Print(Node *x)
{
	if(x==NULL) return;
	Print(x->left);
	cout<<x->data<<" ";
	Print(x->right);
}

int Size(Node *x)
{
	if(x==NULL)
	return 0;
	else return Size(x->left)+Size(x->right)+1;
}

bool Check_Identical(Node *start1,Node* start2)
{
	if(start1==NULL && start2==NULL)
	return 1;
	
	if((start1==NULL && start2!=NULL)||((start1!=NULL && start2==NULL)))
	return 0;
	
	else
	return ((start1->data==start2->data) && (Check_Identical(start1->left,start2->left)) && Check_Identical(start1->right,start2->right));
}

int Height(Node *start)
{
	if(start==NULL)
	return 0;
	
	else
	return max(Height(start->left),Height(start->right))+1;
}

void DeleteTree(Node *x)
{
	if(x==NULL)
	return;
	
	DeleteTree(x->left);
	DeleteTree(x->right);
	cout<<"deleting "<<x->data<<endl;
	delete x;
}

void Mirror(Node *start)
{
	if(start==NULL)
	return;
	else
	{
		Mirror(start->left);
		Mirror(start->right);
		
		Node *temp=start->left;
		start->right=start->left;
		start->left=temp;
	}
}

void PrintRootTOLeaf(Node *start,int Path[],int pathlength)
{
	if(start==NULL)
	return;
	
	Path[pathlength]=start->data;
	if(start->left==NULL && start->right==NULL)
	{
		for(int i=0;i<=pathlength;++i)
		cout<<Path[i]<<" ";
		cout<<endl;
	}
	PrintRootTOLeaf(start->left,Path,pathlength+1);
	PrintRootTOLeaf(start->right,Path,pathlength+1);
}


int LowestCommonAncestor(Node *start,int val1,int val2)
{
	if(start==NULL || start->data==val2 || start->data==val1)
	return -1;
	
	else if(start->right && (start->right->data==val1 || start->right->data==val2))
	return start->data;
	
	else if(start->left && (start->left->data==val1 || start->left->data==val2))
	return start->data;
	
	else if(start->data>val1 && start->data<val2)
	return start->data;
	
	else if(start->data>val1 && start->data>val2)
	return LowestCommonAncestor(start->left,val1,val2);
	
	else if(start->data<val1 && start->data<val2)
	return LowestCommonAncestor(start->right,val1,val2);
}

void LevelOrderTraversal(Node *start)	
{
	queue<Node *> dq;
	dq.push(start);
	while(!dq.empty())
	{
		Node *temp=dq.front();
		dq.pop();
		if(temp->left)
		dq.push(temp->left);
		
		if(temp->right)
		dq.push(temp->right);
		
		cout<<temp->data<<" ";
	}
}

void LevelOrder(Node *start,int i)
{
	if(start==NULL)
	return;
	
	if(i==1)
	cout<<start->data<<" ";
	else
	{
		LevelOrder(start->left,i-1);
		LevelOrder(start->right,i-1);
	}
}

void LevelOrderRecursive(Node *start)	
{
	int h=Height(start);
	
	for(int i=1;i<=h;++i)
	LevelOrder(start,i);
}

int GetLeafCount(Node *start)
{
	static int count=0;
	if(start==NULL)
	return 0;
	else if(start->left==NULL && start->right==NULL)
	++count;
	GetLeafCount(start->left);
	GetLeafCount(start->right);
	return count;
}

int GetLeafCount2(Node *start)
{
	if(start==NULL)
	return 0;
	else if(start->left==NULL && start->right==NULL)
	return 1;
	else return GetLeafCount2(start->left)+GetLeafCount2(start->right);
}

bool IsBST(Node *start,int maxi,int mini)
{
	if(start==NULL)
	return 1;
	
	if(start->data<mini || start->data>maxi)
	return 0;
	
	return IsBST(start->left,start->data,mini) && IsBST(start->right,maxi,start->data);
}

bool CheckBST(Node *start)
{
	return IsBST(start,INT_MAX,INT_MIN);
}

bool CheckBST2(Node *start)
{
	Node *prev=NULL;
	if(start==NULL)
	return 1;
	
	return CheckBST2(start->left);
	
	if(!prev)
	prev=start;
	else
	{
		if(prev->data>start->data)
		return 0;
		
		prev=start;
	}
	
	return CheckBST2(start->right);
}

int main()
{
	Node *start=NULL,*start2=NULL;
	start2=insert(start2,10);
	start2=insert(start2,14);
	start2=insert(start2,1);
	start2=insert(start2,12);
	start2=insert(start2,7);
	start2=insert(start2,23);
	start2=insert(start2,78);
	start2=insert(start2,4);
	
	start=insert(start,10);
	start=insert(start,14);
	start=insert(start,1);
	start=insert(start,12);
	start=insert(start,7);
	start=insert(start,23);
	start=insert(start,78);
	start=insert(start,4);
	
	Print(start);
	cout<<endl<<Size(start);
	cout<<endl<<"is Identical "<<Check_Identical(start,start2)<<endl;
	cout<<"Height "<<Height(start)<<endl;
	//DeleteTree(start2);start2=NULL;cout<<" "<<Size(start2);
	int arr[100];
	PrintRootTOLeaf(start,arr,0);
	Print(start);
	cout<<endl<<"Lowestcommonancestor of 12 and 23  "<<endl<<LowestCommonAncestor(start,12,23)<<endl;
	LevelOrderTraversal(start);
	cout<<endl;
	LevelOrderRecursive(start);
	cout<<endl;
	cout<<GetLeafCount(start);
	cout<<" "<<GetLeafCount2(start)<<endl;
	cout<<CheckBST2(start)<<" "<<CheckBST(start);
}
