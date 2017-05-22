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
Node* insert(Node *x,int d)
{
	if(x==NULL) return new Node(d);
	else if(x->data>d) x->left=insert(x->left,d);
	else if(x->data<d) x->right=insert(x->right,d);
	else x->data=d;
	return x;
}

Node* Constructtree(int pre[],int sz)
{
	Node *temp=new Node(pre[0]),*start=temp;
	int prev=pre[0];
	stack<Node*> st;
	st.push(start);
	for(int i=1;i<sz;++i)
	{
		Node *temp2=new Node(pre[i]);
		if(pre[i]<prev)
		{
			temp->left=temp2;
			temp=temp->left;
			st.push(temp);
		}
		else
		{
			while(!st.empty() &&  st.top()->data<pre[i])
			{
			temp=st.top();
			st.pop();
			}
			temp->right=temp2;
			temp=temp->right;
			st.push(temp);
		}
		prev=pre[i];
	}
	return start;
}

void inorder(Node *start)
{
	if(start==NULL) return;
	inorder(start->left);
	cout<<start->data<<" ";
	inorder(start->right);
}

Node *buildTree(int pre[],int post[],int lo,int hi,int sz)
{
	static int preindex=0;
	if(preindex>=sz ||(lo>hi))
	return NULL;
	
	Node *temp=new Node(pre[preindex++]);
	if(lo==hi)
	return temp;
	
	int i;
	for(i=lo;i<=hi;++i)
	if(pre[preindex]==post[i]) break;
	
	if(i<=hi)
	{
	temp->left=buildTree(pre,post,lo,i,sz);
	temp->right=buildTree(pre,post,i+1,hi,sz);
	}
	
	return temp;
}
int main()
{
	int pre[]={10, 5, 1, 7, 40, 50};
	int sz=sizeof(pre)/sizeof(int);
	Node *start=NULL;
	start=Constructtree(pre,sz);
	inorder(start);
	int pre1[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
     int post1[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
     Node *start2=NULL;
     int sz2=sizeof(pre1)/sizeof(int);
     cout<<endl;
     start2=buildTree(pre1,post1,0,sz2-1,sz2);
     inorder(start2);
}
