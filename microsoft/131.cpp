//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *right;
	Node *left;
	Node *nextright;
	Node(int d)
	{
		data=d;
		right=NULL;
		left=NULL;
		nextright=NULL;
	}
};


void Connect(Node *start)
{
	if(start==NULL)
	return;
	
	if(start->left)
	start->left->nextright=start->right;
	
	if(start->right)
	{
		Node *p;
		p=start->nextright;
		if(p)
		{
		p=p->left;
		start->right->nextright=p;
		}
		else
		start->right->nextright=NULL;
	}
	Connect(start->left);
	Connect(start->right);
}


void ConnectNodesAtSameLevel2(Node *start)
{
	start->nextright=NULL;
	Connect(start);
}


Node* arr[100];
void ConnectNodesAtSameLevel(Node *start)
{
	static int level=0;
	queue<Node *> dq;
	dq.push(start);
	dq.push(NULL);
	
	Node *temp,*prev=NULL;
	while(!dq.empty())
	{
		temp=dq.front();
		dq.pop();
		if(temp==NULL)
		{
			if(dq.empty())break;
			prev->nextright=temp;
			prev=NULL;
			dq.push(NULL);
		}
		else
		{
			if(temp->left)
			dq.push(temp->left);
			if(temp->right)
			dq.push(temp->right);
			
			if(prev==NULL)
			{
				prev=temp;
				arr[level++]=temp;
			}
			else
			{
				prev->nextright=temp;
				prev=temp;
			}
		}
	}
	
	for(int i=0;i<level;++i)
	{
		Node *x=arr[i];
		while(x)	{cout<<x->data<<" ";x=x->nextright;}
		cout<<endl;
	}
}


Node* getnextRight(Node *p)
{
	Node *temp=p->nextright;
	while(temp)
	{
		if(temp->left)
		return temp->left;
		
		if(temp->right)
		return temp->right;
		
		temp=temp->nextright;
	}
	return NULL;
}

void Connectlevel(Node *start)
{
	start->nextright=NULL;
	
	if(start)
	return;
	
	while(p)
	{
		Node *q=p;
		while(q)
		{
			if(q->left)
			{
				if(q->right)
				q->left->nextright=q->right;
				else
				q->left->nextright=getnextRight(q);
			}
			
			if(q->right)
			q->right->nextright=getnextRight(q);
			
			q=q->nextright;
		}
		if(p->left)
		p=p->left;
		else if(p->right)
		p=p->right;
		else
		p=p->nextright;
	}
	
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
	ConnectNodesAtSameLevel(start4);
	cout<<"using preorder \n";
	Connect(start4);
	Node *p=start4->left->left;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->nextright;
	}
}
