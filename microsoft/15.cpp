//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[] = {12, 13, 15, 10, 35, 1};
	int smallest=INT_MAX,secondsmallest=INT_MAX,n=sizeof(arr)/sizeof(int);
	
	for(int i=0;i<n;++i)
	{
		if(arr[i]<smallest)
		{
			secondsmallest=smallest;
			smallest=arr[i];
		}
		
		else if(arr[i]<secondsmallest)
		secondsmallest=arr[i];
	}
	
	cout<<smallest<<" "<<secondsmallest<<endl;
	
}
