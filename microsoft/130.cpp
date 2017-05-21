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

int MaxSumRootToLeaf(Node *start,int sum_till_nw,int *leaf)
{
	static int sum=INT_MIN;
	if(start==NULL) return 0;
	
	if(start->left==NULL && start->right==NULL)
	{
		int initial=sum;
		sum=max(sum,sum_till_nw+start->data);
		if(sum>initial)*leaf=start->data;
	}
	else sum_till_nw+=start->data;
	
	MaxSumRootToLeaf(start->left,sum_till_nw,leaf);
	MaxSumRootToLeaf(start->right,sum_till_nw,leaf);
	return sum;
}

bool Path(Node *start,int data)
{
	if(start==NULL)
	return 0;
	
	if(Path(start->left,data) ||Path(start->right,data) ||(start->left==NULL && start->right==NULL && start->data==data))
	{
	cout<<start->data<<" ";
	return 1;
	}
	return 0;
}

int Width(Node *start)
{
	Node *n=NULL;
	queue<Node*> dq;
	dq.push(start);
	dq.push(n);
	int count=0,width=0;
	while(!dq.empty())
	{
		Node *temp=dq.front();
		
		if(temp==n)
		{
			dq.pop();
			if(dq.empty()) break;
			dq.push(n);
			width=max(count,width);
			count=0;
			continue;
		}
		
		dq.pop();
		if(temp->left)
		{dq.push(temp->left);++count;}
		if(temp->right)
		{dq.push(temp->right);++count;}
	}
	return width;
}

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

void LevelOrderSpiralL(Node * start,int i,bool flip)
{
	if(start==NULL) return;
	
	if(i==1)
	cout<<start->data<<" ";
	
	else if(flip)
	{
		LevelOrderSpiralL(start->left,i-1,flip);
		LevelOrderSpiralL(start->right,i-1,flip);
	}
	else
	{
		LevelOrderSpiralL(start->right,i-1,flip);
		LevelOrderSpiralL(start->left,i-1,flip);
	}
}

void LevelOrderSpiral(Node *start)
{
	int H=Height(start);
	bool flip=0;
	for(int i=1;i<=H;++i)
	{
		flip=!flip;
		LevelOrderSpiralL(start,i,flip);
	}
}


bool ChildrenSumProperty(Node *start)
{
	if(start==NULL ||( start->left==NULL && start->right==NULL))
	return 1;
	
	else
	{
	
	int left_val=0,right_val=0;
	if(start->left)
	left_val=start->left->data;
	
	if(start->right)
	right_val=start->right->data;
	
	if((start->data==left_val+right_val)&& ChildrenSumProperty(start->left) && ChildrenSumProperty(start->right))
	return 1;
	else return 0;
	}
}

void Increment(Node *start,int diff)
{
	if(start==NULL) return;
	
	if(start->left)
	{
		start->left->data+=diff;
		Increment(start->left,diff);
	}
	else if(start->right)
	{
		start->right->data+=diff;
		Increment(start->right,diff);
	}
}

void ConvertToSumProperty(Node *start)
{
	if(start==NULL ||(start->left==NULL && start->right==NULL))
	return;
	
	else
	{
	ConvertToSumProperty(start->left);
	ConvertToSumProperty(start->right);
	
	int left_val=0,right_val=0;
	if(start->left)
	left_val=start->left->data;
	
	if(start->right)
	right_val=start->right->data;
	
	int diff=left_val+right_val-start->data;
	
	if(diff>0)
	start->data+=diff;
	
	if(diff<0)
	Increment(start,-diff);
	}
}

int DiameterOftree(Node *start)
{
	if(start==NULL)
	return 0;
	
	int lH=Height(start->left);
	int rH=Height(start->right);
	
	int ldia=DiameterOftree(start->left);
	int rdia=DiameterOftree(start->right);
	
	return max(lH+rH+1,max(ldia,rdia));
}

bool IsHeightBalanced(Node *start)
{
	if(start==NULL)
	return 1;
	
	int lH=Height(start->left);
	int rH=Height(start->right);
	
	if(abs(lH-rH)<=1 && IsHeightBalanced(start->left) && IsHeightBalanced(start->right))
	return 1;
	
	else return 0;
}

void InorderIterative(Node *start)
{
	stack<Node *> st;
	Node *current=start;
	while(!st.empty() || current)
	{
		if(current)
		{
			st.push(current);
			current=current->left;
		}
		else
		{
			if(!st.empty())
			{
				current=st.top();
				st.pop();
				cout<<current->data<<" ";
				current=current->right;
			}
		}
	}
}

void MorrisTraversal(Node *start)
{
	Node *current=start;
	while(current)	
	{
		if(current->left==NULL)
		{
			cout<<current->data<<" ";
			current=current->right;
		}
		else
		{
			Node *pre=current->left;
			
			while(pre->right!=NULL && pre->right!=current)
			pre=pre->right;
			
			if(pre->right==NULL)
			{
				pre->right=current;
				current=current->left;
			}
			else
			{
				pre->right=NULL;
				cout<<current->data<<" ";
				current=current->right;
			}
		}
	}
}

bool rootTo(Node *start,int path[],int pathlen,int sum)
{
	if(start==NULL)
	return 0;
	
	else
	{
		path[pathlen]=start->data+path[pathlen-1];
		++pathlen;
		if(start->left==NULL && start->right==NULL)
		{
			if(path[pathlen-1]==sum)
			return 1;
			
			else 
			return 0;
		}
	}
	return (rootTo(start->left,path,pathlen,sum) || rootTo(start->right,path,pathlen,sum));
}

bool rootToLeaf(Node *start,int sum)
{
	int path[100],pathlen=1;
	path[0]=0;
	return rootTo(start,path,pathlen,sum);
}


bool SumrootToleaf(Node *root,int sum)
{
	int diff;
	if(root==NULL)
	return (sum==0);
	
	else
	{
	     diff=sum-(root->data);
		if(diff==0 && root->left==NULL && root->right==NULL)
		return 1;
		
		return (SumrootToleaf(root->left,diff)|| SumrootToleaf(root->right,diff));
	}
}


void DoubleTree(Node *start)
{
	Node *temp;
	if(start==NULL)return;
	
	DoubleTree(start->left);
	DoubleTree(start->right);
	
	temp=new Node(start->data);
	if(start->left==NULL)
		start->left=temp;
	else
	{
		Node *k=start->left;
		start->left=temp;
		temp->left=k;
	}
}


void KDistance(Node *start,int k,int count)
{
	if(start==NULL)
	return;
	else
	{
		KDistance(start->left,k,count+1);
		KDistance(start->right,k,count+1);
		if(count==k)
		{
			cout<<start->data<<' ';
		}
	}
}

Node * InorderSuccesor(Node *start,Node *x)
{
	if(x->right!=NULL)
	{
		while(x->left)
		x=x->left;
		return x;
	}
	else
	{
		Node *potential;
		while(start)
		{
			if(start->data<x->data)
			start=start->right;
			
			else if(start->data>x->data)
			{
				potential=start;
				start=start->left;
			}
			
			else 
			break;
		}
		return potential;
	}
}

int getlevel(Node *start,int data,int level)
{
	if(start==NULL)
	return 0;
	
	if(start->data==data)
	return level;
	
	else
	{
		return (getlevel(start->left,data,level+1))|(getlevel(start->right,data,level+1));
	}
}

bool PrintAncestors(Node* start,int data)
{
	if(start==NULL)
	return 0;
	
	if(start->data==data)
	return 1;
	
	if(PrintAncestors(start->left,data)|PrintAncestors(start->right,data))
	{
		cout<<start->data<<" ";
		return 1;
	}
	return 0;
}

void PrintAncestors2(Node* start,int arr[],int pathlenth,int data)
{
	if(start==NULL)
	return ;
	
	if(start->data==data)
	{
		for(int i=0;i<pathlenth;++i)
		cout<<arr[i]<<' ';
		return;
	}
	else arr[pathlenth++]=start->data;
	
	PrintAncestors2(start->left,arr,pathlenth, data);
	PrintAncestors2(start->right,arr,pathlenth, data);
}

void printKeysInArange(Node *start,int k1,int k2)
{
	if(start==NULL)
	return;
	
	if(start->data>k1)
	printKeysInArange(start->left,k1,k2);
	
	if(start->data>=k1 && start->data<=k2)
	cout<<start->data<<" ";
	
	if(start->data<k2)
	printKeysInArange(start->right,k1,k2);
}

bool IsHeightBalancedOrder_n(Node  *start,int* hgt)
{
	if(start==NULL)
	{
		*hgt=0;
		return 1;
	}
	else
	{
		int lhgt=0,rhgt=0;
		bool l=IsHeightBalancedOrder_n(start->left,&lhgt);
		bool r=IsHeightBalancedOrder_n(start->right,&rhgt);
		
		*hgt=max(lhgt,rhgt)+1;
		if(abs(lhgt-rhgt)>=2)
		return 0;
		
		return l && r;
	}
}


bool ISSUMTREE(Node *start,int *sum)
{
	if(start->left==NULL && start->right==NULL)
	{
		*sum=start->data;
		return 1;
	}
	
	if(start==NULL)
	{
		*sum=0;
		return 1;
	}
	else
	{
		int lsum=0,rsum=0;
		bool l=1,r=1;
		l=ISSUMTREE(start->left,&lsum);
		r=ISSUMTREE(start->right,&rsum);
	
		*sum=lsum+rsum+start->data;
		if(start->data!=lsum+rsum)
		return 0;
		
		return l&&r;
	}
}

bool IsSumTree(Node *start)
{
	int sum=0;
	ISSUMTREE(start,&sum);
}

bool isLeaf(Node *x)
{
	if(x->left==NULL && x->right==NULL)
	return 1;
	else
	return 0;
}

bool IsSumTree2(Node *start)
{
	if(start==NULL || (start->left==NULL && start->right==NULL))
	return 1;
	
	if(start==NULL)
	return 1;
	
	else
	{
		bool l,r;
		int lh=0,rh=0;
		l=IsSumTree2(start->left);
		r=IsSumTree2(start->right);
		
		if(start->left && isLeaf(start->left))
		lh=start->left->data;
		
		if(start->left && !isLeaf(start->left))
		lh=2*(start->left->data);
		
		if(start->right && isLeaf(start->right))
		rh=start->right->data;
		
		if(start->right && !isLeaf(start->right))
		rh=2*(start->right->data);
		
		if(start->data!=lh+rh)
		return 0;
		
		return l&&r;
	}
}

void MergeBST(Node *start1,Node *start2)
{
	stack<Node*> st1;
	stack<Node*> st2;
	
	Node* current1=start1,*current2=start2;
	
	bool done=0;
	while(!done)
	{
		while(current1)
		{
			st1.push(current1);
			current1=current1->left;
		}
		while(current2)
		{
			st2.push(current2);
			current2=current2->left;
		}
		
		
		if(st1.size() && st2.size())
		{
			
			current1=st1.top();
			current2=st2.top();
			if(current1->data<current2->data)
			{
			st1.pop();
			cout<<current1->data<<" ";
			current1=current1->right;
			current2=NULL;
			}
			else
			{
			st2.pop();
			cout<<current2->data<<" ";
			current2=current2->right;
			current1=NULL;	
			}
		}
		else
		done=1;
	}
	
	while(st1.size())
	{
		cout<<st1.top()->data<<" ";
		st1.pop();
	}
	while(st2.size())
	{
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
}

bool CheckCompleteBinaryTree(Node *start)
{
	queue<Node *> st;
	st.push(start);
	bool zero=0;
	
	while(!st.empty())
	{
		Node *temp=st.front();
		
		if((temp->left==NULL && temp->right!=NULL) ||(temp->left!=NULL && temp->right==NULL))
		return 0;
		
		else if(temp->left && temp->right)
		{
		if(zero==1)	 return 0;
		st.push(temp->left);
		st.push(temp->right);
		}
		else if(temp->left==NULL && temp->right==NULL)
		zero=1;
		
		st.pop();
	}
	return 1;
}

void CorreectSwapped(Node *start)
{
	Node *first=NULL,*second=NULL,*third=NULL,*prev=NULL;
	bool done=0,found=0;
	stack<Node *> st;
	Node *current=start;
	
	while(!done)
	{
		while(current)
		{
			st.push(current);
			current=current->left;
		}
		
		if(!st.empty())
		{
			current=st.top();
			st.pop();
			
			if(prev==NULL)
			prev=current;
			else
			{
				if(current->data>=prev->data)
				prev=current;
				else
				{
					if(third==NULL)
					{
					first=prev;
					second=current;
					found=1;
					}
					else
					third=current;
				}
			}
			
			current=current->right;
		}
		else done=1;
	}
	if(third)
	{
	cout<<second->data<<" "<<third->data;
	swap(second,third);
	}
	else
	{
	cout<<first->data<<" "<<second->data;
	swap(second,first);
	}
}

bool FindPairWithRequiredSum(Node *start,int sum)
{
	stack<Node *> st1;
	stack<Node *> st2;
	Node *current1=start,*current2=start;
	bool done=0;
	
	while(!done)
	{
		while(current1)
		{
			st1.push(current1);
			current1=current1->left;
		}
		while(current2)
		{
			st2.push(current2);
			current2=current2->right;
		}
		
		if(st1.size()!=0 && st2.size()!=0)
		{
			current1=st1.top();
			current2=st2.top();
			if(current1->data+current2->data==sum)
			{
				cout<<current1->data<<" "<<current2->data;
				return 1;
			}
			else if(current1->data+current2->data>sum)
			{
				st2.pop();
				current2=current2->left;
				current1=NULL;
			}
			else
			{
				st1.pop();
				current1=current1->right;
				current2=NULL;
			}
		}
		else
		done=1;
	}
	
	cout<<"Sum not found";
	return  0;
}

void TripletRequiredSum(Node *start)
{
	Node *head=start;
	stack<Node*> st;
	Node *current=start;
	bool done=0;
	while(!done)
	{
		while(current)
		{
			st.push(current);
			current=current->left;
		}
		if(st.size()!=0)
		{
			current=st.top();
			st.pop();
			if(FindPairWithRequiredSum(head,((-1)*current->data)))
			{cout<<" "<<current->data;return;}
			
			current=current->right;
		}
		else
		done=1;
	}
}

Node* DeleteKeysOutsideRange(Node*start, int mini,int maxi)
{
	if(start==NULL)
	return NULL;
	
	start->left=DeleteKeysOutsideRange(start->left,mini,maxi);
	start->right=DeleteKeysOutsideRange(start->right,mini,maxi);
	
	if(start->data<mini)
	{
		Node *k=start->right;
		delete start;
		return k;
	}
	if(start->data>maxi)
	{
		Node *k=start->left;
		delete start;
		return k;
	}
	return start;
}

void IterativePreorder(Node *start)
{
	stack<Node*> st;
	st.push(start);
	Node *current=start;
	while(!st.empty())
	{
		while(current)
		{
			cout<<current->data<<" ";
			st.push(current);
			current=current->left;
		}
		
		if(!st.empty())
		{
			current=st.top();
			st.pop();
			current=current->right;
		}
	}
}

void PostOrderTraversalIterative2stacks(Node *start)
{
	stack<Node*> st1;
	stack<Node*> st2;
	st1.push(start);
	Node *temp;
	while(!st1.empty())
	{
		temp=st1.top();
		st1.pop();
		
		if(temp->left)
		st1.push(temp->left);
		if(temp->right)
		st1.push(temp->right);
		
		st2.push(temp);
	}
	while(!st2.empty())
	{
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
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
	cout<<endl;
	LevelOrderSpiral(start);
	cout<<endl;
	
	Node *start3=NULL;
	start3=insert(start3,10);
	start3=insert(start3,20);
	cout<<ChildrenSumProperty(start3);
	cout<<endl;
	
	
	ConvertToSumProperty(start);
	Print(start);
	cout<<endl<<ChildrenSumProperty(start)<<endl;
	cout<<"diameter "<<DiameterOftree(start);
	cout<<"\nis height balanced "<<IsHeightBalanced(start)<<endl;
	Print(start2);
	cout<<endl;
	InorderIterative(start2);
	cout<<endl;
	MorrisTraversal(start2);
	cout<<endl;
	cout<<"sum root to leaf "<<rootToLeaf(start2,22)<<endl;
	cout<<"sum root to leaf "<<SumrootToleaf(start2,20)<<endl;
	cout<<Width(start2)<<endl;
	Print(start2);
	cout<<endl;
	//DoubleTree(start2);
	Print(start2);
	cout<<"\nat distance 3 -> ";
	KDistance(start2,3,0);
	cout<<endl;
	cout<<"level of 23 "<<getlevel(start2,23,0)<<endl;
	cout<<"ancestors of 78- ";
	PrintAncestors2(start2,arr,0,78);
	cout<<"\n5ancestors of 4- ";
	PrintAncestors(start2,4);
	cout<<endl<<"printing in range 10 to 30 ";
	printKeysInArange(start2,10,30);
	cout<<endl;
	
	cout<<"\n sum tree check  \n";
	
	Node *start4=NULL;
	start4=new Node(60);
	start4->left=new Node(65);
	start4->left->left=new Node(15);
	start4->left->right=new Node(25);
	start4->right=new Node(70);
	start4->right->left=new Node(20);
	start4->right->right=new Node(75);
	cout<<IsSumTree(start4);
	cout<<IsSumTree2(start4)<<endl;
	
	int leafdata;
	cout<<" maximum leaf to root sum= ";
	cout<<MaxSumRootToLeaf(start4,0,&leafdata);
	cout<<"Pat till leaf\n";
	Path(start4,leafdata);
	
	Node *start5=NULL;
	start5=insert(start5,45);
	start5=insert(start5,6);
	start5=insert(start5,13);
	start5=insert(start5,80);
	start5=insert(start5,56);
	start5=insert(start5,4);
	start5=insert(start5,87);
	
	cout<<"\n\n\nmerge  BST\n";
	InorderIterative(start2);
	cout<<endl;
	InorderIterative(start5);
	cout<<endl;
	MergeBST(start2,start5);
	cout<<endl<<"\nchecking complete binary tree ";
	cout<<CheckCompleteBinaryTree(start5);
	cout<<"\ncoreect swapped BST \n";
	CorreectSwapped(start4);
	cout<<endl;
	InorderIterative(start5);
	cout<<"\npair with sum 19= ";
	FindPairWithRequiredSum(start5,19);
	
	Node *start6=NULL;
	start6=insert(start6,6);
	start6=insert(start6,-13);
	start6=insert(start6,14);
	start6=insert(start6,-8);
	start6=insert(start6,7);
	start6=insert(start6,13);
	start6=insert(start6,15);
	cout<<"\ntriplet with sum 0= ";
	TripletRequiredSum(start6);
	cout<<"\ndelete outside range ";
	DeleteKeysOutsideRange(start6,10,40);
	InorderIterative(start6);
	cout<<"\n Iterative preorder\n";
	InorderIterative(start5);
	cout<<endl;
	IterativePreorder(start5);
	cout<<endl;
	PostOrderTraversalIterative2stacks(start5);
}
