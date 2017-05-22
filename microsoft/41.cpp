//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int arr[100],lo,hi,N;

int Floor(int k)
{
	int lo=0,hi=N;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		
		if(arr[mid]<k && arr[mid+1]>k)
		return arr[mid];
		
		if(arr[mid]==k)
		return k;
		
		else if(arr[mid]>k)
		hi=mid-1;
		
		else if(arr[mid]<k)
		lo=mid+1;
	}
	return arr[lo];
}
int Ceil(int k)
{
	int lo=0,hi=N;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		
		if(arr[mid]>k && arr[mid-1]<k)
		return arr[mid];
		
		if(arr[mid]==k)
		return k;
		
		else if(arr[mid]>k)
		hi=mid-1;
		
		else if(arr[mid]<k)
		lo=mid+1;
	}
	return arr[hi];
}
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	cout<<Floor(3)<<" "<<Ceil(3);
}
