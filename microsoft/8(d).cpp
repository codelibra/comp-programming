//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[]={0,1,0,3,2,3,2,1,0,2,0,1,3,2,1,3,2,1,2,0},n=sizeof(arr)/sizeof(int),j=n-1;
	
	int middle1=1,middle2=2,left=0,right=n-1,i=0;
	
	while(i<right)
	{
		if(arr[i]<middle1 && arr[i]<middle2)
		{
			swap(arr[i],arr[left]);
			++i;
			++left;
		}
		
		else if(arr[i]>middle1 && arr[i]>middle2)
		{
			swap(arr[i],arr[right]);
			--right;
		}
		
		else ++i;
	}
	left=0,right=n-1;
	while(arr[left]==middle1 || arr[left]==middle2) ++left;
	while(arr[right]==middle1 || arr[right]==middle2) --right;
	
	while(left<right)
	{
		while(arr[left]!=2) ++left;
		while(arr[right]!=1) --right;
		
		if(left<right)
		swap(arr[left],arr[right]);
	}
	
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	
}
