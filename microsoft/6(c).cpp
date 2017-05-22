//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int arr[100000];
int N;
int findpivot(int lo,int hi)
{
	int mid=(lo+hi)/2;
	if(lo>hi) return -1;
	
	if(mid<hi && arr[mid]>arr[mid+1])
	return mid;
	
	if(arr[mid]>arr[lo])
	return findpivot(mid+1,hi);
	
	else
	return findpivot(lo,mid-1);
}

int BinarySearch(int lo,int hi,int num)
{
	while(lo<=hi)
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
		
	int p=findpivot(0,N-1);
	
	if(BinarySearch(0,p,12)!=-1)
	cout<<BinarySearch(0,p,12);
	
	if(BinarySearch(p+1,N-1,12)!=-1)
	cout<<BinarySearch(p+1,N-1,12);
}
