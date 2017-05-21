//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
#include<shiviheaders.h>
using namespace std;
int arr[] = {1, 2, 3, 4, 5, 6, 7};

void reverse(int start,int end)
{
	int temp=arr[start];
	while(start<end)
	{
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		
		++start;
		--end;
	}
}
int main()
{
	int n=sizeof(arr)/sizeof(int),d;
	cin>>d;
	
	reverse(0,n-1);
	reverse(0,d);
	reverse(d+1,n-1);
	
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	
}
