//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int N;
	int value;
	int key;
	Node *left;
	Node *right;
	Node(int k,int v,int n)
	{
		value=v;
		key=k;
		N=n;
		left=NULL;
		right=NULL;
	}
};

int Size(Node *x)
{
	if(x==NULL) return 0;
	else return x->N;
}

Node* put(Node *root,int k,int v)
{
	if(root==NULL) return new Node(k,v,1);
	else if(root->key>k) root->left=put(root->left,k,v);
	else if(root->key<k) root->right=put(root->right,k,v);
	else if(root->key==k) root->value=v;
	root->N=Size(root->left)+Size(root->right)+1;
	return root;
}

int get(Node *root,int k)
{
	if(root==NULL) return -1;
	else if(root->key==k) return root->value;
	else if(root->key>k)  return get(root->left,k);
	else if(root->key<k)  return get(root->right,k);
}

void Inorder(Node *root)
{
	if(root==NULL) return;
	Inorder(root->left);
	cout<<root->key<<"-> "<<root->value<<endl;
	Inorder(root->right);
}

void Postorder(Node *root)
{
	if(root==NULL) return;
	Inorder(root->left);
	Inorder(root->right);
	cout<<root->key<<"-> "<<root->value<<endl;
}

void Preorder(Node *root)
{
	if(root==NULL) return;
	cout<<root->key<<"-> "<<root->value<<endl;
	Inorder(root->left);
	Inorder(root->right);
}

int min(Node *root)
{
	if(root->left==NULL) return root->value;
	else return min(root->left);
}

int max(Node *root)
{
	if(root->right==NULL) return root->value;
	else return max(root->right);
}

Node* Floor(Node *root,int k)
{
	if(root==NULL) return NULL;
	else if(root->key==k) return root;
	else if(root->key>k) return Floor(root->left,k);
	else 
	{
		Node *y=Floor(root->right,k);
		if(y==NULL) return root;
		else return y;
	}
}

Node * Ceil(Node *root,int k)
{
	if(root==NULL) return NULL;
	else if(root->key==k) return root;
	else if(root->key<k) return Ceil(root->right,k);
	else
	{
		Node *y=Ceil(root->left,k);
		if(y==NULL) return root;
		else return y;
	}
}


Node  * Select(Node *root,int r)
{
	if(root==NULL) return NULL;
	int t=Size(root->left);
	if(t==r) return root;
	else if(t>r) return Select(root->left,r);
	else return Select(root->right,r-t-1);
}

int Rank(Node *root,int k)
{
	if(root==NULL) return 0;
	else if(root->key>k) return Rank(root->left,k);
	else if(root->key<k) return Size(root->left)+1+Rank(root->right,k);
	else return Size(root);
}

int main()
{
	struct Node *root=NULL;
	root=put(root,2,3);
	root=put(root,4,13);
	root=put(root,5,13);
	root=put(root,7,45);
	root=put(root,1,32);
	root=put(root,-1,32);
	root=put(root,-10,32);
	root=put(root,22,78);
	root=put(root,12,9);
	root=put(root,24,15);
	root=put(root,62,33);
	Inorder(root);
	cout<<" \nvalue of 22= "<<get(root,22);
	cout<<" \nvalue of 10= "<<get(root,10);
	cout<<" \nvalue of min key= "<<min(root);
	cout<<" \nvalue of max key= "<<max(root);
	Node *k=Floor(root,6);
	cout<<" \nFloor of 6= "<<k->key;
	k=Ceil(root,6);
	cout<<" \nCeil of 6= "<<k->key;
	k=Select(root,5);
	cout<<" \n5th element= "<<k->value;
	cout<<" \nrank of 12= "<<Rank(root,12);
}
