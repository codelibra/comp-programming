//shivi..coding is adictive!!
//Sorted Array to Balanced BST
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

Node* BuildTree(Node* start,int arr[],int lo,int hi)
{
	if(hi<lo)
	return NULL;
	
	int mid=(lo+hi)/2,data=arr[mid];
	Node *temp=new Node(data);
	
	if(start==NULL)
	start=temp;
	
	if(lo==hi)
	return temp;
	
	start->left=BuildTree(start->left,arr,lo,mid-1);
	start->right=BuildTree(start->right,arr,mid+1,hi);
	return start;
}

void Inorder(Node *start)
{
	if(!start) return;
	Inorder(start->left);
	cout<<start->data<<' ';
	Inorder(start->right);
}

int main()
{
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	Node *start=NULL;
	start=BuildTree(start,arr,0,n-1);
	Inorder(start);
}
