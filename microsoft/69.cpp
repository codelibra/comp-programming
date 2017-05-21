//shivi..coding is adictive!!
//maximum sub array sum using divide and conquer approach
#include<shiviheaders.h>
using namespace std;
int arr[10000];
int maxcrossingsum(int lo,int mid,int hi)
{
	int leftsum=INT_MIN,rightsum=INT_MIN,sum=0;
	
	for(int i=mid;i>=lo;--i)
	{
		sum+=arr[i];
		if(leftsum<sum)
		leftsum=sum;
	}
	
	sum=0;
	for(int i=mid+1;i<=hi;++i)
	{
		sum+=arr[i];
		if(rightsum<sum)
		rightsum=sum;
	}
	
	return leftsum+rightsum;
}

int MaxSubarraySum(int lo,int hi)
{
	if(lo==hi)
	return arr[lo];
	
	int mid=(lo+hi)/2;
	
	return max(MaxSubarraySum(lo,mid),max(MaxSubarraySum(mid+1,hi),maxcrossingsum(lo,mid,hi)));
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	cout<<MaxSubarraySum(0,N-1);
}
