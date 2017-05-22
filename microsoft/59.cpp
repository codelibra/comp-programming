//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
		cin>>arr[i];
	
	int lo=0,hi=N-1;
	
	while(lo<=hi)
	{
		
		if (lo==hi) {cout<<arr[lo];break;}
		
		if ((hi == lo + 1) && arr[lo] < arr[hi])
 	     {cout<< arr[hi];break;}
 	     
 	     if ((hi == lo + 1) && arr[lo] > arr[hi])
 	     {cout<<arr[lo];break;}
 	     
		int mid=(lo+hi)/2;
		
		if(arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid])
		{cout<<arr[mid];break;}
		
		else if(arr[mid+1]>arr[mid] && arr[mid-1]<arr[mid])
		lo=mid+1;
		
		else if(arr[mid+1]<arr[mid] && arr[mid-1]>arr[mid])
		hi=mid-1;
		
		
	}
		
}
