//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,mid;
	int arr[100];
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int lo=0,hi=N;
	
	while(lo<hi)
	{
		mid=(lo+hi)/2;
		
		if(arr[mid]>mid)
		hi=mid;
		
		else if(arr[mid]==mid)
		lo=mid+1;
		
	}
	
	cout<<mid+1;
}
