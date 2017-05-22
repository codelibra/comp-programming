//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[]={0, 1, 0, 1, 0, 0, 1, 1, 1, 0},n=sizeof(arr)/sizeof(int),j=n-1;
	
	for(int i=0;i<n;++i)
	{
	if(i>=j)	break;
		if(arr[i]==1)
		{
		while(arr[j]!=0)--j;	
		swap(arr[i],arr[j]);
		}
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	cout<<" "<<j;
	cout<<endl;
	}
	
	
}
