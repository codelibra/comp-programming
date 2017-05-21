//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[]={0, 1, 0, 1, 0, 0, 1, 1, 1, 0},n=sizeof(arr)/sizeof(int),j=n-1;
	
	int left=0,right=n;
	while(left<right)
	{
		while(arr[left]!=1)
		++left;
		
		while(arr[right]!=0)
		--right;
		
		if(left<right)
		swap(arr[left],arr[right]);
	}
	
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	
}
