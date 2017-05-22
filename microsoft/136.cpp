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

Node* Buildtree(int pre[],char preLN[],int N) 
{
	static int index=-1;
	
	if(index==N)
	return NULL;
	
	Node *temp=new Node(pre[++index]);
	if(preLN[index]=='N')
	{
		temp->left=Buildtree(pre,preLN,N);
		temp->right=Buildtree(pre,preLN,N);
	}
	return temp;
}
Node* buildtree2(int pre[],char preLN[],int N)
{
	
	Node *start=NULL,*head;
	stack<Node*> st;
	for(int i=0;i<N;++i)
	{
		Node *temp=new Node(pre[i]);
		if(start==NULL)
		{
			start=temp;
			head=start;
			continue;
		}
		
		if(start->left==NULL)
		start->left=temp;
		else if(start->right==NULL)
		start->right=temp;
		else
		{
			start=st.top();
			st.pop();
			
			if(start->left==NULL)
			start->left=temp;
			else if(start->right==NULL)
			start->right=temp;
		}
		
		st.push(start);
		start=temp;
		
		if(preLN[i]=='L')
		{
			start=st.top();
			st.pop();
		}
	}
	return head;
}

void Inorder(Node *start)
{
	if(start==NULL)
	return;
	Inorder(start->left);
	cout<<start->data<<"  ";
	Inorder(start->right);
}

int maxi(int inorder[],int i,int j)
{
	int index,max=INT_MIN;
	for(int k=i;k<=j;++k)
	{
		if(inorder[k]>max)
		{
		max=inorder[k];
		index=i;
		}
	}
	return index;
}

Node* Buildtree3(int inorder[], int lo,int hi)
{
	if(lo>hi)
	return NULL;
	
	int i=maxi(inorder,lo,hi);
	Node *temp=new Node(inorder[i]);
	
	if(lo==hi)
	return temp;
	
	temp->left=Buildtree3(inorder,lo,i-1);
	temp->right=Buildtree3(inorder,i+1,hi);
	return temp;
}

int main()
{
	int pre[] = {10, 30, 20, 5, 15};
	int inord[]={5,10,40,30,28};
	int N=sizeof(pre)/sizeof(int);
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	Node *start=NULL,*start2=NULL;
	start=buildtree2(pre,preLN,N);
	Inorder(start);
	cout<<endl;
	start2=Buildtree3(inord,0,4);
	Inorder(start2);
}
