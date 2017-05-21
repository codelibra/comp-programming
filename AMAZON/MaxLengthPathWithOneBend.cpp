// iHaala Madrid - A Gunner
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

struct node{
	int height;
	int max_left;
	int max_right;
	int leftbendingright;
	int rightbendingleft;
};

struct tree{
	int x;
	tree *left;
	tree *right;
};

node LongestPathWithOneBendHelper(tree*q,int h,int *ans){
	node nd;
	nd.height=-1;
	nd.max_left=0;
	nd.max_right=0;
	nd.rightbendingleft=0;
	nd.leftbendingright=0;
	
	if(q==NULL)	return nd;
	
	node l = LongestPathWithOneBendHelper(q->left ,h+1,ans);
	node r = LongestPathWithOneBendHelper(q->right,h+1,ans);
	
	nd.height = h;
	nd.max_left = max(l.max_left,h);
	nd.max_right= max(r.max_right,h);
	
	int maxLengthWithCurrentNodeBent=1;
	
	int maxLengthWithRightChildBendingLeft=1;
	if(r.height!=-1){			
		maxLengthWithRightChildBendingLeft = 1 + (r.max_left - r.height + 1 );
		maxLengthWithCurrentNodeBent+=(r.max_right - r.height + 1 );
		nd.rightbendingleft= 1 + r.rightbendingleft;
		nd.rightbendingleft= max( nd.rightbendingleft, r.max_right - r.height + 1) ;
	}	
	nd.rightbendingleft= max( maxLengthWithRightChildBendingLeft , nd.rightbendingleft);
	
	int maxLengthWithLeftChildBendingRight=1;
	if(l.height!=-1){			
		maxLengthWithLeftChildBendingRight = 1 +  (l.max_right  - l.height + 1 );
		maxLengthWithCurrentNodeBent+=(l.max_left - l.height + 1 );
		nd.leftbendingright= 1 + l.leftbendingright;
		nd.leftbendingright= max( nd.leftbendingright , l.max_left - l.height + 1);
	}
	nd.leftbendingright= max( maxLengthWithLeftChildBendingRight , nd.leftbendingright);
	
	*ans = max(*ans , maxLengthWithCurrentNodeBent);
	
	if(l.height!=-1)	*ans=max(*ans ,nd.leftbendingright);
	if(r.height!=-1)	*ans=max(*ans ,nd.rightbendingleft);
	
//	cout<<q->x<<" "<<nd.height<<" "<<nd.max_left<<" "<<nd.max_right<<" "<<nd.leftbendingright<<" "<<nd.rightbendingleft<<endl;
	
	return nd;
}

int LongestPathWithOneBend(tree *head){
	int ans=0;
	LongestPathWithOneBendHelper(head,1,&ans);
	return ans;
}
int cnt=1;
tree* newnode(){
	tree* nd = new tree;
	nd->x = cnt++;
	nd->left = nd->right = NULL;
	return nd;
}

int main(){
	tree *head = newnode();
	
	
	head->left = newnode();
	head->right = newnode();
	head->left->left = newnode();
	head->left->right = newnode();
	head->right->left = newnode();
	head->right->right = newnode();
//	head->left->left->left = newnode();
	head->left->left->right = newnode();
	head->left->left->right->right = newnode();
	head->left->left->right->right->right = newnode();
	head->left->left->right->right->left = newnode();
	head->left->left->right->right->left->left = newnode();
	head->left->left->right->right->left->left->left = newnode();
	head->left->left->right->right->left->left->left->left = newnode();
	head->left->left->right->right->right->right = newnode();
	head->left->left->right->right->right->right->right = newnode();
	head->left->left->right->right->right->right->right->right = newnode();
	head->left->left->right->right->right->right->right->right->right = newnode();
	
	
	cout<<LongestPathWithOneBend(head);
	return 0;	
}