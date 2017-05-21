//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
#include<shiviheaders.h>
using namespace std;
int arr[100000];
int N;
int BinarySearch(int num)
{
	int lo=0,hi=N-1;
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(arr[mid]>num)
		hi=mid-1;
		
		else if(arr[mid]<num)
		lo=mid+1;
		
		else
		return mid+1;
	}
	return -1;
}
int main()
{
		vector<int> vi;
		int x,sum;
		cin>>N;
		for(int i=0;i<N;++i)
		{
			cin>>x;
			arr[i]=x;
		}
		
	sort(arr,arr+N);	
	if(BinarySearch(12)!=-1)
	cout<<BinarySearch(12);
	
}
