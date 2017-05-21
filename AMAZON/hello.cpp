#include<shiviheaders.h>
using namespace std;
struct  Node
{
	/* data */
	int data;
	Node* next;
};
int arr[]={10,20,30};
int main()
{
	Node *head=NULL;
	cout<<"hello";
	for (int i = 0; i < 3; ++i)
	{
		/* code */
		cout<<arr[i]<<" ";
	}
	getch();
}
