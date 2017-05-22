//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[]={0,1,0,2,2,1,0,2,0,1,2,1,2,1,2,0},n=sizeof(arr)/sizeof(int),j=n-1;
	
	int middle=1,left=0,right=n-1,i=0;
	
	while(i<right)
	{
		if(arr[i]<middle)
		{
			swap(arr[i],arr[left]);
			++i;
			++left;
		}
		else if(arr[i]>middle)
		{
			swap(arr[i],arr[right]);
			--right;
		}
		else ++i;
	}
	
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	
}
