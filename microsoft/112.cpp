//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

void push(Node **start,int k)
{
	Node  *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=k;
	temp->next=*start;
	*start=temp;
}

void  print(Node *start)
{
	while(start)
	{
		cout<<start->data<<" ";
		start=start->next;
	}
	cout<<endl;
}
Node *head;
Node* Merge(Node *start,Node *start2)
{
	Node *ans=NULL;
	
	if(start==NULL)
	return start2;
	
	else if(start2==NULL)
	return start;
	
	else if(start->data>=start2->data)
	{
		ans=start;
		ans->next=Merge(start->next,start2);
	}
	else
	{
		ans=start2;
		ans->next=Merge(start,start2->next);
	}
	return ans;
	
}

struct Node* SortedMerge(struct Node* a, struct Node* b) 
{
  struct Node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data >= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

int main()
{
	Node *start=NULL,*start2=NULL,*start3=NULL;
	push(&start,10);push(&start,20);push(&start,30);push(&start,40);
	push(&start2,15);push(&start2,25);push(&start2,35);push(&start2,45);
	print(start);
	print(start2);
	start3=Merge(start,start2);
//	start3=SortedMerge(start,start2);
	//print(start3);
	//print(start);
	print(start3);
}
